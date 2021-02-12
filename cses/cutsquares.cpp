#include <iostream>
using namespace std;

int solver(int a,int b,int **dp){
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            if(i==j){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = 1e9;
                for(int k=1;k<i;k++){
                    dp[i][j] = min(dp[i][j],1+dp[i-k][j]+dp[k][j]);
                }
                for(int k=1;k<j;k++){
                    dp[i][j] = min(dp[i][j],1+dp[i][j-k]+dp[i][k]);
                }
            }
        }
    }
    // for(int i=0;i<=a;i++){
    //     for(int j=0;j<=b;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[a][b];
}

int main(){
    int a, b;
    cin>>a>>b;
    int **dp = new int*[a+1];
    for(int i=0;i<=a;i++){
        dp[i] = new int[b+1];
        for(int j=0;j<=b;j++){
            dp[i][j] = -1;
        }
    }
    cout<<solver(a,b,dp)<<endl;
    return 0;
}