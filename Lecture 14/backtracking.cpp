#include <iostream>

using namespace std;

bool isSafe(int board[][3],int row,int col, int n){

	for(int i=0;i<row;i++){
		if(board[i][col]){
			return false;
		}
	}

	int x = row;
	int y = col;

	while(x>=0 and y>=0){
		if(board[x][y]){
			return false;
		}
		x--;
		y--;
	}

	x = row;
	y = col;

	while(x>=0 and y<n){
		if(board[x][y]){
			return false;
		}
		x--;
		y++;
	}

	return true;

}

// bool NQueens(int board[][4],int row,int n){

// 	if(row==n){
// 		return true;
// 	}

// 	for(int col=0;col<4;col++){

// 		if(isSafe(board,row,col,n)){

// 			board[row][col] = 1;

// 			bool rest_of_the_queens = NQueens(board,row+1,n);

// 			if(rest_of_the_queens){
// 				return true;
// 			}

// 			board[row][col] = 0;

// 		}

// 	}

// 	return false;

// }

// void printNQueens(int board[][4],int row,int n){
// 	if(row==n){
// 		for(int i=0;i<n;i++){
// 			for(int j=0;j<n;j++){
// 				if(board[i][j]){
// 					cout<<"Q ";
// 				}else{
// 					cout<<"_ ";
// 				}
// 			}
// 			cout<<endl;
// 		}

// 		cout<<"*****************"<<endl;

// 		return;
// 	}

// 	for(int col=0;col<4;col++){

// 		if(isSafe(board,row,col,n)){

// 			board[row][col] = 1;

// 			printNQueens(board,row+1,n);

// 			board[row][col] = 0;

// 		}

// 	}
// }

int countNQueens(int board[][3],int row,int n){
	if(row==n){
		return 1;
	}

	int count = 0;

	for(int col=0;col<n;col++){

		if(isSafe(board,row,col,n)){

			board[row][col] = 1;

			count += countNQueens(board,row+1,n);

			board[row][col] = 0;

		}

	}

	return count;
}

bool ratInAMaze(char maze[][4],int sol[][4],int row,int col,int endRow,int endCol){

	if(row==endRow and col==endCol){

		sol[row][col] = 1;

		for(int i=0;i<=endRow;i++){
			for(int j=0;j<=endCol;j++){
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;

		return true;
	}

	if(row>endRow or col>endCol){
		return false;
	}

	if(maze[row][col]=='X'){
		return false;
	}


	sol[row][col] = 1;

	bool horizontalWay = ratInAMaze(maze,sol,row,col+1,endRow,endCol);
	bool verticalWay = ratInAMaze(maze,sol,row+1,col,endRow,endCol);

	sol[row][col] = 0;

	if(horizontalWay or verticalWay){
		return true;
	}

	// sol[row][col] = 0;

	return false;
}

int main(){

	int board[3][3] = {0};
	int n = 3;
	// cout<<NQueens(board,0,n)<<endl;
	// cout<<countNQueens(board,0,n)<<endl;
	// printNQueens(board,0,n);

	// char maze[4][4] = {
	// 	 {'0','0','0','X'},
	// 	 {'0','0','X','0'},
	// 	 {'0','0','0','0'},
	// 	 {'0','0','0','0'}
	// };

	// int sol[4][4] = {0};

	// cout<<ratInAMaze(maze,sol,0,0,3,3)<<endl;

	int mat[9][9] = {
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}
    };

	return 0;
}

