#ifndef MOVE_GEN_H
#define MOVE_GEN_H
#include "board.h"

using namespace std;

class Generate_Moves{
	public:
		//Default constructor
		//Update function
		void ValidMoves(int position,Piece *board[],Pieces type,Color color);
	private:
		//TODO:Checkmate,check,forced
};

#endif