/*	Making Devices 2020
	https://makingdevices.com
	Rubén García Segovia
	Pic Bytes Micro
*/

#ifndef __Core
#define __Core

char screenmap_index = 0;

char screenmap[24] = { 
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
 };

#pragma idata my_memory_section_2
char game_ram[70]={ 
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,     
	 0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,     
	 0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,     
	 0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,     
	 0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,     
	 0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,     
	 0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,     
	 0b00000000,
     0b00000000,
     0b00000000,
     0b00000000,
     0b00000000
 };
#pragma idata my_memory_section_2

char buttonmap = 0b00000000;	//Player one

/*
0b12345678
1: Up arrow
2: Down arrow
3: Left arrow
4: Rigth arrow
5: S_b
6: S_a
7: 
8:
*/

int ingame = 0;			// We should start at 0
int game_selection = 9;    //We should start at 9
float buzer_beep_timer = 0;
int speed_menu = 40; //1 = without movement // 0 = with movement

void ADC_Init()
{    	
	TRISEbits.TRISE2 = 1;  /* Set RE2 as input port */
    //ADCON1 = 0x0E;	/* Ref vtg is VDD and Configure pin as analog pin */
    ADCON1 = 0b00000111; //Vss and Vdd as reference. AN7 ANALOG
	ADCON2 = 0x92;	/* Right Justified, 4Tad and Fosc/32. */
    ADRESH=0;		/* Flush ADC output Register */
    ADRESL=0;   
} 

int ADC_Read(void)
{
    int digital;

    /* Channel 7 is selected  */
    ADCON0bits.CHS = 7;
    ADCON0bits.ADON = 1;
    ADCON0bits.GO = 1;	/*Enable ADC and start conversion*/
	
    /* Wait for End of conversion i.e. Go/done'=0 conversion completed */
    while(ADCON0bits.GO==1);

    digital = (ADRESH*256) | (ADRESL);	/*Combine 8-bit LSB and 2-bit MSB*/
    return(digital);
}

void write_button(char buttonx){
	char new_value= 0b10000000;
	buttonx--;
	new_value = new_value >> buttonx;
	buttonmap = buttonmap|new_value;
}

char read_button(char buttonx){
	char answer = 0b00000000;
	answer = buttonmap >> (8-buttonx);
	answer = answer&0b00000001;
	return answer;
}

void clean_buttons(void){
	buttonmap=0;
}
char buzzer_beep(float time){
	if(buzzer_enable==1){
		buzer_beep_timer=time;
		return 0;
	}
	return 1;
}
void update_buttons(void){
	if(PORTAbits.RA0==0) write_button(1); // Up
	if(PORTAbits.RA1==0) write_button(2); // Down
	if(PORTAbits.RA2==0) write_button(3); // Left
	if(PORTAbits.RA3==0) write_button(4); // Right
	if(PORTAbits.RA4==0) write_button(5); // B
	if(PORTAbits.RA5==0) write_button(6); // A

}

void print_screen(void){
	char row_controlled;
	row_controlled = screenmap_index;
	LATE = 0b00000000;
	
	if(row_controlled>7){
		row_controlled-=8;
		LATC = ((screenmap[row_controlled+16]&0b00110000)<<2);
		
	} else {
		LATC = (screenmap[row_controlled+16]&0b11000000);
	}
	LATB = 0b00000001 << row_controlled;
	LATD = screenmap[screenmap_index];

	if(buzer_beep_timer>0){
		LATCbits.LATC2 = 1;
	}

	if(screenmap_index>7){
		LATE = 0b00000001;
	} else {
		LATE = 0b00000010;
	}
	screenmap_index++;
	if(screenmap_index==16)screenmap_index=0;
}

char read_screen(char x, char y){
	char answer = 0b00000000;
	char index = 0;
	x--;
	y--;
	if(x==8 || x == 9){
		if(y>=8 && y<16){
			y-=8;
			x+=2;
		}
		x -=8;
		index = 16;
	}
	x = 7 - x;
	answer = screenmap[y+index] >> x;
	answer = answer&0b00000001;
	return answer;
}


void write_screen(char x, char y, char value){
	if((x>0 && x<11)&&(y>0 && y<17)) {
		char new_value= 0b10000000;
		char index = 0;
		x--;
		y--;
	
		if(x==8 || x == 9){
			if(y>=8){
				new_value= 0b00100000;
				y-=8;
			}
			x -=8;
			index = 16;
		}
		value = value&0b00000001;
		new_value = new_value >> x;
		if(value==1){
			screenmap[y+index] = screenmap[y+index]|new_value;
		} else {
			screenmap[y+index] = screenmap[y+index]&~new_value;
		}
	}
}

void clean_screen(void){
char i, j;
	for(i=1;i<17;i++){
		for(j=1;j<11;j++){
			write_screen(j,i,0);
		}
	}
}

void print_sprite(char x, char y, char *sprite){
	char i = 0;
	for (i=0; i<5; i++)
	{
    	if(((sprite[0]>>(7-i))&1)==1)write_screen(x+i,y,(sprite[0]>>(7-i))&1);
		if(((sprite[1]>>(7-i))&1)==1)write_screen(x+i,y+1,(sprite[1]>>(7-i))&1);
		if(((sprite[2]>>(7-i))&1)==1)write_screen(x+i,y+2,(sprite[2]>>(7-i))&1);
		if(((sprite[3]>>(7-i))&1)==1)write_screen(x+i,y+3,(sprite[3]>>(7-i))&1);
		if(((sprite[4]>>(7-i))&1)==1)write_screen(x+i,y+4,(sprite[4]>>(7-i))&1);
	}
}

void remove_sprite(char x, char y, char *sprite){
	char i = 0;
	for (i=0; i<5; i++)
	{
    	if(((sprite[0]>>(7-i))&1)==1) write_screen(x+i,y,0);
		if(((sprite[1]>>(7-i))&1)==1) write_screen(x+i,y+1,0);
		if(((sprite[2]>>(7-i))&1)==1) write_screen(x+i,y+2,0);
		if(((sprite[3]>>(7-i))&1)==1) write_screen(x+i,y+3,0);
		if(((sprite[4]>>(7-i))&1)==1) write_screen(x+i,y+4,0);
	}
}

void timer0_start(void){
    T0CONbits.T08BIT = 0;   // 16-bit timer
    T0CONbits.T0CS = 0;     // increment on instruction cycle input
    T0CONbits.T0SE = 0;     // increment on low--> high transition of clock
    T0CONbits.PSA = 0;
//	PIE2bits.USBIE = 0;
	T0CONbits.T0PS2 = 0;
	T0CONbits.T0PS1 = 0;
	T0CONbits.T0PS0 = 0;
	TMR0H = 0xFE;
	TMR0L = 0x70;
    RCONbits.IPEN       = 1;    //Enable Interrupt Priorities
    INTCONbits.GIEL     = 1;    //Enable Low Priority Interrupt
    INTCONbits.GIEH     = 1;    // disable high priority interrupts        
    INTCONbits.TMR0IE   = 1;    //Enable Timer0 Interrupt
    INTCON2bits.TMR0IP  = 0;    //TMR0 set to low Priority Interrupt
    INTCONbits.TMR0IF = 0;  // T0 int flag bit cleared before starting
    T0CONbits.TMR0ON = 1;   // timer0 START
}

void splash_init(){
	char shift,j,g,i;
	ADCON1 = 0x0F;   
	TRISA = 0xFF;
	TRISB = 0;
	TRISC = 0b00000001;
	TRISD = 0;
	TRISE = 0;
	timer0_start();
	if(splash_enabled == 1){
		for(g=1;g<17;g++){
			for(j=1;j<11;j++){
				write_screen(j,g,1);
				Delay1KTCYx(30);
			}
		}
	
		for(g=1;g<17;g++){
			for(j=1;j<11;j++){
				write_screen(j,g,0);
				Delay1KTCYx(30);
			}
		}
		for(i=0;i<70;i++){
			remove_sprite(11-i,4,letter_M);
			print_sprite(10-i,4,letter_M);
			remove_sprite(16-i,4,letter_A);
			print_sprite(15-i,4,letter_A);
			remove_sprite(21-i,4,letter_K);
			print_sprite(20-i,4,letter_K);
			remove_sprite(26-i,4,letter_I);
			print_sprite(25-i,4,letter_I);
			remove_sprite(31-i,4,letter_N);
			print_sprite(30-i,4,letter_N);
			remove_sprite(36-i,4,letter_G);
			print_sprite(35-i,4,letter_G);
			remove_sprite(36-i,9,letter_D);
			print_sprite(35-i,9,letter_D);
			remove_sprite(41-i,9,letter_E);
			print_sprite(40-i,9,letter_E);
			remove_sprite(46-i,9,letter_V);
			print_sprite(45-i,9,letter_V);
			remove_sprite(51-i,9,letter_I);
			print_sprite(50-i,9,letter_I);
			remove_sprite(56-i,9,letter_C);
			print_sprite(55-i,9,letter_C);
			remove_sprite(61-i,9,letter_E);
			print_sprite(60-i,9,letter_E);
			remove_sprite(66-i,9,letter_S);
			print_sprite(65-i,9,letter_S);
			Delay10KTCYx(10);
		}
	}
}

void wait_buttons(void){
	while(1){
		clean_buttons();
		update_buttons();
		if(read_button(4)==0 && read_button(3)==0 && read_button(5)==0 && read_button(6)==0) break;
	}
}

void change_menu_screen(void){
	wait_buttons();
	clean_screen();
	print_sprite(9,10,letter_right);
	print_sprite(1,10,letter_left);
}

void menu(){
	char j = 0,i=0 ,option=0;
	print_sprite(9,10,letter_right);
	print_sprite(1,10,letter_left);
	while(j==0){
		while(option==0){
			for(i=4;i<21;i++){
				remove_sprite(6-i,4,letter_S);
				print_sprite(5-i,4,letter_S);
				remove_sprite(11-i,4,letter_N);
				print_sprite(10-i,4,letter_N);
				remove_sprite(17-i,4,letter_A);
				print_sprite(16-i,4,letter_A);
				remove_sprite(22-i,4,letter_K);
				print_sprite(21-i,4,letter_K);
				remove_sprite(27-i,4,letter_E);
				print_sprite(26-i,4,letter_E);
				Delay10KTCYx(speed_menu);

				if(read_button(6)==1){ //button
					buzzer_beep(500);
					clean_screen();
					j = 1;
					option = 10;
					break;
				}
				if(read_button(4)==1 || read_button(3)==1){ //button
					if(read_button(4)==1)option = 1;
					if(read_button(3)==1)option = 3;
					change_menu_screen();
					break;
				}
			}
			if(option==0){
				for(i=20;i>3;i--){
					remove_sprite(5-i,4,letter_S);
					remove_sprite(10-i,4,letter_N);
					print_sprite(6-i,4,letter_S);
					remove_sprite(16-i,4,letter_A);
					print_sprite(11-i,4,letter_N);
					remove_sprite(21-i,4,letter_K);
					print_sprite(17-i,4,letter_A);
					remove_sprite(26-i,4,letter_E);
					print_sprite(22-i,4,letter_K);
					print_sprite(27-i,4,letter_E);
					Delay10KTCYx(speed_menu);

					if(read_button(6)==1){ //button
						clean_screen();
						buzzer_beep(500);
						j = 1;
						option = 10;
						break;
					}
					if(read_button(4)==1 || read_button(3)==1){ //button
						if(read_button(4)==1)option = 1;
						if(read_button(3)==1)option = 3;
						change_menu_screen();
						break;
					}
				}
			}
		}
		while(option==1){
			for(i=4;i<22;i++){
				remove_sprite(6-i,4,letter_T);
				print_sprite(5-i,4,letter_T);
				remove_sprite(11-i,4,letter_E);
				print_sprite(10-i,4,letter_E);
				remove_sprite(15-i,4,letter_T);
				print_sprite(14-i,4,letter_T);
				remove_sprite(20-i,4,letter_R);
				print_sprite(19-i,4,letter_R);
				remove_sprite(23-i,4,letter_I);
				print_sprite(22-i,4,letter_I);
				remove_sprite(28-i,4,letter_S);
				print_sprite(27-i,4,letter_S);
				Delay10KTCYx(speed_menu);

				if(read_button(6)==1){ //button
					clean_screen();
					buzzer_beep(500);
					j = 1;
					option = 11;
					break;
				}
				if(read_button(4)==1 || read_button(3)==1){ //button
					if(read_button(4)==1)option = 2;
					if(read_button(3)==1)option = 0;
					wait_buttons();
					change_menu_screen();
					break;
				}
			}
			if(option==1){
				for(i=21;i>3;i--){
					remove_sprite(5-i,4,letter_T);
					remove_sprite(10-i,4,letter_E);
					print_sprite(6-i,4,letter_T);
					remove_sprite(14-i,4,letter_T);
					print_sprite(11-i,4,letter_E);
					remove_sprite(19-i,4,letter_R);
					print_sprite(15-i,4,letter_T);
					remove_sprite(22-i,4,letter_I);
					print_sprite(20-i,4,letter_R);
					print_sprite(23-i,4,letter_I);
					remove_sprite(27-i,4,letter_S);
					print_sprite(28-i,4,letter_S);
					Delay10KTCYx(speed_menu);
					if(read_button(6)==1){ //button
						clean_screen();
						buzzer_beep(500);
						j = 1;
						option = 11;
						break;
					}
					if(read_button(4)==1 || read_button(3)==1){ //button
						if(read_button(4)==1)option = 2;
						if(read_button(3)==1)option = 0;
						wait_buttons();
						change_menu_screen();
						break;
					}
				}
			}
		}
		while(option==2){	
			for(i=4;i<35;i++){
				remove_sprite(6-i,4,letter_A);
				print_sprite(5-i,4,letter_A);
				remove_sprite(11-i,4,letter_R);
				print_sprite(10-i,4,letter_R);
				remove_sprite(15-i,4,letter_K);
				print_sprite(14-i,4,letter_K);
				remove_sprite(20-i,4,letter_A);
				print_sprite(19-i,4,letter_A);
				remove_sprite(25-i,4,letter_N);
				print_sprite(24-i,4,letter_N);
				remove_sprite(31-i,4,letter_O);
				print_sprite(30-i,4,letter_O);
				remove_sprite(35-i,4,letter_I);
				print_sprite(34-i,4,letter_I);
				remove_sprite(40-i,4,letter_D);
				print_sprite(39-i,4,letter_D);
				Delay10KTCYx(speed_menu);

				if(read_button(6)==1){ //button
					clean_screen();
					buzzer_beep(500);
					j = 1;
					option = 12;
					break;
				}
				if(read_button(4)==1 || read_button(3)==1){ //button
					if(read_button(4)==1)option = 3;
					if(read_button(3)==1)option = 1;
					wait_buttons();
					change_menu_screen();
					break;
				}

			}
			if(option==2){
				for(i=34;i>3;i--){
					remove_sprite(5-i,4,letter_A);
					remove_sprite(10-i,4,letter_R);
					print_sprite(6-i,4,letter_A);
					remove_sprite(14-i,4,letter_K);
					print_sprite(11-i,4,letter_R);
					remove_sprite(19-i,4,letter_A);
					print_sprite(15-i,4,letter_K);
					remove_sprite(24-i,4,letter_N);
					print_sprite(20-i,4,letter_A);
					print_sprite(25-i,4,letter_N);	
					remove_sprite(30-i,4,letter_O);
					print_sprite(31-i,4,letter_O);
					remove_sprite(34-i,4,letter_I);
					print_sprite(35-i,4,letter_I);
					remove_sprite(39-i,4,letter_D);
					print_sprite(40-i,4,letter_D);
					Delay10KTCYx(speed_menu);
					if(read_button(6)==1){ //button
						clean_screen();
						buzzer_beep(500);
						j = 1;
						option = 12;
						break;
					}
					if(read_button(4)==1 || read_button(3)==1){ //button
						if(read_button(4)==1)option = 3;
						if(read_button(3)==1)option = 1;
						wait_buttons();						
						change_menu_screen();
						break;
					}
				}
			}
		}
		while(option==3){	
			for(i=4;i<35;i++){
				remove_sprite(6-i,4,letter_S);
				print_sprite(5-i,4,letter_S);
				remove_sprite(11-i,4,letter_E);
				print_sprite(10-i,4,letter_E);
				remove_sprite(15-i,4,letter_T);
				print_sprite(14-i,4,letter_T);
				remove_sprite(19-i,4,letter_T);
				print_sprite(18-i,4,letter_T);
				remove_sprite(23-i,4,letter_I);
				print_sprite(22-i,4,letter_I);
				remove_sprite(28-i,4,letter_N);
				print_sprite(27-i,4,letter_N);
				remove_sprite(34-i,4,letter_G);
				print_sprite(33-i,4,letter_G);
				remove_sprite(40-i,4,letter_S);
				print_sprite(39-i,4,letter_S);
				Delay10KTCYx(speed_menu);

				if(read_button(6)==1){ //button
					option = 4;
					wait_buttons();
					break;
				}
				if(read_button(4)==1 || read_button(3)==1){ //button
					if(read_button(4)==1)option = 0;
					if(read_button(3)==1)option = 2;
					wait_buttons();
					change_menu_screen();
					break;
				}

			}
			if(option==3){
				for(i=34;i>3;i--){
					remove_sprite(5-i,4,letter_S);
					remove_sprite(10-i,4,letter_E);
					print_sprite(6-i,4,letter_S);
					remove_sprite(14-i,4,letter_T);
					print_sprite(11-i,4,letter_E);
					remove_sprite(18-i,4,letter_T);
					print_sprite(15-i,4,letter_T);
					remove_sprite(22-i,4,letter_I);
					print_sprite(19-i,4,letter_T);
					print_sprite(23-i,4,letter_I);	
					remove_sprite(27-i,4,letter_N);
					print_sprite(28-i,4,letter_N);
					remove_sprite(33-i,4,letter_G);
					print_sprite(34-i,4,letter_G);
					remove_sprite(39-i,4,letter_S);
					print_sprite(40-i,4,letter_S);
					Delay10KTCYx(speed_menu);
					if(read_button(6)==1){ //button
						option = 4;
						wait_buttons();
						break;
					}
					if(read_button(4)==1 || read_button(3)==1){ //button
						if(read_button(4)==1)option = 0;
						if(read_button(3)==1)option = 2;
						wait_buttons();						
						change_menu_screen();
						break;
					}
				}
			}
		}while(option==4){
			if(readEE(203)==1){
				remove_sprite(4,10,letter_cross);
				print_sprite(4,10,letter_tick);
			} else {
				remove_sprite(4,10,letter_tick);
				print_sprite(4,10,letter_cross);
			}
			for(i=4;i<21;i++){
				remove_sprite(6-i,4,letter_S);
				print_sprite(5-i,4,letter_S);
				remove_sprite(11-i,4,letter_O);
				print_sprite(10-i,4,letter_O);
				remove_sprite(16-i,4,letter_U);
				print_sprite(15-i,4,letter_U);
				remove_sprite(21-i,4,letter_N);
				print_sprite(20-i,4,letter_N);
				remove_sprite(27-i,4,letter_D);
				print_sprite(26-i,4,letter_D);
				Delay10KTCYx(speed_menu);

				if(read_button(6)==1 || read_button(5)==1){ //button
					if(read_button(6)==1){
						change_sound();
						if(readEE(203)==1){
							remove_sprite(4,10,letter_cross);
							print_sprite(4,10,letter_tick);
						} else {
							remove_sprite(4,10,letter_tick);
							print_sprite(4,10,letter_cross);
						}
					}
					if(read_button(5)==1){
						option = 3;
						clean_screen();
						change_menu_screen();
						break;
					}
					wait_buttons();
				}
				if(read_button(4)==1 || read_button(3)==1){ //button
					if(read_button(4)==1)option = 5;
					if(read_button(3)==1)option = 6;
					wait_buttons();
					change_menu_screen();
					break;
				}

			}
			if(option==4){
				for(i=21;i>3;i--){
					remove_sprite(5-i,4,letter_S);
					remove_sprite(10-i,4,letter_O);
					print_sprite(6-i,4,letter_S);
					remove_sprite(15-i,4,letter_U);
					print_sprite(11-i,4,letter_O);
					remove_sprite(20-i,4,letter_N);
					print_sprite(16-i,4,letter_U);
					remove_sprite(26-i,4,letter_D);
					print_sprite(21-i,4,letter_N);
					print_sprite(27-i,4,letter_D);	
					Delay10KTCYx(speed_menu);
					if(read_button(6)==1 || read_button(5)==1){ //button
						if(read_button(6)==1){
							change_sound();
							if(readEE(203)==1){
								remove_sprite(4,10,letter_cross);
								print_sprite(4,10,letter_tick);
							} else {
								remove_sprite(4,10,letter_tick);
								print_sprite(4,10,letter_cross);
							}
						}
						if(read_button(5)==1){
							option = 3;
							change_menu_screen();
							break;
						}
						wait_buttons();
					}
					if(read_button(4)==1 || read_button(3)==1){ //button
						if(read_button(4)==1)option = 5;
						if(read_button(3)==1)option = 6;
						wait_buttons();						
						change_menu_screen();
						break;
					}
				}
			}
		} while(option==5){
			if(readEE(202)==1){
				remove_sprite(4,10,letter_cross);
				print_sprite(4,10,letter_tick);
			} else {
				remove_sprite(4,10,letter_tick);
				print_sprite(4,10,letter_cross);
			}
			for(i=4;i<25;i++){
				remove_sprite(6-i,4,letter_S);
				print_sprite(5-i,4,letter_S);
				remove_sprite(11-i,4,letter_P);
				print_sprite(10-i,4,letter_P);
				remove_sprite(16-i,4,letter_L);
				print_sprite(15-i,4,letter_L);
				remove_sprite(20-i,4,letter_A);
				print_sprite(19-i,4,letter_A);
				remove_sprite(25-i,4,letter_S);
				print_sprite(24-i,4,letter_S);
				remove_sprite(30-i,4,letter_H);
				print_sprite(29-i,4,letter_H);
				Delay10KTCYx(speed_menu);

				if(read_button(6)==1 || read_button(5)==1){ //button
					if(read_button(6)==1){
						change_splash();
						if(readEE(202)==1){
							remove_sprite(4,10,letter_cross);
							print_sprite(4,10,letter_tick);
						} else {
							remove_sprite(4,10,letter_tick);
							print_sprite(4,10,letter_cross);
						}
					}
					if(read_button(5)==1){
						option = 3;
						change_menu_screen();
						break;
					}
					wait_buttons();
				}
				if(read_button(4)==1 || read_button(3)==1){ //button
					if(read_button(4)==1)option = 6;
					if(read_button(3)==1)option = 4;
					wait_buttons();
					change_menu_screen();
					break;
				}

			}
			if(option==5){
				for(i=25;i>3;i--){
					remove_sprite(5-i,4,letter_S);
					remove_sprite(10-i,4,letter_P);
					print_sprite(6-i,4,letter_S);
					remove_sprite(15-i,4,letter_L);
					print_sprite(11-i,4,letter_P);
					remove_sprite(19-i,4,letter_A);
					print_sprite(16-i,4,letter_L);
					remove_sprite(24-i,4,letter_S);
					print_sprite(20-i,4,letter_A);
					print_sprite(25-i,4,letter_S);	
					remove_sprite(29-i,4,letter_H);
					print_sprite(30-i,4,letter_H);
					Delay10KTCYx(speed_menu);
					if(read_button(6)==1 || read_button(5)==1){ //button
						if(read_button(6)==1){
							change_splash();
							if(readEE(202)==1){
								remove_sprite(4,10,letter_cross);
								print_sprite(4,10,letter_tick);
							} else {
								remove_sprite(4,10,letter_tick);
								print_sprite(4,10,letter_cross);
							}
						}
						if(read_button(5)==1){
							option = 3;
							change_menu_screen();
							break;
						}
						wait_buttons();
					}
					if(read_button(4)==1 || read_button(3)==1){ //button
						if(read_button(4)==1)option = 6;
						if(read_button(3)==1)option = 4;
						wait_buttons();						
						change_menu_screen();
						break;
					}
				}
			}
		} while(option==6){
			for(i=4;i<28;i++){
				remove_sprite(7-i,4,letter_R);
				print_sprite(6-i,4,letter_R);
				remove_sprite(11-i,4,letter_E);
				print_sprite(10-i,4,letter_E);
				remove_sprite(16-i,4,letter_S);
				print_sprite(15-i,4,letter_S);
				remove_sprite(20-i,4,letter_T);
				print_sprite(19-i,4,letter_T);
				remove_sprite(25-i,4,letter_O);
				print_sprite(24-i,4,letter_O);
				remove_sprite(30-i,4,letter_R);
				print_sprite(29-i,4,letter_R);
				remove_sprite(34-i,4,letter_E);
				print_sprite(33-i,4,letter_E);
				Delay10KTCYx(speed_menu);

				if(read_button(6)==1 || read_button(5)==1){ //button
					if(read_button(6)==1){
						option = 7;
						clean_screen();
						i = 28;
					}
					if(read_button(5)==1){
						option = 3;
						change_menu_screen();
						break;
					}
					wait_buttons();
				}
				if(read_button(4)==1 || read_button(3)==1){ //button
					if(read_button(4)==1)option = 4;
					if(read_button(3)==1)option = 5;
					wait_buttons();
					change_menu_screen();
					break;
				}

			}
			if(option==6){
				for(i=28;i>3;i--){
					remove_sprite(6-i,4,letter_R);
					remove_sprite(10-i,4,letter_E);
					print_sprite(7-i,4,letter_R);
					remove_sprite(15-i,4,letter_S);
					print_sprite(11-i,4,letter_E);
					remove_sprite(19-i,4,letter_T);
					print_sprite(16-i,4,letter_S);
					remove_sprite(24-i,4,letter_O);
					print_sprite(20-i,4,letter_T);
					print_sprite(25-i,4,letter_O);	
					remove_sprite(29-i,4,letter_R);
					print_sprite(30-i,4,letter_R);
					remove_sprite(33-i,4,letter_E);
					print_sprite(34-i,4,letter_E);
					Delay10KTCYx(speed_menu);
					if(read_button(6)==1 || read_button(5)==1){ //button
						if(read_button(6)==1){
							option = 7;
							clean_screen();
							i = 0;
						}
						if(read_button(5)==1){
							option = 3;
							change_menu_screen();
							break;
						}
						wait_buttons();
					}
					if(read_button(4)==1 || read_button(3)==1){ //button
						if(read_button(4)==1)option = 4;
						if(read_button(3)==1)option = 5;
						wait_buttons();					
						change_menu_screen();
						break;
					}
				}
			}
		}while(option==7){
			for(i=4;i<20;i++){
				remove_sprite(6-i,4,letter_S);
				print_sprite(5-i,4,letter_S);
				remove_sprite(11-i,4,letter_U);
				print_sprite(10-i,4,letter_U);
				remove_sprite(16-i,4,letter_R);
				print_sprite(15-i,4,letter_R);
				remove_sprite(20-i,4,letter_E);
				print_sprite(19-i,4,letter_E);
				remove_sprite(25-i,4,letter_int);
				print_sprite(24-i,4,letter_int);
				Delay10KTCYx(speed_menu);

				if(read_button(6)==1 || read_button(5)==1){ //button
					if(read_button(6)==1){
						restore_EEPROM();
						option = 0;
						change_menu_screen();
						break;
					}	
					if(read_button(5)==1){
						option = 3;
						change_menu_screen();
						break;
					}
					wait_buttons();
				}
			}
			if(option==7){
				for(i=20;i>3;i--){
					remove_sprite(5-i,4,letter_S);
					remove_sprite(10-i,4,letter_U);
					print_sprite(6-i,4,letter_S);
					remove_sprite(15-i,4,letter_R);
					print_sprite(11-i,4,letter_U);
					remove_sprite(19-i,4,letter_E);
					print_sprite(16-i,4,letter_R);
					remove_sprite(24-i,4,letter_int);
					print_sprite(20-i,4,letter_E);
					print_sprite(25-i,4,letter_int);	
					Delay10KTCYx(speed_menu);
					if(read_button(6)==1 || read_button(5)==1){ //button
						if(read_button(6)==1){
							restore_EEPROM();
							option = 0;
							change_menu_screen();
							break;
						}
						if(read_button(5)==1){
							option = 3;
							change_menu_screen();
							break;
						}
						wait_buttons();
					}
				}
			}
		}
	}
	game_selection = option - 10;
	ingame = 1;
}

void low_batt_alert(void){
	buzzer_beep(500);
	while(1){
		print_sprite(2,1, letter_L);
		print_sprite(6,1, letter_O);
		print_sprite(4,7, letter_W);
		print_sprite(1,11, letter_B);
		print_sprite(5,11, letter_A_small);
		print_sprite(7,11, letter_T);

		if(read_button(5)==1 || read_button(6)==1){ //back button is pressed
			clean_screen();
			wait_buttons();
			break;
		}
	}
}
#endif