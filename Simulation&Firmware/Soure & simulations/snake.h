/*	Making Devices 2023
	https://makingdevices.com
	Rubén García Segovia
	  Pic Bytes Micro
*/
#ifndef __snake_game
#define __snake_game

// ----------------- SNAKE GAME ----------------------- //
int snake_length=0;
char unique_mov=0; //his guaranties only one movement per time
unsigned char max_points_snake=0;
void snake_init(void){
	int j;  
 	srand((unsigned) TMR0L);  //Pseudo-random seed for random generator
	snake_game_speed = 30;
	game_ram[0] = 0; //init movement of the snake
	game_ram[60]=7;	//head x axis
	game_ram[61]=3;	//head y axis
	game_ram[62]=4;	//tale x axis
	game_ram[63]=3; //tale y axis
	game_ram[64]=0; // tale pointer position
	game_ram[65]=0; // snake movement
	game_ram[66]=0; // tale pointer index
	game_ram[67]=0; // food state
	game_ram[68]=0; // food x axis
	game_ram[69]=0; // food y axis
	snake_length=4;	// length of the snake
	max_points_snake=0; //Points for the snake game
	for(j=4;j<8;j++){
		write_screen(j,3,1);
	}
}

void snake_end_game(void){
 	clean_screen();
	buzzer_beep(1000);
	game_selection= 9;
	ingame = 0;
	if(max_points_snake>readEE(201))writeEE(201,max_points_snake);	//snake max points
}

void food_snake(void){
	while(game_ram[67]==0){
		game_ram[68] = (rand() % 9) + 1;
		game_ram[69] = (rand() % 15) + 1;
		if(read_screen(game_ram[68],game_ram[69])==0)game_ram[67] = 1;
		if(game_ram[68] == 1 && game_ram[69]==1) game_ram[67] = 0;
		if(game_ram[68] == 10 && game_ram[69]==1) game_ram[67] = 0;
		if(game_ram[68] == 1 && game_ram[69]==16) game_ram[67] = 0;
		if(game_ram[68] == 10 && game_ram[69]==16) game_ram[67] = 0;
		if(game_ram[67] == 1) max_points_snake++;
	}
	write_screen(game_ram[68],game_ram[69],1);
}

char stack_snake(char movement, char value){
	if(value==0){
		int head_index_pointer, head_position_pointer;
		head_position_pointer = snake_length + game_ram[64] - 1;
		head_index_pointer = game_ram[66];
		if(head_position_pointer>3){
			head_index_pointer = game_ram[66] + head_position_pointer/4;
			head_position_pointer = head_position_pointer % 4;
		}

		if(head_index_pointer >59) head_index_pointer -=60;  //fix the bug.
		game_ram[head_index_pointer] = game_ram[head_index_pointer]&~(0b00000011<<(6-(2*head_position_pointer)));
		game_ram[head_index_pointer] = game_ram[head_index_pointer]|(movement<<(6-(2*head_position_pointer)));
		return 0;
	} else if(value==1){
		game_ram[64]++; 
		if(game_ram[64]==4){
			game_ram[64]=0;
			game_ram[66]++;
		}
		if(game_ram[66] == 60){
			game_ram[66] = 0;
		}
		return 0;
	} else if(value==2){
		return ((game_ram[game_ram[66]]<<(game_ram[64]*2))&0b11000000);
	}
}

void move_snake(void){
	if(game_ram[60] > 10 || game_ram[60] < 1)snake_end_game();
	if(game_ram[61] > 16 || game_ram[61] < 1)snake_end_game();
	if(game_ram[65]==0b00000000){ //rigth
		if(((game_ram[60]+1)==game_ram[68])&&game_ram[61]==game_ram[69]){
			game_ram[67]=0;	
			buzzer_beep(150);
			if(snake_game_speed>10) snake_game_speed--;
			game_ram[60]++;
			stack_snake(game_ram[65],0);
			snake_length++;
		}
		game_ram[60]++;
	}
	if(game_ram[65]==0b00000011){//down
		if((game_ram[60]==game_ram[68])&&(game_ram[61]+1)==game_ram[69]){
			game_ram[67]=0;
			buzzer_beep(150);
			if(snake_game_speed>10) snake_game_speed--;	
			game_ram[61]++;
			stack_snake(game_ram[65],0);
			snake_length++;
		}
		game_ram[61]++;
	}
	if(game_ram[65]==0b00000010){ //up
		if((game_ram[60]==game_ram[68])&&(game_ram[61]-1)==game_ram[69]){
			game_ram[67]=0;	
			buzzer_beep(150);
			if(snake_game_speed>10) snake_game_speed--;
			game_ram[61]--;
			stack_snake(game_ram[65],0);
			snake_length++;
		}
		game_ram[61]--;
	}
	if(game_ram[65]==0b00000001){ //left
		if(((game_ram[60]-1)==game_ram[68])&&game_ram[61]==game_ram[69]){
			game_ram[67]=0;	
			buzzer_beep(150);
			if(snake_game_speed>10) snake_game_speed--;
			game_ram[60]--;
			stack_snake(game_ram[65],0);
			snake_length++;
		}
		game_ram[60]--;
	}
	if(read_screen(game_ram[60],game_ram[61])==1)snake_end_game();
	else write_screen(game_ram[60],game_ram[61],1);
	write_screen(game_ram[62],game_ram[63],0);

	stack_snake(game_ram[65],0);

	if(stack_snake(game_ram[65],2)==0b00000000){
		game_ram[62]++;	
	}
	if(stack_snake(game_ram[65],2)==0b11000000){
		game_ram[63]++;	
	}
	if(stack_snake(game_ram[65],2)==0b01000000){
		game_ram[62]--;	
	}
	if(stack_snake(game_ram[65],2)==0b10000000){
		game_ram[63]--;	
	}
	unique_mov = 0;
	stack_snake(game_ram[65],1);
}



void check_movement(void){
	if(read_button(4)==1 && unique_mov == 0 && (game_ram[65]!=0b00000001)){ //rigth
		unique_mov = 1;
		game_ram[65] = 0b00000000;
	}
	if(read_button(3)==1 && unique_mov == 0 && (game_ram[65]!=0b00000000)){ //left
		unique_mov = 1;
		game_ram[65] = 0b00000001;
	}
	if(read_button(2)==1 && unique_mov == 0 && (game_ram[65]!=0b00000010)){ //down
		unique_mov = 1;
		game_ram[65] = 0b00000011;
	}
	if(read_button(1)==1 && unique_mov == 0 && (game_ram[65]!=0b00000011)){ //up
		unique_mov = 1;
		game_ram[65] = 0b00000010;
	}
}
void snake_sel_init(void){
	unsigned char max_points=0;
	unsigned char nr1=0,nr2=0,nr3=0;
	max_points = readEE(201); //max points
	if(max_points == 0) {
		snake_init();
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
				snake_init();
				wait_buttons();
				break;
			}
			if(read_button(5)==1){ //back button is pressed
				snake_end_game();
				wait_buttons();
				break;
			}
		}
	}
}


#endif