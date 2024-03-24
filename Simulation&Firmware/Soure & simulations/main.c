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


char arkanoid_game_speed = 40;
char snake_game_speed = 30;
char tetris_game_speed = 20;
char buzzer_enable = 1; //1 = enabled // 0 = disabled
char splash_enabled = 0; //1 = enabled // 0 = disabled
char voltage_detector = 1; //1 = enabled // 0 = disabled (for old HW)

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
char game=0;
void _low_isr (void)
{
if(INTCONbits.TMR0IF) //Timer0 interrupt
{
	if(buzer_beep_timer>0){
		buzer_beep_timer -= 1;
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
	TMR0H = 0xFE;
	TMR0L = 0xF0;
	INTCONbits.TMR0IF = 0; // reset overflow bit
}
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
		Delay10KTCYx(snake_game_speed);
		food_snake();
		move_snake();
	}
	while(game_selection==2){
		Delay10KTCYx(arkanoid_game_speed);
		move_ball();
		//Wait until the game is done
	}
	while(game_selection==1){
		Delay10KTCYx(tetris_game_speed);
		move_tetrominoe();
	}
}




