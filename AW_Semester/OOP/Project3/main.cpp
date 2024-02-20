#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include "Adventure.h"


bool flag=0;
std::string direction_array[6]={"north", "east", "south", "west", "up", "down"};
S_NPC Monster, Prince;


int main(int argc, char** argv) {
	
	srand(time(0));
	C_Detecter Prince_Detecter;		//a magic tool
	C_Detecter Monster_Detecter;	//a magic tool
	C_Worrior Worrior(0,2,2);		//you
	C_Castle Castle(&Worrior, &Prince_Detecter, &Monster_Detecter);	//the castle, or, the map

//	Prince_Detecter.show_NPC();
//	Monster_Detecter.show_NPC();
//  the lines above can print the positon of the princess or the monster
	while(!flag){
		Castle.enter_room();			//the information of the room
		if(flag) break;
		Castle.print_detecter_signal();	//if you've found the magic tools
		Castle.print_direction();		//print the direction
		Castle.choose_direction();		//choose the direction
		std::cout << std::endl;
		
	}
	
	return 0;
}
