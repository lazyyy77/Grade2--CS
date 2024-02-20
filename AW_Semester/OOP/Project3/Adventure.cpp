#include "Adventure.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>

C_Castle::C_Castle(){

	worrior_p=NULL;
}

/*this function initialize the map
it build the map as the information in map.xlse in the folder.
it also randomly set the position of princess and the monster.
*/
C_Castle::C_Castle(C_Worrior *_worrior_p, C_Detecter *_Prince_Detecter_p, C_Detecter *_Monster_Detecter_p){
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			for(int k=0;k<5;k++){
				Room[i][j][k].z=i;
				Room[i][j][k].x=j;
				Room[i][j][k].y=k;
				Room[i][j][k].use=0;
				if(i<2)
					Room[i][j][k].type=0;
				else
					Room[i][j][k].type=1;
				for(int l=0;l<6;l++)
					Room[i][j][k].direction[l]=0;
			}
	Room[0][1][1].type=Room[0][1][2].type
	=Room[0][2][1].type=Room[0][2][4].type=1;
	Room[0][2][2].type=50;
	if(rand()%2)
		Room[0][2][3].type=21, Room[0][3][1].type=22;
	else
		Room[0][2][3].type=22, Room[0][3][1].type=21;
		
	Room[1][0][0].type=Room[1][0][1].type=Room[1][1][1].type=Room[1][1][2].type
	=Room[1][1][3].type=Room[1][2][3].type=Room[1][2][4].type=Room[1][3][3].type
	=Room[1][4][1].type=Room[1][4][2].type=Room[1][4][3].type=1;
	Room[1][0][3].type=31;
	
	Room[2][0][2].type=Room[2][1][4].type=Room[2][2][3].type
	=Room[2][2][4].type=Room[2][3][3].type=Room[2][3][4].type
	=Room[2][4][0].type=Room[2][4][3].type=Room[2][4][4].type=0;
	Room[2][0][4].type=23;
	Room[2][2][1].type=40;
	Room[2][2][2].type=32;
	
	Room[3][0][2].type=Room[3][2][1].type=Room[3][2][2].type
	=Room[3][2][3].type=Room[3][3][3].type=0;
	
	
	Room[4][1][1].type=0;
	
// these lines print the room type
//	for(int i=0;i<5;i++){
//		std::cout << "floor" << i << std::endl;
//		for(int j=0;j<5;j++){
//			for(int k=0;k<5;k++){
//				std::cout << std::setw(3) << Room[i][j][k].type;
//			}
//			std::cout << std::endl;
//		}
//	}

	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			for(int k=0;k<5;k++){
				if(Room[i][j][k].type==0)
					continue;
				if(j>0&&Room[i][j-1][k].type!=0)
					Room[i][j][k].direction[0]=1;
				if(k>0&&Room[i][j][k-1].type!=0)
					Room[i][j][k].direction[3]=1;
				if(j<4&&Room[i][j+1][k].type!=0)
					Room[i][j][k].direction[2]=1;
				if(k<4&&Room[i][j][k+1].type!=0)
					Room[i][j][k].direction[1]=1;
			}
		}
	}
	
	Room[0][1][1].direction[4]=Room[0][2][4].direction[4]=Room[1][0][0].direction[4]=Room[1][4][2].direction[4]
	=Room[2][0][3].direction[4]=Room[2][3][0].direction[4]=Room[3][4][4].direction[4]=1;
	Room[1][1][1].direction[5]=Room[1][2][4].direction[5]=Room[2][0][0].direction[5]=Room[2][4][2].direction[5]
	=Room[3][0][3].direction[5]=Room[3][3][0].direction[5]=Room[4][4][4].direction[5]=1;
	
// these lines print the doors
//	for(int i=0;i<5;i++){
//		std::cout << "floor" << i << std::endl;
//		for(int j=0;j<5;j++){
//			for(int k=0;k<5;k++){
//				for(int l=0;l<6;l++)
//					std::cout << Room[i][j][k].direction[l];
//				std::cout << " ";
//			}
//			std::cout << std::endl;
//		}
//	}
	
	worrior_p=_worrior_p;
	prince_d_p=_Prince_Detecter_p;
	monster_d_p=_Monster_Detecter_p;
	
	
	//these lines randomly set the position of princess and monster.
	int rand_z, rand_x, rand_y, rand_flag=0;
	
	rand_z=rand()%6;
	if(rand_z<=0)	rand_z=2;
	else if(rand_z<=2)	rand_z=3;
	else	rand_z=4;
	while(rand_flag==0){
		rand_x=rand()%5;
		rand_y=rand()%5;
		if(Room[rand_z][rand_x][rand_y].type==1){
			Room[rand_z][rand_x][rand_y].type=60;
			this->monster_d_p->NPC.z=rand_z, this->monster_d_p->NPC.x=rand_x, this->monster_d_p->NPC.y=rand_y;
			this->monster_d_p->NPC.name="monster";
			this->monster_d_p->has_found=0;
			this->monster_d_p->has_upgraded=0;
			rand_flag=1;
		}
	}
	
	rand_z=rand()%3;
	if(rand_z<=0)	rand_z=3;
	else	rand_z=4;
	rand_flag=0;
	while(rand_flag==0){
		rand_x=rand()%5;
		rand_y=rand()%5;
		if(Room[rand_z][rand_x][rand_y].type==1){
			Room[rand_z][rand_x][rand_y].type=70;
			this->prince_d_p->NPC.z=rand_z, this->prince_d_p->NPC.x=rand_x, this->prince_d_p->NPC.y=rand_y;
			this->prince_d_p->NPC.name="prince";		
			this->prince_d_p->has_found=0;
			this->prince_d_p->has_upgraded=0;
			rand_flag=1;
		}
	}
	

}

C_Castle::~C_Castle(){

}

/*this function determine the type of the room you entered.
the switch turn to the inline function that corresponding to the specific room.
*/
void C_Castle::enter_room(){
	now_x=this->worrior_p->pos_x;
	now_y=this->worrior_p->pos_y;
	now_z=this->worrior_p->pos_z;
	switch(Room[now_z][now_x][now_y].type/10){
		case 0:	normal_room();	break;
		case 2:	clue_room();	break;
		case 3:	magic_room();	break;
		case 4:	upgrade_room();	break;
		case 5:	flag=lobby_room();		break;
		case 6: monster_room(); flag=1; break;
		case 7: prince_room();	break;
		default:
			std::cout << "something went wrong" << std::endl;
			flag=1; break;
	}
	if(flag==1)
		return;
	
	
}

/*this function print the exits you can go
*/
void C_Castle::print_direction(){
	int num=0;
	for(int i=0;i<6;i++){
		if(Room[now_z][now_x][now_y].direction[i]==1)
			num++;
	}
	std::cout << "There are " << num << " exits:";
	for(int i=0;i<6;i++){
		if(Room[now_z][now_x][now_y].direction[i]==1)
			std::cout << " " << direction_array[i];
	}
	std::cout << std::endl << "Enter your command:" << std::endl;

}

/*this function is the way those magic tools works.
the magic tools can help you to find the position of monster and princess.
*/
void C_Castle::print_detecter_signal(){
	if(this->prince_d_p->has_found==1){
		if(this->prince_d_p->has_upgraded==0)	this->prince_d_p->detect_NPC_1(now_z, now_x, now_y);
		else	this->prince_d_p->detect_NPC_2(now_z, now_x, now_y);
	}
	if(this->monster_d_p->has_found==1){
		if(this->monster_d_p->has_upgraded==0)	this->monster_d_p->detect_NPC_1(now_z, now_x, now_y);
		else	this->monster_d_p->detect_NPC_2(now_z, now_x, now_y);
	}
}

/*use this function to input the go direction.
it has a protection so if you type in something wrong or illegal,
the program will remind you to type in again.
*/
void C_Castle::choose_direction(){
	std::string way;
	int illegal, find=0;
	do{
		illegal=0;
		std::cin >> way;
		if(way.compare("go")){
			illegal=1;
			std::cin >> way;
		}else{
			std::cin >> way;
			for(int i=0;i<6;i++){
				if(way.compare(direction_array[i])==0){
					if(Room[now_z][now_x][now_y].direction[i]==0){
					illegal=1;
					}else{
						this->worrior_p->update_pos(i);
						find=1;
						break;
					}
				}
			}
		}
		if(illegal||!find)
			std::cout << "illegal input. please type in the right command:" << std::endl;
	}while(illegal||!find);
	

}


C_Worrior::C_Worrior(){
	pos_z=0;
	pos_x=2;
	pos_y=2;
	prince=0;
}

/*
this function initialize the information of you.
*/
C_Worrior::C_Worrior(int i_z, int i_x, int i_y){
	pos_z=i_z;
	pos_x=i_x;
	pos_y=i_y;
	prince=0;
}

C_Worrior::~C_Worrior(){
	
}

void C_Worrior::find_conversation(){
	std::cout << "You walk close to the princess." << std::endl;
	std::cout << "The princess open her eyes." << std::endl;
	std::cout << "Princess: Are you coming to save me?" << std::endl;
	std::cout << "You: Sure! The monster is still in the castle! Let's run!" << std::endl;
	std::cout << "You grab the princess's hand and start to run." << std::endl;
}

void C_Worrior::caught_conversation(){
	std::cout << "ahhhh" << std::endl << "You Lose..." << std::endl;
}

void C_Worrior::victory_conversation(){
	std::cout << "yeahhh! You successfully save the princess." << std::endl << "You and princess leave this castle and live a happy life. The game ends." << std::endl;
}

/*this information update the position of you after input the go direction.
*/
void C_Worrior::update_pos(int c){
//	int x;
//	std::cin >> x; 
	switch(c){
		case 0:	pos_x--;break;
		case 1:	pos_y++;break;
		case 2: pos_x++;break;
		case 3: pos_y--;break;
		case 4: pos_z++;break;
		case 5: pos_z--;break;
		default: std::cout << "???";break;
	}
	
}

/*this function is only a tool to print the position.
it won't be used when the program runs.
*/
void C_Worrior::show_pos(){
	std::cout << pos_z << " " << pos_x << " " << pos_y << std::endl;
}

/*this function initialize the magic tools
*/
C_Detecter::C_Detecter(){
	NPC.z=NPC.x=NPC.y=0;
	NPC.name="null";
	has_found=has_upgraded=0;
}

C_Detecter::~C_Detecter(){
	
}

/*this function is only a tool to print the position.
it won't be used when the program runs.
*/
void C_Detecter::show_NPC(){
	std::cout << NPC.name << " " << NPC.z << " " << NPC.x << " " << NPC.y << std::endl;
}

/*
this is how the magic tools work
*/
void C_Detecter::detect_NPC_1(int _z, int _x, int _y){
	if(_z!=NPC.z)	return;
	if(NPC.y==_y&&abs(NPC.x-_x)<=1||NPC.x==_x&&abs(NPC.y-_y)<=1){
		//std::cout << NPC.x << " " << _x << " " << NPC.y << " " << _y << std::endl;
		std::cout << "Ringinging! the " << NPC.name << " detecter find something!" << std::endl;
	}
		
	return;
}

/*
this is how the magic tools work
*/
void C_Detecter::detect_NPC_2(int _z, int _x, int _y){
	//std::cout << NPC.z << " " << _z << std::endl;
	if(_z<NPC.z){
		std::cout << NPC.name << " is upstair" << std::endl;
		return;
	}else if(_z>NPC.z){
		std::cout << NPC.name << " is downstair" << std::endl;
		return;
	}else{
		//std::cout << NPC.x << " " << _x << " " << NPC.y << " " << _y << std::endl;
		if(_x<NPC.x)	std::cout << NPC.name << " is at south, ";
		else if(_x>NPC.x)	std::cout << NPC.name << " is at north, ";
		else if(_x==NPC.x)	std::cout << NPC.name << " is at same row, ";
		if(_y<NPC.y)	std::cout << NPC.name << " is at east" << std::endl;
		else if(_y>NPC.y)	std::cout << NPC.name << " is at west" << std::endl;
		else if(_y==NPC.y)	std::cout << NPC.name << " is at same col" << std::endl;
		return;
	}
		
}





