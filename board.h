
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <list>

using namespace std;
enum Color{
	White,
	Black
};

enum Pieces{
	Pawn,
	Knight,
	Bishop,
	Rook,
	Queen,
	King
};

struct Piece{
	int Board_Position;
	Pieces PieceType;
	Color PieceColor;
	string PrintName;
	bool Moved;
	vector<int> Valid_Moves;
};

class Board{
	public:
		//Constructor
		Board();
		//Copy Constructors
		Board(const Board& board_copy);
		Board(const Board& board_copy,int from_pos, int to_pos);
		//Destructor
		~Board();
		//Update functions
		void Make_Move();
		void Engine_Make_Move(const int from,const int to);
		void Active_Moves();
		//Accessor functions
		void PrintBoard() const;
		//void PrintAddress() const {cout << prev << endl;};
	private:
		friend class Generate_Moves;
		friend class Game_Tree;
		//Game board
		Piece* board[64];
		//Game state
		Color Turn;
		Color Human;
		int Evaluation;
		unsigned int MoveNumber;
		//for copied boards
		const Board* prev;
};

#endif