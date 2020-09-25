#include <iostream>
#include <algorithm>
typedef long long int ll ;
using namespace std;
inline void fastio(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
}

void dfs(char **grid,int rows,int cols,int currow,int curcol,bool **visited){
	visited[currow][curcol]=true;
	if(currow<rows-1){
		if(grid[currow+1][curcol]=='.' && !visited[currow+1][curcol]){
			dfs(grid,rows,cols,currow+1,curcol,visited);
		}
	}
	if(currow>0){
		if(grid[currow-1][curcol]=='.' && !visited[currow-1][curcol]){
			dfs(grid,rows,cols,currow-1,curcol,visited);
		}
	}
	if(curcol>0){
		if(grid[currow][curcol-1]=='.' && !visited[currow][curcol-1]){
			dfs(grid,rows,cols,currow,curcol-1,visited);
		}
	}
	if(curcol<cols-1){
		if(grid[currow][curcol+1]=='.' && !visited[currow][curcol+1]){
			dfs(grid,rows,cols,currow,curcol+1,visited);
		}
	}
}

int main(){
	int rows,cols;
	cin>>rows>>cols;
	char **map = new char*[rows];
	for(int i=0;i<rows;i++){
		map[i] = new char[cols];
		for(int j=0;j<cols;j++){
			cin>>map[i][j];
		}
	}
	bool **visited = new bool*[rows];
	for(int i=0;i<rows;i++){
		visited[i] = new bool[cols];
		for(int j=0;j<cols;j++){
			visited[i][j]=false;
		}
	}
	int rooms = 0;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(map[i][j]=='.' && !visited[i][j]){
				dfs(map,rows,cols,i,j,visited);
				rooms+=1;
			}
		}
	}
	cout<<rooms<<endl;
	return 0;
}