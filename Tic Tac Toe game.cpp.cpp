#include<iostream>
using namespace std;

void initialize_board(char board[3][3]){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			board[i][j]=' ';
		}
	}
}
void display_board(char board[3][3]){
	
		cout<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
		cout<<"__________"<<endl;
		cout<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
		cout<<"__________"<<endl;
		cout<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;	
	
}
bool check_win(char board[3][3], char player){
	for(int i=0; i<3; i++){
		if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
    	}
    }
	if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}
bool is_board_full(char board[3][3]){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(board[i][j]==' '){
				return false;
			}
		}
	}
	return true;
}
	


int main(){
	char board[3][3];
	int row, col;
	char curr_player='X';
	int gameover = 0;
	
	initialize_board(board);
	while(gameover!=1){
		display_board(board);
		cout<<"Player "<<curr_player<<" enter your move (row and column)";
		cin>>row>>col;
		
		
		if(row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' '  ) {
			cout<<"Invalid move. Try again."<<endl;
            continue;
        }
       
        board[row-1][col-1]=curr_player;
        
        if (check_win(board, curr_player)) {
            display_board(board);
            cout<<"Player "<<curr_player<<" win"<<endl;
            gameover = 1;
        } else if (is_board_full(board)) {
            display_board(board);
            cout<<"It's a draw!"<<endl;
            gameover = 1;
        }
        curr_player = (curr_player=='X')?'O':'X';

	}
	return 0;
	
	
	
}
