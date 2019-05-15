#include "board.h"
#include "move_gen.h"

Board::Board(){
	
	Turn = White;
	MoveNumber = 0;
	
	//initialize the entire 8x8 board to NULL. NULL implies no piece occupies the square.
	for(int i=1;i<=64;i++){
			board[i] = NULL;
	}
	//initialize white pawns
	for(int i=0;i<8;i++){
		board[i+48] = new Piece;
		board[i+48]->PieceType = Pawn;
		board[i+48]->PieceColor = White;
		board[i+48]->PrintName = "P";
		board[i+48]->Moved = false;

		board[i+48]->Board_Position = i+48;
	}
	
	//initialize black pawns
	for(int i=0;i<8;i++){
		board[i+8] = new Piece;
		board[i+8]->PieceType = Pawn;
		board[i+8]->PieceColor = Black;
		board[i+8]->PrintName = "P";
		board[i+8]->Moved = false;

		board[i+8]->Board_Position = i+8;
	}
	//initialize king
	board[4] = new Piece;
	board[4]->PieceType = King;
	board[4]->PieceColor = Black;
	board[4]->PrintName = "K";
	board[4]->Moved = false;

	board[4]->Board_Position = 4;
	
	board[60] = new Piece;
	board[60]->PieceType = King;
	board[60]->PieceColor = White;
	board[60]->PrintName = "K";
	board[60]->Moved = false;

	board[60]->Board_Position = 60;
	
	//initialize queen
	board[3] = new Piece;
	board[3]->PieceType = Queen;
	board[3]->PieceColor = Black;
	board[3]->PrintName = "Q";

	board[3]->Board_Position = 3;
	
	board[59] = new Piece;
	board[59]->PieceType = Queen;
	board[59]->PieceColor = White;
	board[59]->PrintName = "Q";

	board[59]->Board_Position = 59;
	
	//initialize rooks
	board[0] = new Piece;
	board[7] = new Piece;
	board[0]->PieceType = Rook;
	board[7]->PieceType = Rook;
	board[0]->PieceColor = Black;
	board[7]->PieceColor = Black;
	board[0]->PrintName = "R";
	board[7]->PrintName = "R";
	board[0]->Moved = false;
	board[7]->Moved = false;

	board[0]->Board_Position = 0;
	board[7]->Board_Position = 7;

	board[56] = new Piece;
	board[63] = new Piece;
	board[56]->PieceType = Rook;
	board[63]->PieceType = Rook;
	board[56]->PieceColor = White;
	board[63]->PieceColor = White;
	board[56]->PrintName = "R";
	board[63]->PrintName = "R";
	board[63]->Moved = false;
	board[56]->Moved = false;
	
	board[56]->Board_Position = 56;
	board[63]->Board_Position = 63;
	//initialize bishops
	board[2] = new Piece;
	board[5] = new Piece;
	board[2]->PieceType = Bishop;
	board[5]->PieceType = Bishop;
	board[2]->PieceColor = Black;
	board[5]->PieceColor = Black;
	board[2]->PrintName = "B";
	board[5]->PrintName = "B";

	board[2]->Board_Position = 2;
	board[5]->Board_Position = 5;
	
	board[58] = new Piece;
	board[61] = new Piece;
	board[58]->PieceType = Bishop;
	board[61]->PieceType = Bishop;
	board[58]->PieceColor = White;
	board[61]->PieceColor = White;
	board[58]->PrintName = "B";
	board[61]->PrintName = "B";

	board[58]->Board_Position = 58;
	board[61]->Board_Position = 61;
	
	//initialize knights
	board[1] = new Piece;
	board[6] = new Piece;
	board[1]->PieceType = Knight;
	board[6]->PieceType = Knight;
	board[1]->PieceColor = Black;
	board[6]->PieceColor = Black;
	board[1]->PrintName = "N";
	board[6]->PrintName = "N";

	board[1]->Board_Position = 1;
	board[6]->Board_Position = 6;
	
	board[57] = new Piece;
	board[62] = new Piece;
	board[57]->PieceType = Knight;
	board[62]->PieceType = Knight;
	board[57]->PieceColor = White;
	board[62]->PieceColor = White;
	board[57]->PrintName = "N";
	board[62]->PrintName = "N";

	board[57]->Board_Position = 57;
	board[62]->Board_Position = 62;
	
	}
	//copy constructor
	Board::Board(const Board& board_copy){
	//copy pieces
		for(int i=0;i<64;i++){
			if(board_copy.board[i]!=NULL){
				board[i]=new Piece;
				board[i]=board_copy.board[i];
			}else{
				board[i]=NULL;
			}
		}
	//copy member data
		Turn = board_copy.Turn;
		Human = board_copy.Human;
		MoveNumber = board_copy.MoveNumber;
	//parent board
		prev = &board_copy;

		Active_Moves();
	}
	//copy constructor for game tree
	Board::Board(const Board& board_copy,int from_pos, int to_pos){
	//copy pieces
		for(int i=0;i<64;i++){
			if(board_copy.board[i]!=NULL){
				board[i]=new Piece;
				board[i]=board_copy.board[i];
			}else{
				board[i]=NULL;
			}
		}
	//piece move
		board[to_pos]=board[from_pos];
		board[from_pos]=NULL;
		board[to_pos]->Board_Position=to_pos;
		if(board[to_pos]->Moved==false){board[to_pos]->Moved=true;}
	//copy member data
		if(board_copy.Turn==White){
			Turn = Black;
		}else{
			Turn = White;
		}
		Human = board_copy.Human;
		MoveNumber = board_copy.MoveNumber;
	//parent board
		prev = &board_copy;

	Active_Moves();
	}

void Board::Active_Moves(){
	Generate_Moves moves;
	for(int i=0;i<64;i++){
		if((board[i]!=NULL)){
			moves.ValidMoves(board[i]->Board_Position,board,board[i]->PieceType,board[i]->PieceColor);
		}
	}
	for(int i=0;i<64;i++){
		if((board[i]!=NULL)){
				cout << board[i]->PrintName << ": ";
			for(int j=0;j<board[i]->Valid_Moves.size();j++){
				cout << board[i]->Valid_Moves[j] << " ";
			}
		cout << endl;	
		}
	}
	cout << endl;

}
	//for analysis/search 
void Board::Engine_Make_Move(const int from_pos,const int to_pos){
	//piece move
	board[to_pos]=board[from_pos];
	board[from_pos]=NULL;
	board[to_pos]->Board_Position=to_pos;
	
}

void Board::Make_Move(){
	Active_Moves();
	
	int start,end;
	bool valid_move=false;
	srand(time(NULL));

	if(Turn==White){
		cout << "Piece: ";
		cin >> start;
		cout << "To: ";
		cin >> end;
		cout << endl;
		//check if move is valid
		if(board[start]==NULL){
			cout << "Move is not valid." << endl;
			return;
		}
		for(int i=0;i<board[start]->Valid_Moves.size();i++){
			if((end)==(board[start]->Valid_Moves[i])){
				valid_move=true;
			}
		}
		if(valid_move){
			board[end]=board[start];
			board[start]=NULL;
			//update new piece position and moved toggle
			board[end]->Board_Position=end;
			board[end]->Moved=true;
			//set board move to black
			Turn=Black;
		}else{
			cout << "Move is not valid." << endl;
		}

	}else{
		//TESTING: black chooses a random move
		int i,black_p,new_square;
		while(1){
			i=rand()%64;
			if((board[i]!=NULL)&&(board[i]->PieceColor==Black)){
				if(board[i]->Valid_Moves.size()!=0){
					black_p=rand()%(board[i]->Valid_Moves.size());
					new_square=board[i]->Valid_Moves[black_p];
					board[new_square]=board[i];
					board[i]=NULL;
					//update new piece position and moved toggle
					board[new_square]->Board_Position=new_square;
					board[new_square]->Moved=true;
					//set board move to black
					Turn=White;
					break;
				}
			}
		}
	}
}

void Board::PrintBoard() const{
	for(int i=0;i<64;i++){
		if(board[i]==NULL){
			cout << board[i] << " ";
		}else if(board[i]->PieceColor==Black){
			cout << "\033[1;31m"+ board[i]->PrintName +"\033[0m" << " ";
		}else if(board[i]->PieceColor==White){
			cout << "\033[1;33m"+ board[i]->PrintName +"\033[0m" << " ";
		}
		if(((i+1)%8)==0){
			cout << endl;
		}
	}
}

Board::~Board(){
	for(int i=0;i<64;i++){
		if(board[i]!=NULL){
			delete board[i];
		}
	}
}