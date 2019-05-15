#ifndef ENGINE_H
#define ENGINE_H

#include "board.h"
#include "move_gen.h"

struct Container{
	list<vector<Board> > Board_Container;
	list<vector<Board> >* next;
	list<vector<Board> >* prev;
};

class Game_Tree{
public:
	//Constructor
	Game_Tree(Board& root_board, const int ply);//ply is the depth weant to search
	//Update functions
	void Build_Tree(); 
	void Build_Level(Container* prev); //paramater: leftmost container of the previous level
	int Evaluate_Boards();
	//Accesor functions
	void Print_Root();
	
private:
	int ply;
	Board root;
};

#endif

