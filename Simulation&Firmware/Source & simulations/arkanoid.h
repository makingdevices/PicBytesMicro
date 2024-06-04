/*	Making Devices 2024
	https://makingdevices.com
	Rubén García Segovia
	  Pic Bytes Micro
*/
#ifndef __arkanoid_game
#define __arkanoid_game

// ----------------- ARKANOID GAME ----------------------- //
char arkanoid_bar[5] = { 
	 0b11111000,
     0b00000000,
	 0b00000000,
	 0b00000000,
	 0b00000000,
};


float speed_ball_x, speed_ball_y;
float speed_bar = 0;
float pos_x_ball,pos_y_ball;
char actual_level = 0; //The level nr
char deleted_bricks = 0;


void create_level(char nr_level){
	char i = 0;
	for(i=0;i<lvlbrick[nr_level][0];i++){
		write_screen(lvlbrick[nr_level][2*i+1],lvlbrick[nr_level][2*i+2],1);
		write_screen(lvlbrick[nr_level][2*i+1]+1,lvlbrick[nr_level][2*i+2],1);
	}
}

void arkanoid_init(void){
	srand((unsigned) TMR0L);  //Pseudo-random seed for random generator
	if(readEE(200) < actual_level)writeEE(200, actual_level);
	if(actual_level>10 || actual_level<0) actual_level = 0;
	game_ram[0] = 4; //pos x of the arkanoid bar
	game_ram[1] = 16; //pos y of the arkanoid bar
	pos_x_ball = 5;
	pos_y_ball = 15;
	speed_ball_x = 0; //x speed (LEDs per movement)
	speed_ball_y = 0; //y speed (LEDs per movement)
	game_ram[68] = 0; //L button pressed. Avoid double movement
	game_ram[69] = 0; //R button pressed. Avoid double movement
	game_ram[67] = 1; //Game is initiated.
	game_ram[66] = 1; //Avoid launch of the ball
	if(actual_level < 3){
		arkanoid_bar[0] = 0b11110000; 
		game_ram[2] = 4; //length of the arkanoid bar
	} else if(actual_level < 7){
		arkanoid_bar[0] = 0b11100000; 
		game_ram[2] = 3; //length of the arkanoid bar
	} else {
		arkanoid_bar[0] = 0b11000000; 
		game_ram[2] = 2; //length of the arkanoid bar
	}
	arkanoid_game_speed = lvlspeed[actual_level];
	write_screen((char)pos_x_ball,(char)pos_y_ball,1);
	print_sprite(game_ram[0],game_ram[1],arkanoid_bar);
	deleted_bricks = 0;
	create_level(actual_level);
}

void arkanoid_end_game(void){
 	actual_level = 0;
	clean_screen();
	buzzer_beep(1000);
	game_selection= 9;
	ingame = 0;
	game_ram[67] = 0; //Game is initiated.
}

//There are 3 types: Borders(1), bar(2),  blocks(3) and no collision (0). 
char check_collision(char pos_x, char pos_y){ 
	char i = 0;
	//With the bar:
	if((pos_x >= game_ram[0] && pos_x < game_ram[0] + game_ram[2]) && pos_y == game_ram[1]){
		speed_ball_x = speed_ball_x + speed_bar;
		speed_ball_y = 0 - speed_ball_y;
		return 2;
	}

	//With the upper border
	if(pos_y < 1){
		speed_ball_y = 0 - speed_ball_y;
		return 1;
	}

	//With the upper border
	if(pos_y < 1){
		speed_ball_y = 0 - speed_ball_y;
		return 1;
	}
	
	//With the rigth&left border
	if(pos_x > 10 || pos_x < 1){
		speed_ball_x = 0 - speed_ball_x;
		return 1;
	}

	//With a brick:
	for(i=0;i<lvlbrick[actual_level][0];i++){	
		if(pos_x == lvlbrick[actual_level][2*i+1] && pos_y == lvlbrick[actual_level][2*i+2] && read_screen(pos_x,pos_y)==1){
			if(speed_ball_x>0) speed_ball_x = 0 - speed_ball_x;
			else speed_ball_y = 0 - speed_ball_y;
			speed_ball_x = speed_ball_x - ((rand() % 5)/10);
			write_screen(pos_x,pos_y,0);
			write_screen(pos_x+1,pos_y,0);
			deleted_bricks++;
			buzzer_beep(100);
			return 3;	
		}

		if(pos_x == lvlbrick[actual_level][2*i+1]+1 && pos_y == lvlbrick[actual_level][2*i+2] && read_screen(pos_x,pos_y)==1){
			if(speed_ball_x<0)speed_ball_x = 0 - speed_ball_x;
			else speed_ball_y = 0 - speed_ball_y;
			speed_ball_x = 0 - speed_ball_x - ((rand() % 5)/10);
			write_screen(pos_x,pos_y,0);
			write_screen(pos_x-1,pos_y,0);
			deleted_bricks++;
			buzzer_beep(100);
			return 3;	
		}
		
	}
	return 0;
}

char check_end_game_arkanoid(void){ //We have two end games: Fail (0) or pass (1)
	if(pos_y_ball > 16){
		arkanoid_end_game();
		return 1;
	}
	return 0;
}

char check_end_lvl_arkanoid(void){ //We have two end games: Fail (0) or pass (1)
	if(deleted_bricks == lvlbrick[actual_level][0]){
		actual_level++;
		clean_screen();
		arkanoid_init();
		buzzer_beep(1000);
		return 1;
	}
	return 0;
}

void move_ball(void){
	
	if(read_button(3)==0 && read_button(4) == 0){
		speed_bar = speed_bar/1.1;
	}

	while( check_collision((char)(pos_x_ball + speed_ball_x),(char) (pos_y_ball + speed_ball_y))!=0);
	write_screen((char)pos_x_ball,(char)pos_y_ball,0);
	pos_x_ball = pos_x_ball + speed_ball_x;
	pos_y_ball = pos_y_ball + speed_ball_y;
	if(speed_ball_y > 1)speed_ball_y = 1;		//In order to detect all collisions
	if(speed_ball_y < -1)speed_ball_y = -1;     //In order to detect all collisions
	if(speed_ball_x > 2)speed_ball_y = 2;		//In order to detect all collisions
	if(speed_ball_x < -2)speed_ball_y = -2;     //In order to detect all collisions
	//check_end_lvl_arkanoid();					//We exec this functions in the following if.
	//check_end_game_arkanoid();
	if(check_end_lvl_arkanoid()== 0 && check_end_game_arkanoid()==0)write_screen((char)pos_x_ball,(char)pos_y_ball,1);
}

void check_movement_arkanoid(void){
	if(game_ram[67] == 1){
		if(read_button(4)==1 && game_ram[69] == 0 && game_ram[0] < (11 - game_ram[2])){ //rigth
			
			if(speed_ball_x==0 && speed_ball_y == 0) { //INIT STATE. BALL STOPPED
				write_screen(pos_x_ball++,pos_y_ball,0);
				write_screen(pos_x_ball,pos_y_ball,1);
			}

			remove_sprite(game_ram[0],game_ram[1],arkanoid_bar);
			print_sprite(++game_ram[0],game_ram[1],arkanoid_bar);
			if(speed_bar < 0.40)speed_bar = speed_bar + 0.10;
			game_ram[69] = 1;
		} else if(read_button(4)==0){
			game_ram[69] = 0;
		}
	
		if(read_button(3)==1 && game_ram[68] == 0 && game_ram[0] > 1){ //left

			if(speed_ball_x==0 && speed_ball_y == 0) { //INIT STATE. BALL STOPPED
				write_screen(pos_x_ball--,pos_y_ball,0);
				write_screen(pos_x_ball,pos_y_ball,1);
			}

			remove_sprite(game_ram[0],game_ram[1],arkanoid_bar);
			print_sprite(--game_ram[0],game_ram[1],arkanoid_bar);
			if(speed_bar > -0.40) speed_bar = speed_bar - 0.10;
			game_ram[68] = 1;
		} else if(read_button(3)==0){
			game_ram[68] = 0;
		}
		if(read_button(6)==1 && speed_ball_x==0 && speed_ball_y == 0 && game_ram[66] == 0){ //We launch the ball
			speed_ball_x = speed_bar; //x speed (LEDs per movement)
			speed_ball_y = 1; //y speed (LEDs per movement)
		} else if(read_button(6)==0) game_ram[66] = 0;
	}
}

void arkanoid_sel_init(void){
	char j = 0,i=0 ,option=0, max_level=0;
	max_level = readEE(200); //The level nr
	if(max_level == 0) {
		actual_level = 0;
		arkanoid_init();
		return;
	} else {
		while(1){
			while(1){
				clean_buttons();
				update_buttons();
				if(read_button(4)==0 && read_button(3)==0 && read_button(5)==0 && read_button(6)==0) break;
			}	
			print_sprite(1,1,letter_L);
			print_sprite(3,1,letter_V);
			print_sprite(8,1,letter_L);
			if (max_level <= j) remove_sprite(9,12,letter_right);
			else print_sprite(9,12,letter_right);
			if (j > 0)print_sprite(1,12,letter_left);
			else remove_sprite(1,12,letter_left);
			print_sprite(4,7, letter_number[j]);

			if(read_button(4)==1 && max_level > j){ //rigth
				remove_sprite(4,7, letter_number[j++]);
				game_ram[69] = 1;
			} else if(read_button(4)==0){
				game_ram[69] = 0;
			}
			if(read_button(3)==1 && j > 0){ //rigth
				remove_sprite(4,7, letter_number[j--]);
				game_ram[68] = 1;
			} else if(read_button(3)==0){
				game_ram[68] = 0;
			}
			if(read_button(5)==1){ //Back button is pressed
				arkanoid_end_game();
				break;
			}
			if(read_button(6)==1){ //Enter button is pressed
					clean_screen();
					actual_level = j;
					arkanoid_init();
				break;
			}
		}
	}
}

#endif