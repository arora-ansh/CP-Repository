#include <iostream>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    int coins[n];
    for(int i=0;i<n;i++){
        cin>>coins[i]; 
    }
    long long int *dp = new long long int[x+1];
    dp[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=x;j++){
            if(j-coins[i]>=0){
                dp[j] += dp[j-coins[i]];
                dp[j] %= 1000000007;
            }
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}