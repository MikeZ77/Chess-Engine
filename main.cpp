
#include "board.h"
#include "move_gen.h"
#include "engine.h"

int main(void){

	Board main_board;
	//main_board.Active_Moves(); 		//must be copied with active moves when passed to Tree for destructor
	Board analysis_board(main_board);
	Game_Tree Tree(analysis_board,5);
	Tree.Build_Tree();
		

	main_board.PrintBoard();

	// while(1){
	// 	main_board.Make_Move();
	// 	main_board.PrintBoard();
	// }

	

	return 0;
}