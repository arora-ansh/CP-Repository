int game[9][9];

bool checknumber(int x, int y, int num){
    for(int i=0;i<9;i++){
        if(num==game[x][i]){
            return false;
        }
    }
    for(int i=0;i<9;i++){
        if(num==game[i][y]){
            return false;
        }
    }
    if(x<3){
        if(y<3){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(game[i][j]==num){
                        return false;
                    }
                }
            }
        }
        else if(y>=3 && y<6){
            for(int i=0;i<3;i++){
                for(int j=3;j<6;j++){
                    if(game[i][j]==num){
                        return false;
                    }
                }
            }  
        }
        else{
            for(int i=0;i<3;i++){
                for(int j=6;j<9;j++){
                    if(game[i][j]==num){
                        return false;
                    }
                }
            }  
        } 
    }
    else if(x>=3 && x<6){
        if(y<3){
            for(int i=3;i<6;i++){
                for(int j=0;j<3;j++){
                    if(game[i][j]==num){
                        return false;
                    }
                }
            }
        }
        else if(y>=3 && y<6){
            for(int i=3;i<6;i++){
                for(int j=3;j<6;j++){
                    if(game[i][j]==num){
                        return false;
                    }
                }
            }  
        }
        else{
            for(int i=3;i<6;i++){
                for(int j=6;j<9;j++){
                    if(game[i][j]==num){
                        return false;
                    }
                }
            }  
        }   
    }
    else{
        if(y<3){
            for(int i=6;i<9;i++){
                for(int j=0;j<3;j++){
                    if(game[i][j]==num){
                        return false;
                    }
                }
            }
        }
        else if(y>=3 && y<6){
            for(int i=6;i<9;i++){
                for(int j=3;j<6;j++){
                    if(game[i][j]==num){
                        return false;
                    }
                }
            }  
        }
        else{
            for(int i=6;i<9;i++){
                for(int j=6;j<9;j++){
                    if(game[i][j]==num){
                        return false;
                    }
                }
            }  
        }  
    }
    return true;
}

bool answer = false;

bool solver(int x, int y,int empty){
    if(empty==0){
        for(int i=0;i<9;i++){
    		for(int j=0;j<9;j++){
        		cout<<game[i][j]<<" ";
        	}
        	cout<<endl;
    	}
    	cout<<endl;
        answer = true;
    }
    
    if(game[x][y]==0){
        for(int i=1;i<=9;i++){
            if(checknumber(x,y,i)){
                //cout<<x<<" "<<y<<endl;
                game[x][y]=i;
                if(x<8){
                    solver(x+1,y,empty-1);
                }
                else if(x==8 && y<8){
                    solver(0,y+1,empty-1);
                }
                else if(x==8 && y==8){
                    answer = true;
                }
                game[x][y]=0;//backtracking
            }
        }
    }
    else{
        if(x<8){
            solver(x+1,y,empty);
        }
        else if(x==8 && y<8){
            solver(0,y+1,empty);
        }
        else if(x==8 && y==8){
            return true;
        }
    }
    if(x==8 && y==8){
        return false;
    }
}

bool sudokuSolver(int board[][9]){
    int empty = 0;
    for(int i=0;i<9;i++){
    	for(int j=0;j<9;j++){
        	game[i][j]=board[i][j];
            if(board[i][j]==0){
                empty+=1;
            }
        }
    }
	solver(0,0,empty);
    return answer;
}