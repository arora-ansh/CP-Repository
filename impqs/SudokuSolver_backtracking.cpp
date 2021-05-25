bool check(vector<vector<char>> board,char num,int row,int col){
        //3 checks - Same row, Same col, Same gridbox
        for(int i=0;i<9;i++){
            if(num==board[row][i]){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            if(num==board[i][col]){
                return false;
            }
        }
        int x = 3 * ((int) floor(row/3));
        int y = 3 * ((int) floor(col/3));
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                if(num==board[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool solveSudoku(vector<vector<char>>& board, int cur, int col) {
        //printBoard(board);
        if(cur==9){
            return true;
        }
        if(col==9){
            return solveSudoku(board,cur+1,0);
        }
        if(board[cur][col]!='.'){
            return solveSudoku(board,cur,col+1);
        }
        for(int j=1;j<=9;j++){
            if(check(board,'0'+j,cur,col)){
                board[cur][col] = '0'+j;
                if(solveSudoku(board,cur,col+1)){
                    return true;   
                }
                board[cur][col] = '.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board){
        solveSudoku(board,0,0);
    }
