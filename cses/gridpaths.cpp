#include <iostream>
using namespace std;
#define MOD 1000000007

long long int solver(char **grid, int currow, int curcol,int n,long long int **dp){
    if(currow>n || curcol>n){
        return 0;
    }
    if(grid[currow][curcol]=='*'){
        return 0;
    }
    if(currow==n && curcol==n){
        return 1;
    }
    if(dp[currow][curcol]>-1){
        return dp[currow][curcol];
    }
    long long int x = solver(grid,currow+1,curcol,n,dp)+solver(grid,currow,curcol+1,n,dp);
    x = x%MOD;
    dp[currow][curcol] = x;
    return x;
}

int main(){
    int n;
    cin>>n;
    char **grid = new char*[n+1];
    for(int i=0;i<=n;i++){
        grid[i] = new char[n+1];
    } 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>grid[i][j];
        }
    }
    long long int **dp = new long long int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new long long int[n+1];
        for(int j=0;j<=n;j++){
            dp[i][j] = -1;
        }
    }
    cout<<solver(grid,1,1,n,dp)<<endl;
    return 0;
}