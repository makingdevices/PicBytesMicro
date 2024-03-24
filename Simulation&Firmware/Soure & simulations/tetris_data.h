/*	Making Devices 2024
	https://makingdevices.com
	Rub�n Garc�a Segovia
	Pic Bytes Micro
	v1.25
*/
#ifndef __tetris_data
#define __tetris_data

char kicks_tetromino_general[5][5][2];

char kicks_tetromino_I[5][5][2];

#pragma idata my_memory_section_1
char tetris_pieces[7][4][5] = { 
	{{ //Line Block
	 0b00000000,
     0b11110000,
	 0b00000000,
	 0b00000000,
	 0b00000000,
	},
	{
	 0b01000000,
     0b01000000,
	 0b01000000,
	 0b01000000,
	 0b00000000,
	},
	{
	 0b00000000,
     0b11110000,
	 0b00000000,
	 0b00000000,
	 0b00000000,
	},
	{
	 0b01000000,
	 0b01000000,
     0b01000000,
	 0b01000000,
	 0b00000000,
	},
},
	{{ //Blue Block
	 0b10000000,
     0b11100000,
	 0b00000000,
	 0b00000000,
	 0b00000000,
	},
	{
	 0b01100000,
     0b01000000,
	 0b01000000,
	 0b00000000,
	 0b00000000,
	},
	{
	 0b00000000,
     0b11100000,
	 0b00100000,
	 0b00000000,
	 0b00000000,
	},
	{
	 0b01000000,
	 0b01000000,
     0b11000000,
	 0b00000000,
	 0b00000000,
	},
},
	{{ //Orange Block
	 0b00100000,
     0b11100000,
	 0b00000000,
	 0b00000000,
	 0b00000000,
	},
	{
	 0b01000000,
     0b01000000,
	 0b01100000,
	 0b00000000,
	 0b00000000,
	},
	{
	 0b00000000,
     0b11100000,
	 0b10000000,
	 0b00000000,
	 0b00000000,
	},
	{
	 0b11000000,
	 0b01000000,
     0b01000000,
	 0b00000000,
	 0b00000000,
	},
},
	{{	//Square block - yellow
	 0b01100000,
     0b01100000,
	 0b00000000,
	 0b00000000,
	 0b00000000,
	},
	{
	 0b01100000,
     0b01100000,
	 0b00000000,
	 0b00000000,
	 0b00000000,
	},
	{
	 0b01100000,
     0b01100000,
	 0b00000000,
	 0b00000000,
	 0b00000000,
	},
	{
	 0b00110000,
	 0b00110000,
     0b00000000,
	 0b00000000,
	 0b00000000,
	},
},
	{{ //Green Block
	 0b01100000,
     0b11000000,
	 0b00000000,
	 0b00000000,
	 0b00000000,
	},
	{
	 0b01000000,
     0b01100000,
	 0b00100000,
	 0b00000000,
	 0b00000000,
	},
	{
	 0b00000000,
     0b01100000,
	 0b11000000,
	 0b00000000,
	 0b00000000,
	},
	{
	 0b10000000,
	 0b11000000,
     0b01000000,
	 0b00000000,
	 0b00000000,
	},
},
	{{ //Purple Block
	 0b01000000,
     0b11100000,
	 0b00000000,
	 0b00000000,
	 0b00000000,
	},
	{
	 0b01000000,
     0b01100000,
	 0b01000000,
	 0b00000000,
	 0b00000000,
	},
	{
	 0b00000000,
     0b11100000,
	 0b01000000,
	 0b00000000,
	 0b00000000,
	},
	{
	 0b01000000,
	 0b11000000,
     0b01000000,
	 0b00000000,
	 0b00000000,
	},
},
	{{ //red Block
	 0b11000000,
     0b01100000,
	 0b00000000,
	 0b00000000,
	 0b00000000,
	},
	{
	 0b00100000,
     0b01100000,
	 0b01000000,
	 0b00000000,
	 0b00000000,
	},
	{
	 0b00000000,
     0b11000000,
	 0b01100000,
	 0b00000000,
	 0b00000000,
	},
	{
	 0b01000000,
	 0b11000000,
     0b10000000,
	 0b00000000,
	 0b00000000,
	},
},
};

#endif