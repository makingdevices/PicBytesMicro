/*	Making Devices 2020
	https://makingdevices.com
	Rubén García Segovia
	Pic Bytes Micro
*/

#ifndef __Eproom
#define __Eproom
char readEE(char address) {

// Load address into address register
EEADR =address;

//Configuration as per manual
EECON1bits.EEPGD =0;
EECON1bits.CFGS =0;
EECON1bits.RD =1;


return EEDATA;
}

void writeEE(char address, char data)
{

EEADR =address;
EEDATA = data;

//Configuration as per manual
EECON1bits.EEPGD =0;
EECON1bits.CFGS =0;
EECON1bits.WREN =1; 
INTCONbits.GIE = 0;
EECON2 = 0x55;
EECON2 = 0xAA; 
EECON1bits.WR = 1;
INTCONbits.GIE = 1;
EECON1bits.WREN = 0;
}

void initiate_EEPROM(void){
	if(readEE(199) == 0xFF) writeEE(199,0);	//Tetris max points
	Delay10KTCYx(10);
	if(readEE(200) == 0xFF) writeEE(200,0);	//Arkanoid max level
	Delay10KTCYx(10);
	if(readEE(201) == 0xFF) writeEE(201,0);	//Snake max points
	Delay10KTCYx(10);
	if(readEE(202) == 0xFF) writeEE(202,1);	//Splash // 0 -> disabled. 1 Enabled
	Delay10KTCYx(10);
	if(readEE(203) == 0xFF) writeEE(203,1);	//Sound // 0 -> disabled. 1 Enabled
	Delay10KTCYx(10);
}

void change_sound(void){
	if(readEE(203) == 1) writeEE(203,0);	//Sound // 0 -> disabled. 1 Enabled
	else writeEE(203,1);
	Delay10KTCYx(5);
}

void change_splash(void){
	if(readEE(202) == 1) writeEE(202,0);	//Sound // 0 -> disabled. 1 Enabled
	else writeEE(202,1);
	Delay10KTCYx(5);
}


void restore_EEPROM(void){
	writeEE(199,0);	//Tetris max points
	Delay10KTCYx(5);
	writeEE(200,0);	//Arkanoid max level
	Delay10KTCYx(5);
	writeEE(201,0);	//Snake max points
	Delay10KTCYx(5);
	writeEE(202,1);	//Splash // 0 -> disabled. 1 Enabled
	Delay10KTCYx(5);
	writeEE(203,1);	//Sound // 0 -> disabled. 1 Enabled
	Delay10KTCYx(5);
	return 0;
}

#endif