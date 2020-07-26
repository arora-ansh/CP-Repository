// RAT IN A MAZE PROBLEM BACKTRACKING

#include<cstring>
#include<iostream>

int board[20][20];

void solve(int maze[][20], int n, int cur1, int cur2){
    if(cur1<0 || cur1>=n || cur2<0 || cur2>=n){
        return;
    }
    else{
        board[cur1][cur2]=1;
        if(cur1==n-1 && cur2==n-1){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<board[i][j]<<" ";
                    
                }
            }
            cout<<endl;
        }
        else{
            if(maze[cur1+1][cur2]==1 && board[cur1+1][cur2]==0)
                solve(maze,n,cur1+1,cur2);
            if(maze[cur1][cur2+1]==1 && board[cur1][cur2+1]==0)
                solve(maze,n,cur1,cur2+1);
            if(maze[cur1-1][cur2]==1 && board[cur1-1][cur2]==0)
                solve(maze,n,cur1-1,cur2);
            if(maze[cur1][cur2-1]==1 && board[cur1][cur2-1]==0)
                solve(maze,n,cur1,cur2-1);
        }
        board[cur1][cur2]=0;//backtracking ke liye basically mai backtrack karke apni initial position pe aa gaya hun by entering this statement
    }
}

void ratInAMaze(int maze[][20], int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
    memset(board,0,20*20*sizeof(int));
    solve(maze,n,0,0);
}