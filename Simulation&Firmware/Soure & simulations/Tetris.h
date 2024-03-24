/*	Making Devices 2024
	https://makingdevices.com
	Rubén García Segovia
	  Pic Bytes Micro
*/
#ifndef __tetris_game
#define __tetris_game

// ----------------- TETRIS GAME ----------------------- //

char tetris_block_ram[5] = { 
	 0b00000000,
     0b00000000,
	 0b00000000,
	 0b00000000,
	 0b00000000,
};
unsigned char max_points_lvl=0;
void tetris_init(void){
	srand((unsigned) TMR0L);  //Pseudo-random seed for random generator
	game_ram[0] = (rand() % 7); //Block index
	game_ram[1] = 0; //Block rotation
	game_ram[2] = 5; //X axis for the block
	game_ram[3] = 0; //Y axis for the block
	game_ram[4] = 5; //speed for the blocks (10 equals a movement)
	game_ram[5] = 0; //time counter
	game_ram[6] = 0; //moving
	max_points_lvl=0; // points for the ongoing game
	game_ram[60] = 1; //Game is initiated.
	game_ram[65] = 0; //65 to 69 avoid double pulsations.
	game_ram[66] = 0; //66 to 69 avoid double pulsations.
	game_ram[67] = 0;
	game_ram[68] = 0;
	game_ram[69] = 0;
	tetris_game_speed = 20;
}



//****** Check Tetris Collision function *******
// * Function to read the collision *
// Returns: 
// 1 for bottom collision. Piece stop

char check_tetris_collision(void){ 
	char x = game_ram[2];
	char y = game_ram[3];
	char i = 0;
	for (i=0; i<5; i++)		//Check collision when moving a piece
	{
    	if(((tetris_pieces[game_ram[0]][game_ram[1]][0]>>(7-i))&1)==1)if(read_screen(x+i,y)==1 || y > 16 || x+i > 10 || x+i <1)return 1;
		if(((tetris_pieces[game_ram[0]][game_ram[1]][1]>>(7-i))&1)==1)if(read_screen(x+i,y+1)==1 || y+1 > 16 || x+i > 10 || x+i <1) return 1;
		if(((tetris_pieces[game_ram[0]][game_ram[1]][2]>>(7-i))&1)==1)if(read_screen(x+i,y+2)==1 || y+2 > 16 || x+i > 10 || x+i <1) return 1;
		if(((tetris_pieces[game_ram[0]][game_ram[1]][3]>>(7-i))&1)==1)if(read_screen(x+i,y+3)==1 || y+3 > 16 || x+i > 10 || x+i <1) return 1;
		if(((tetris_pieces[game_ram[0]][game_ram[1]][4]>>(7-i))&1)==1)if(read_screen(x+i,y+4)==1 || y+4 > 16 || x+i > 10 || x+i <1) return 1;
	}
	return 0;
}

void end_tetris_game(void){
	clean_screen();
	buzzer_beep(500);
	game_selection= 9;
	ingame = 0;
	game_ram[60] = 0; //Game is initiated.
	if(max_points_lvl>readEE(199))writeEE(199,max_points_lvl);	//Tetris max points
}

//****** Check Tetris line *******
// * Function to read the complete line *
// Returns: 
// X number of lines
char check_tetris_line(void){
	char i=1,j=16,j_2, counter=0,point=0;
	for(j=16 ;j>0;j--){
		for(i=1;i<11;i++){
			counter += read_screen(i,j);
		}
		if(counter==10){
			point++;
			for(j_2=j; j_2>1;j_2--){
				for(i=1;i<11;i++){
					write_screen(i,j_2,read_screen(i,j_2-1));
				}	
			}
			j = 16;
		}
		counter = 0;
	}
	if(point>0){
		buzzer_beep(150);
		if(tetris_game_speed>8)tetris_game_speed--;
	}
	return point;
} 


//*********** New tetrominoe ************
// * Function to create new tetrominoes *
void new_tetrominoe(void) {
	game_ram[0] = (rand() % 7); //Block index
	game_ram[1] = 0; //Block rotation
	game_ram[2] = 5; //X axis for the block
	game_ram[3] = 1; //Y axis for the block
	if(check_tetris_collision()==1) end_tetris_game();
}

void move_tetrominoe(void){
	if(((++game_ram[5]>=game_ram[4])) ||(read_button(2)==1)){
		game_ram[6] = 1;
		remove_sprite(game_ram[2],game_ram[3],tetris_pieces[game_ram[0]][game_ram[1]]);
		game_ram[3]++;
		if(check_tetris_collision()==1){
			print_sprite(game_ram[2],game_ram[3]-1,tetris_pieces[game_ram[0]][game_ram[1]]);
			new_tetrominoe();
			game_ram[8]=1;
			while(game_ram[8]!=0){
				game_ram[8] = check_tetris_line();
				max_points_lvl += game_ram[8];
			}
		}else print_sprite(game_ram[2],game_ram[3],tetris_pieces[game_ram[0]][game_ram[1]]); 
		game_ram[5] = 0;
		game_ram[6] = 0;
	} 
}

void check_movement_tetris(void){
	if(read_button(4)==1 && game_ram[6] == 0 && game_ram[68] == 0 && game_ram[69] == 0 && game_ram[67] == 0 && game_ram[66] == 0){ //right
		remove_sprite(game_ram[2],game_ram[3],tetris_pieces[game_ram[0]][game_ram[1]]);
		game_ram[69] = 1;
		game_ram[2]++; //X axis for the block
		if(check_tetris_collision()==1) game_ram[2]--;
		print_sprite(game_ram[2],game_ram[3],tetris_pieces[game_ram[0]][game_ram[1]]);
	} else if(read_button(4)==0) game_ram[69] = 0;

	if(read_button(3)==1 && game_ram[6] == 0 && game_ram[68] == 0 && game_ram[69] == 0 && game_ram[67] == 0 && game_ram[66] == 0){ //left
		remove_sprite(game_ram[2],game_ram[3],tetris_pieces[game_ram[0]][game_ram[1]]);
		game_ram[68] = 1;
		game_ram[2]--; //X axis for the block
		if(check_tetris_collision()==1) game_ram[2]++;
		print_sprite(game_ram[2],game_ram[3],tetris_pieces[game_ram[0]][game_ram[1]]);
	} else if(read_button(3)==0) game_ram[68] = 0;

	if(read_button(6)==1 && game_ram[6] == 0 && game_ram[68] == 0 && game_ram[69] == 0 && game_ram[67] == 0 && game_ram[66] == 0){ //A
		game_ram[1]++;
		game_ram[67] = 1;
		if(game_ram[1]==4){	
			game_ram[1]=0;
			remove_sprite(game_ram[2],game_ram[3],tetris_pieces[game_ram[0]][3]);
		}else remove_sprite(game_ram[2],game_ram[3],tetris_pieces[game_ram[0]][game_ram[1]-1]);
		if(check_tetris_collision()==1){
			game_ram[1]--;
			if(game_ram[1]==-1)game_ram[1]=3;
		}
		print_sprite(game_ram[2],game_ram[3],tetris_pieces[game_ram[0]][game_ram[1]]);
	} else if(read_button(6)==0) game_ram[67] = 0;
	
	if(read_button(5)==1 && game_ram[6] == 0 && game_ram[68] == 0 && game_ram[69] == 0 && game_ram[67] == 0 && game_ram[66] == 0){ //B
		game_ram[1]--;
		game_ram[66] = 1;
		if(game_ram[1]==-1){
			game_ram[1]=3;
			remove_sprite(game_ram[2],game_ram[3],tetris_pieces[game_ram[0]][0]);
		} else remove_sprite(game_ram[2],game_ram[3],tetris_pieces[game_ram[0]][game_ram[1]+1]);
		if(check_tetris_collision()==1){
			game_ram[1]++;
			if(game_ram[1]==4)game_ram[1]=0;
		}
		print_sprite(game_ram[2],game_ram[3],tetris_pieces[game_ram[0]][game_ram[1]]);
	} else if(read_button(5)==0) game_ram[66] = 0;
}

void tetris_sel_init(void){
	unsigned char max_points=0;
	unsigned char nr1=0,nr2=0,nr3=0;
	max_points = readEE(199); //max points
	if(max_points == 0) {
		tetris_init();
		return;
	} else {
		while(1){
			wait_buttons();
			print_sprite(1,1,letter_P_small);
			print_sprite(3,1,letter_T);
			print_sprite(8,1,letter_S_small);
			
			nr1 = max_points/100;
			nr1 = nr1 % 10;
			nr2 = max_points/10;
			nr2 = nr2 % 10;
			nr3 = max_points;
			nr3 = nr3 % 10;
			print_sprite(1,6,letter_number[nr1]);
			print_sprite(1,12,letter_number[nr2]);
			print_sprite(6,12,letter_number[nr3]);
			if(read_button(6)==1){ //Enter button is pressed
				clean_screen();
				tetris_init();
				wait_buttons();
				break;
			}
			if(read_button(5)==1){ //back button is pressed
				end_tetris_game();
				wait_buttons();
				break;
			}
		}
	}
}

#endif