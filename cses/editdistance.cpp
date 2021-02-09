#include <iostream>
using namespace std;

int main(){
    string x,y;
    cin>>x>>y;
    int m = x.length();
    int n = y.length();
    int **dp = new int*[m+1];
    for(int i=0;i<=m;i++){
        dp[i] = new int[n+1];
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0){ //First string is empty case
                dp[i][j] = j;
            }
            else if(j==0){ //Second string empty case
                dp[i][j] = i;
            }
            else if(x[i-1]==y[j-1]){//If last character being checked is same, no operations needed
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }
        }
    }
    // for(int i=0;i<=m;i++){
    //     for(int j=0;j<=n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[m][n]<<endl;
    return 0;
}