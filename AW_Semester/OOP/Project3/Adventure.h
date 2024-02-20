#ifndef Adventure_h
#define Adventure_h
#include <math.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>

extern bool flag;		//whetehr to stop the program-- die or win
extern std::string direction_array[6];


struct S_Room{
	int z, x, y, type;
	bool use, direction[6];
};

struct S_NPC{			
	int z, x, y;
	std::string name;
};

class C_Worrior{
private:
	friend class C_Castle;
	int pos_z, pos_x, pos_y;
	bool prince;
public:
	C_Worrior();
	C_Worrior(int initial_z, int initial_x, int initial_y);
	~C_Worrior();
	void update_pos(int c);
	void find_conversation();
	void caught_conversation();
	void victory_conversation();
	void show_pos();
	
};

class C_Detecter{
	private:
		friend class C_Castle;
		S_NPC NPC;
		bool has_found, has_upgraded;
	public:
		C_Detecter();
		~C_Detecter();
		void show_NPC();
		void detect_NPC_1(int _z, int _x, int _y);
		void detect_NPC_2(int _z, int _x, int _y);
};

class C_Castle{
private:
	int now_x, now_y, now_z;
	S_Room Room[5][5][5];		//`	Qz, x, y
	C_Worrior *worrior_p;
	C_Detecter *prince_d_p;
	C_Detecter *monster_d_p;
public:
	C_Castle();	// default constructor
	C_Castle(C_Worrior *_worrior_p, C_Detecter *_a_p, C_Detecter *_b_p);//, C_Detecter *a1, C_Detecter *a2
	~C_Castle();
	void enter_room();
	void print_direction();
	void print_detecter_signal();
	void choose_direction();

	inline void clue_room(){
		std::cout << "Welcome to the clue_room." << std::endl;
		switch(Room[now_z][now_x][now_y].type%10){
			case 1: std::cout << "Congratulate, dear worrior! You find clue 1: "<< std::endl << "You are at floor 0. The monster only appears at floor 2 or 3 or 4 with rising possibility." << std::endl; break;
			case 2: std::cout << "Congratulate, dear worrior! You find clue 2: " << std::endl << "You are at floor 0. The princess is locked at floor 4 or 5 with rising possibility." << std::endl; break;
			case 3: std::cout << "Congratulate, dear worrior! You find clue 3: s" << std::endl << "You are at floor 2. you can find 2 different magic tools in a room in floor 1 and in a room in floor 2, which can help you a lot." << std::endl; break;
			default:std::cout << "something about clues went wrong" << std::endl; break;
		}
		Room[now_z][now_x][now_y].use=1;
	}
	inline void magic_room(){
		std::cout << "Welcome to the magic_room." << std::endl;
		if(Room[now_z][now_x][now_y].use)
			std::cout << "You've already taken away the magic tool in this room." << std::endl;
		else{
			switch(Room[now_z][now_x][now_y].type%10){
				case 1: std::cout << "You find a magic tool: monster_detecter." << std::endl;
						std::cout << "It will ring when monster is around you." << std::endl;
						this->monster_d_p->has_found=1;	break;
				case 2: std::cout << "You find a magic tool: prince_detecter." << std::endl;
						std::cout << "It will ring when princess is around you." << std::endl;
						this->prince_d_p->has_found=1;	break;
				default:std::cout << "something about the magic tools went wrong" << std::endl; break;
			}
			Room[now_z][now_x][now_y].use=1;
		}
	}
	inline int lobby_room(){
		std::cout << "Welcome to the lobby_room." << std::endl;
		if(this->worrior_p->prince==1){
			this->worrior_p->victory_conversation();
			return 1;
		}
		return 0;
	}
	inline void normal_room(){
		std::cout << "Welcome to the normal_room." << std::endl;
	}
	inline void prince_room(){
		if(this->worrior_p->prince==1){
			std::cout << "you come back to the room where used to lock the princess." << std:: endl;
			return;
		}
		std::cout << "You enter the room..." << std::endl << "There on the bed lies the prince." << std::endl;
		this->prince_d_p->has_found=0;
		this->prince_d_p->has_upgraded=0;
		this->worrior_p->prince=1;
		this->worrior_p->find_conversation();
	}
	inline void monster_room(){
		std::cout << "You enter the room..." << std::endl << "There in front of the window stands the monster." << std::endl;
		this->worrior_p->caught_conversation();
	};
	inline void upgrade_room(){
		std::cout << "Welcome to the upgrade_room." << std::endl;
		if(this->prince_d_p->has_found==1&&this->monster_d_p->has_found==1){
			std::cout << "All of your magic tools've been upgraded!" << std::endl;
			return;
		}
		if(this->prince_d_p->has_found==0&&this->monster_d_p->has_found==0){
			std::cout << "You don't have any magic tools to upgrade." << std::endl;
			return;
		}
			
		if(this->prince_d_p->has_found==1){
			std::cout << "Your prince detecter've been upgraded! It will show you a more detail direction!" << std::endl;
			this->prince_d_p->has_upgraded=1;
		}
		if(this->monster_d_p->has_found==1){
			std::cout << "Your monster detecter've been upgraded! It will show you a more detail direction!" << std::endl;
			this->monster_d_p->has_upgraded=1;	
		}
	}
};




#endif
