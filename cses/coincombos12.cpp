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
    for(int i=1;i<=x;i++){
        dp[i] = 0;
        for(int j=0;j<n;j++){
            if(i>=coins[j]){
                dp[i]+=dp[i-coins[j]];
                dp[i]=dp[i]%1000000007;
            }
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}