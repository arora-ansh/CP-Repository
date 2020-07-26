// N-QUEEN PROBLEM BACKTRACKING

#include <cstring> 
#include <iostream>

int board[10][10];

bool isPossible(int n,int row,int col){
    for(int i=row-1;i>=0;i--){
        if(board[i][col]==1){
            return false;
        }
    }
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]==1){
            return false;
        }
    }
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
		if(board[i][j]==1){
            return false;
        }
    }
    return true;
}

void solve(int n,int row){
    if(row==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(isPossible(n,row,i)){
            board[row][i]=1;
            solve(n,row+1);
            board[row][i]=0; //backtracking statement so that agla jo ham attempt maare that doesnt show any problem
        }
    }
    return;
}

void placeNQueens(int n){
	memset(board,0,sizeof(int)*10*10);
  	solve(n,0);
}
