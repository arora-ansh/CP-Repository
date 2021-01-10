#include <iostream>
#include <vector>
using namespace std;

int solver(int n, int *dp){
    //cout<<n<<endl;
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    vector<int> arr;
    int x = n;
    while(x!=0){
        //cout<<x%10<<" ";
        arr.push_back(x%10);
        x = x/10;
    }
    //cout<<endl;
    dp[n] = 100000000;
    for(int i=0;i<arr.size();i++){
        if(n-arr[i]>=0){
            dp[n] = min(dp[n],1+solver(n-arr[i],dp));
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    int *dp = new int[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = -1;
    }
    cout<<solver(n,dp)<<endl;
    return 0;
}