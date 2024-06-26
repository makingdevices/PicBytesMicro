/*	Making Devices 2024
	https://makingdevices.com
	Rub�n Garc�a Segovia
	  Pic Bytes Micro
*/
#ifndef __arkanoid_game_lvl
#define __arkanoid_game_lvl

int lvlspeed[10] = 
	{
	400,
	350,
	300,
	300,
	300,
	250,
	250,
	220,
	230,
	200,
	};
rom char lvlbrick[10][41] = {//First: number of bricks, then X,Y of bricks
	{		//LEVEL 0
	5,						
	5,2,
	5,3,
	5,4,
	5,5,
	5,6,
	1,1,
	1,1,
	1,1,
	1,1,
	1,1,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	},
	{		//LEVEL 1	
	10,						
	3,2,
	3,3,
	3,4,
	3,5,
	3,6,
	7,2,
	7,3,
	7,4,
	7,5,
	7,6,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	},
	{		//LEVEL 2	
	10,						
	2,3,
	2,5,
	2,7,
	5,2,
	5,4,
	5,6,
	5,8,
	8,3,
	8,5,
	8,7,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	},
	{		//LEVEL 3	
	10,						
	2,1,
	2,4,
	2,7,
	4,4,
	5,1,
	5,7,
	6,4,
	8,1,
	8,4,
	8,7,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	},
	{		//LEVEL 4	
	10,						
	1,7,
	2,4,
	3,3,
	3,5,
	5,2,
	5,6,
	7,3,
	7,5,
	8,4,
	9,7,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	},
	{		//LEVEL 5	
	10,						
	1,1,
	1,5,
	3,3,
	3,7,
	5,1,
	5,5,
	7,3,
	7,7,
	9,1,
	9,5,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	},
	{		//LEVEL 6	
	10,						
	1,1,
	2,2,
	3,3,
	4,4,
	5,5,
	6,4,
	7,3,
	8,2,
	9,1,
	5,1,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	},
	{		//LEVEL 7	
	15,						
	1,2,
	1,3,
	1,4,
	1,5,
	1,6,
	3,3,
	3,4,
	3,5,
	3,6,
	5,4,
	5,5,
	5,6,
	7,5,
	7,6,
	9,6,
	0,0,
	0,0,
	0,0,
	0,0,
	0,0,
	},
	{		//LEVEL 8	
	20,						
	1,1,
	1,3,
	1,5,
	1,7,
	3,1,
	3,2,
	3,4,
	3,6,
	5,1,
	5,3,
	5,5,
	5,7,
	7,1,
	7,2,
	7,4,
	7,5,
	9,1,
	9,3,
	9,5,
	9,7,
	},
	{		//LEVEL 9	
	17,						
	1,1,
	1,4,
	1,7,
	3,3,
	3,4,
	3,5,
	5,2,
	5,3,
	5,4,
	5,5,
	5,6,
	7,3,
	7,4,
	7,5,
	9,1,
	9,4,
	9,7,
	0,0,
	0,0,
	0,0,
	},
};

#endif