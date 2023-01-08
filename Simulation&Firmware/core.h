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

char letter_M[5] = { 
	 0b10001000,
     0b11011000,
	 0b10101000,
	 0b10001000,
	 0b10001000,
};

char letter_A[5] = { 
	 0b01100000,
     0b10010000,
	 0b11110000,
	 0b10010000,
	 0b10010000,
};

char letter_K[5] = { 
	 0b10010000,
     0b10100000,
	 0b11000000,
	 0b10100000,
	 0b10010000,
};

char letter_I[5] = { 
	 0b01110000,
     0b00100000,
	 0b00100000,
	 0b00100000,
	 0b01110000,
};

char letter_N[5] = { 
	 0b10001000,
     0b11001000,
	 0b10101000,
	 0b10011000,
	 0b10001000,
};

char letter_G[5] = { 
	 0b11111000,
     0b10000000,
	 0b10111000,
	 0b10001000,
	 0b11111000,
};

char letter_D[5] = { 
	 0b11100000,
     0b10010000,
	 0b10010000,
     0b10010000,
	 0b11100000,
};

char letter_E[5] = { 
	 0b11110000,
     0b10000000,
	 0b11100000,
	 0b10000000,
	 0b11110000,
};

char letter_V[5] = { 
	 0b10001000,
     0b10001000,
	 0b01010000,
	 0b01010000,
	 0b00100000,
};

char letter_C[5] = { 
	 0b11110000,
     0b10000000,
	 0b10000000,
	 0b10000000,
	 0b11110000,
};

char letter_S[5] = { 
	 0b11110000,
     0b10000000,
	 0b11110000,
	 0b00010000,
	 0b11110000,
};
char letter_T[5] = { 
	 0b01110000,
     0b00100000,
	 0b00100000,
	 0b00100000,
	 0b00100000,
};
char letter_R[5] = { 
	 0b11100000,
     0b10100000,
	 0b11000000,
	 0b10100000,
	 0b10100000,
};
char letter_O[5] = { 
	 0b11110000,
     0b10010000,
	 0b10010000,
	 0b10010000,
	 0b11110000,
};
char letter_right[5] = { 
	 0b00000000,
     0b10000000,
	 0b11000000,
	 0b10000000,
	 0b00000000,
};
char letter_left[5] = { 
	 0b00000000,
     0b01000000,
	 0b11000000,
	 0b01000000,
	 0b00000000,
};

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

char buttonmap = 0b00000000;	//Player one

/*
0b12345678
1: Up arrow
2: Down arrow
3: Left arrow
4: Rigth arrow
5: Encoder botton
6: Encoder Rigth
7: Encoder Left
8:
*/

int ingame = 0;
int game_selection = 9;

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

void update_buttons(void){
	if(PORTAbits.RA0==0) write_button(1);
	if(PORTAbits.RA1==0) write_button(2);
	if(PORTAbits.RA2==0) write_button(3);
	if(PORTAbits.RA3==0) write_button(4);
	if(PORTCbits.RC0==0) write_button(5);

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
	PIE2bits.USBIE = 0;
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
	timer0_start();/*
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
} */
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
				Delay10KTCYx(30);

				if(read_button(5)==1){ //button
					while(1){
						clean_buttons();
						update_buttons();
						if(read_button(5)==0) break;
					}
					clean_screen();
					j = 1;
					option += 3;
					i = 22;
				}
				if(read_button(4)==1 || read_button(3)==1){ //button
					if(read_button(4)==1)option = 1;
					if(read_button(3)==1)option = 2;
					while(1){
						clean_buttons();
						update_buttons();
						if(read_button(4)==0 && read_button(3)==0) break;
					}
					clean_screen();
					i = 22;
					print_sprite(9,10,letter_right);
					print_sprite(1,10,letter_left);
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
					Delay10KTCYx(30);
					if(read_button(5)==1){ //button
						clean_screen();
						j = 1;
						option += 3;
						i = 0;
					}
					if(read_button(4)==1 || read_button(3)==1){ //button
						if(read_button(4)==1)option = 1;
						if(read_button(3)==1)option = 2;
						while(1){
							clean_buttons();
							update_buttons();
							if(read_button(4)==0 && read_button(3)==0) break;
						}
						clean_screen();
						i = 0;
						print_sprite(9,10,letter_right);
						print_sprite(1,10,letter_left);
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
				Delay10KTCYx(30);

				if(read_button(5)==1){ //button
					clean_screen();
					j = 1;
					option += 3;
					i = 23;
				}
				if(read_button(4)==1 || read_button(3)==1){ //button
					if(read_button(4)==1)option = 2;
					if(read_button(3)==1)option = 0;
					while(1){
						clean_buttons();
						update_buttons();
						if(read_button(4)==0 && read_button(3)==0) break;
					}
					clean_screen();
					i = 23;
					print_sprite(9,10,letter_right);
					print_sprite(1,10,letter_left);
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
					Delay10KTCYx(30);
					if(read_button(5)==1){ //button
						clean_screen();
						j = 1;
						option += 3;
						i = 0;
					}
					if(read_button(4)==1 || read_button(3)==1){ //button
						if(read_button(4)==1)option = 2;
						if(read_button(3)==1)option = 0;
						while(1){
							clean_buttons();
							update_buttons();
							if(read_button(4)==0 && read_button(3)==0) break;
						}
						clean_screen();
						i = 0;
						print_sprite(9,10,letter_right);
						print_sprite(1,10,letter_left);
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
				Delay10KTCYx(30);

				if(read_button(5)==1){ //button
					clean_screen();
					j = 1;
					option += 3;
					i = 40;
				}
				if(read_button(4)==1 || read_button(3)==1){ //button
					if(read_button(4)==1)option = 0;
					if(read_button(3)==1)option = 1;
					while(1){
						clean_buttons();
						update_buttons();
						if(read_button(4)==0 && read_button(3)==0) break;
					}
					clean_screen();
					i = 40;
					print_sprite(9,10,letter_right);
					print_sprite(1,10,letter_left);
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
					Delay10KTCYx(30);
					if(read_button(5)==1){ //button
						clean_screen();
						j = 1;
						option += 3;
						i = 0;
					}
					if(read_button(4)==1 || read_button(3)==1){ //button
						if(read_button(4)==1)option = 0;
						if(read_button(3)==1)option = 1;
						while(1){
							clean_buttons();
							update_buttons();
							if(read_button(4)==0 && read_button(3)==0) break;
						}						
						clean_screen();
						i = 0;
						print_sprite(9,10,letter_right);
						print_sprite(1,10,letter_left);
					}
				}
			}
		}
	}
	game_selection = option - 3;
	ingame = 1;
}
#endif