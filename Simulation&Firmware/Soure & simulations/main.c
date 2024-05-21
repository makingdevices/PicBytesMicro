/*	Making Devices 2024
	https://makingdevices.com
	Rubén García Segovia
	  Pic Bytes Micro
*/
// CONFIG1H
#pragma config FOSC = HSPLL_HS // Oscillator Selection bits (HS oscillator, PLL enabled (HSPLL))
#pragma config FCMEN = OFF // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)
#pragma config LVP = OFF //Disable low voltage programmer so we can use RB5.

//Declarations of big chunks of data


int arkanoid_game_speed = 800;
int snake_game_speed = 250;
int tetris_game_speed = 200;
char buzzer_enable = 1; //1 = enabled // 0 = disabled
char splash_enabled = 0; //1 = enabled // 0 = disabled
char voltage_detector = 1; //1 = enabled // 0 = disabled (for old HW)
char game=0;
unsigned int sleep_time = 23000; //Time before deep sleep
unsigned int deep_sleep = 0;
char sleep_counter_multiplier = 0;

#include "graphics.h"
#include "tetris_data.h"

#include <p18f4550.h>
#include <delays.h>
#include "EEPROM.h"
#include "core.h"
#include "snake.h"
#include "arkanoid_lvl.h"
#include "arkanoid.h"
#include "tetris.h"

/*
Screen: 10x16
*/

void _low_isr (void);
void _high_isr (void);

#pragma code low_vector=0x18 //Low interrupt priority starts at 0x18
void low_interrupt(void)
{
_asm goto _low_isr _endasm
}

#pragma code high_vector=0x08 //High interrupt priority starts at 0x08
void high_interrupt(void)
{
_asm goto _high_isr _endasm
}
#pragma code


#pragma interrupt _low_isr
char state = 0;

void _low_isr (void)
{
//PIR1bits.TMR1IF
//INTCONbits.TMR0IF
if(PIR1bits.TMR1IF) //Timer0 interrupt
{
	if(++sleep_counter_multiplier>2){
		deep_sleep++;
		sleep_counter_multiplier = 0;
	}
	if(buttonmap!=0)deep_sleep=0;
	if(buzer_beep_timer>0 && buzzer_enable==1){
		buzer_beep_timer -= 2;
		LATCbits.LATC2 = 1;
	} else {
		LATCbits.LATC2 = 0;
	}
	if(ingame==1) clean_buttons();
	update_buttons();
	print_screen();
	if(game_selection==0)check_movement();
	if(game_selection==2)check_movement_arkanoid();
	if(game_selection==1)check_movement_tetris();
    TMR1H = 0xE8;
    TMR1L = 0x90;
	PIR1bits.TMR1IF = 0; // reset overflow bit
}
/*
 OSCCONbits.IDLEN = 1; //Set idle mode.;
 OSCCONbits.SCS0 = 0; //Set idle mode.;
 OSCCONbits.SCS1 = 0; //Set idle mode.;*/
}

#pragma interrupt _high_isr
void _high_isr (void)
{
if(INTCONbits.INT0IF) //Reset 
{
	INTCONbits.INT0IF = 0;
}
}


/* ****************** MAIN ****************** */
float bat_voltage;
int ADC_digit;
void main(void)
{	
	if(voltage_detector ==1){
		ADC_Init();
		ADC_digit=ADC_Read();
		bat_voltage= ADC_digit*((float)5.0/(float)1023);
	} else bat_voltage = 4;
	if(readEE(202) == 0xFF) initiate_EEPROM();
	splash_enabled = readEE(202);
	Delay10KTCYx(5);
	buzzer_enable = readEE(203);
	Delay10KTCYx(5);
	splash_init();
	if(bat_voltage<3.25) low_batt_alert();
	menu();
	clean_screen();
	if(game_selection==0) snake_sel_init();
	if(game_selection==2) arkanoid_sel_init();
	if(game_selection==1) tetris_sel_init();
	while(game_selection==0){
		delay_timer1(snake_game_speed);
		food_snake();
		move_snake();
	}
	while(game_selection==2){
		delay_timer1(arkanoid_game_speed);
		move_ball();
		//Wait until the game is done
	}
	while(game_selection==1){
		delay_timer1(tetris_game_speed);
		move_tetrominoe();
	}
	Sleep();
}




