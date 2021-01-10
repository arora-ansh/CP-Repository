#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int *dp = new int[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = -1;
    }
    for(int i=0;i<n;i++){
        dp[arr[i]] = 1;
    }
    int y = arr[0];
    for(int i=y+1;i<=n;i++){
        if(dp[i]==1){
            continue;
        }
        else{
            for(int j=0;j<n;j++){
                if(i-arr[j]>=0 && dp[i-arr[j]]!=-1){
                    if(dp[i]==-1){
                        dp[i] = dp[i-arr[j]]+1;
                    }
                    else{
                        dp[i] = min(dp[i],dp[i-arr[j]]+1);
                    }
                }
            }
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}