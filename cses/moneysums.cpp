/*
KNAPSACK
*/
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int x = 0;//Will become max possible storeable value
    for(int i=0;i<n;i++){
        cin>>arr[i];
        x+=arr[i];
    }
    bool dp[n+1][x+1];//dp i,j represents that if a value j can be formed from the first i coins from our coin array
    for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++){
            dp[i][j] = false;
        }
    }
    dp[0][0] = true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            dp[i][j] = dp[i-1][j];//If a value can be formed from first i-1 coins, it can definitely be formed from first i coins
            if(j-arr[i-1]>=0 && dp[i-1][j-arr[i-1]]){//If value j minus current coin value can be formed, so can j (by simply adding current coin value)
                dp[i][j] = true;
            }
        }
    }
    int ans = 0;
    vector<int> vals;
    for(int i=1;i<=x;i++){
        if(dp[n][i]){
            ans++;
            vals.push_back(i);
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<vals.size();i++){
        cout<<vals[i]<<" ";
    }
    cout<<endl;
    return 0;
}