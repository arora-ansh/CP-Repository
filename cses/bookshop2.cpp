#include <iostream>
using namespace std;

int main(){
    int n, x;
    cin>>n>>x;
    int price[n], page[n];
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>page[i];
    }
    int **dp = new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int[x+1];
        for(int j=0;j<=x;j++){
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(price[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-price[i-1]]+page[i-1]);
            }
        }
    }
    cout<<dp[n][x]<<endl;
    return 0;
}