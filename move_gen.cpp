#include "move_gen.h"

using namespace std;

void Generate_Moves::ValidMoves(int position, Piece *board[],Pieces type,Color color){
	
	vector<int> list;
	
	switch(type){
		case Pawn:
			//TO DO: if position is less that 8 we want to promote
			//TO DO: include el passant
			{int pawn_moves[]={8,16,9,7};

			if(color==Black){
				for(int i=0;i<4;i++){
					pawn_moves[i]=pawn_moves[i]*-1;
				}
			}

			if(board[position-pawn_moves[0]]==NULL){
				list.push_back(position-pawn_moves[0]);
			}
			if((board[position-pawn_moves[1]]==NULL)&&(board[position-pawn_moves[0]]==NULL)
				&&(board[position]->Moved==false)){
				list.push_back(position-pawn_moves[1]);
			}
			if((((position-pawn_moves[2])/8)==((position-pawn_moves[0])/8))&&((board[position-pawn_moves[2]]!=NULL))){
				list.push_back(position-pawn_moves[2]);
			}
			if((((position-pawn_moves[3])/8)==((position-pawn_moves[0])/8))&&((board[position-pawn_moves[3]]!=NULL))){
				list.push_back(position-pawn_moves[3]);	
			}
			}
			break;
			
		case Knight:
			{int knight_moves[]={-15,-17,-6,-10,10,17,15,6};
			for(int i=0;i<8;i++){
				if(((position+knight_moves[i])>=0)&&((position+knight_moves[i])<=63)){
					if(((knight_moves[i]==-17)||(knight_moves[i]==-15)||(knight_moves[i]==15)||(knight_moves[i]==17))
					&&((abs((position/8)-((position+knight_moves[i])/8))==2))){
						list.push_back(position+knight_moves[i]);
					}else if(abs(((position/8)-((position+knight_moves[i])/8)))==1){
						list.push_back(position+knight_moves[i]);
					}
				}
				}
			}
			break;
		case King:
			//TO DO: incorporate castling
			//Fallthrough
		case Queen:
			//Fallthrough

		case Rook:
			{int i = position-8;
			//upmove 
			while((i>=0)&&(i<=63)){
				if(board[i]==NULL){
					list.push_back(i);
				}else{
					list.push_back(i);
					break;
				}
				if(board[position]->PieceType==King){
					break;
				}
				i-=8;
			}
			i = position+8;
			//downmove
			while((i>=0)&&(i<=63)){
				if(board[i]==NULL){
					list.push_back(i);
				}else{
					list.push_back(i);
					break;
				}
				if(board[position]->PieceType==King){
					break;
				}
				i+=8;	
			}
			//leftmove
			i = position;
			for(int j=0;j<(position%8);j++){
				i--;
				if(board[i]==NULL){
					list.push_back(i);
				}else{
					list.push_back(i);
					break;
				}
				if(board[position]->PieceType==King){
					break;
				}

			}
			//rightmove
			i = position;
			for(int j=0;j<7-(position%8);j++){
				i++;
				if(board[i]==NULL){
					list.push_back(i);
				}else{
					list.push_back(i);
					break;
				}
				if(board[position]->PieceType==King){
					break;
				}
			}
			if((board[position]->PieceType==Rook)){break;}
			}
			case Bishop:
				//up-left diagonal
				{int i = position - 9;
				while((i>=0)&&(i<=63)){
					if((((i+9)/8)-1)==(i/8)){
						if(board[i]==NULL){
							list.push_back(i);
						}else{
							list.push_back(i);
							break;
						}
						if(board[position]->PieceType==King){
							break;
						}
						i-=9;
					}else{
						break;
					}
				}
				//up-right diagonal
				i = position - 7;
				while((i>=0)&&(i<=63)){
					if((((i+7)/8)-1)==(i/8)){
						if(board[i]==NULL){
							list.push_back(i);	
						}else{
							list.push_back(i);
							break;
						}
						if(board[position]->PieceType==King){
							break;
						}
						i-=7;	
					}else{
						break;
					}
				}
				//down-left diagonal
				i = position + 7;
				while((i>=0)&&(i<=63)){
					if((((i-7)/8)+1)==(i/8)){
						if(board[i]==NULL){
							list.push_back(i);
						}else{
							list.push_back(i);
							break;
						}
						if(board[position]->PieceType==King){
							break;
						}
						i+=7;	
					}else{
						break;
					}	
				}
				//down-right diagonal
				i = position + 9;
				while((i>=0)&&(i<=63)){
					if((((i-9)/8)+1)==(i/8)){
						if(board[i]==NULL){
							list.push_back(i);
						}else{
							list.push_back(i);
							break;
						}
						if(board[position]->PieceType==King){
							break;
						}
						i+=9;				
					}else{
						break;
					}
				}
				break;
				}
	}
	//remove white pieces landiing on white pieces
	//remove black pieces landing on black pieces
	typedef vector<int>::iterator Iterator;
	Iterator p=list.begin();
	while(p!=list.end()){
		if(board[*p]==NULL){
			p++;
			continue;
		}
		if((board[*p]->PieceColor==color)){
			p=list.erase(p);
		}else{
			++p;
		}
	}

	board[position]->Valid_Moves = list;

	//TO DO:Erase positions which are occupied by a white piece or the king
}