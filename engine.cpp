#include "engine.h"


Game_Tree::Game_Tree(Board& root_board, const int ply): root(root_board), ply(ply) {}

void Game_Tree::Print_Root(){
	root.PrintBoard();
}

void Game_Tree::Build_Tree(){
	//add starting position
	Container* base_position = new Container;
	vector<Board> board;
	board.push_back(root); //uses the Board copy constructor
	base_position->Board_Container.push_front(board);
	//add (ply) levels
	//for(int i=0;i<ply;i++){

		Build_Level(base_position);
	//}

}

void Game_Tree::Build_Level(Container* prev){
	
	Container* new_level = new Container;
	vector<Board> temp;
	int total_possible_moves;

	list<vector<Board> >::iterator list_it;
	vector<Board>::iterator vec_it;
	//generate valid moves for each piece for level + 1
	for(list_it = prev->Board_Container.begin();list_it != prev->Board_Container.end();++list_it){
		for(vec_it = list_it->begin();vec_it != list_it->end();++vec_it){
			vec_it->Active_Moves();

			for(int i=0;i<64;i++){
				if(vec_it->board[i]!=NULL){
					//cout << vec_it->board[i]->Valid_Moves.size() << endl;
					for(int j=0;j<(vec_it->board[i]->Valid_Moves.size());j++){
						//makes a copy of board in vector
						
						//temp.insert(temp.begin(),*vec_it);
						cout << "-------------" << endl;
						temp.push_back(Board(*vec_it,vec_it->board[i]->Board_Position, vec_it->board[i]->Valid_Moves[j]));
						cout << "-------------" << endl;
						//cout << vec_it->board[i]->Valid_Moves[j] << " ";

						//temp[j].Engine_Make_Move(i, vec_it->board[i]->Valid_Moves[j]);
					}
					//cout << endl;
					
				}
			}
		
		}
		// new_level->Board_Container.push_front(temp);
		// //remove elements from temp
		// for(int i=0;i<temp.size();i++){
		// 	temp.pop_back();
		// }
	}
	//build level
	


}