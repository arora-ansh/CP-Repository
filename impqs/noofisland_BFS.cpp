class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        bool visited[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                visited[i][j] = false;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // cout<<i<<" "<<j<<endl;
                // Now perform BFS starting at grid[i][j] if it is a 1
                if(grid[i][j]=='1' && !visited[i][j]){
                    ans++;
                    visited[i][j] = true;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        if(x-1>=0 && grid[x-1][y]=='1' && !visited[x-1][y]){  
                            q.push(make_pair(x-1,y));
                            visited[x-1][y] = true;
                        }
                        if(x+1<m && grid[x+1][y]=='1' && !visited[x+1][y]){
                            q.push(make_pair(x+1,y));
                            visited[x+1][y] = true;
                        }
                        if(y-1>=0 && grid[x][y-1]=='1' && !visited[x][y-1]){
                            q.push(make_pair(x,y-1));
                            visited[x][y-1] = true;
                        }   
                        if(y+1<n && grid[x][y+1]=='1' && !visited[x][y+1]){
                            q.push(make_pair(x,y+1));
                            visited[x][y+1] = true;
                        }
                    }
                }
            }
        }
        return ans;
    }
};