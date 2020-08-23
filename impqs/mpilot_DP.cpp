#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

long long solver(ll *arr1, ll*arr2, int n, int assistants, ll **dp){
    if(n==0){
        return 0;
    }
    if(dp[n][assistants]>-1){
        return dp[n][assistants];
    }
    ll ans;
    if(assistants==0){
        ans = arr2[0]+solver(arr1+1,arr2+1,n-1,assistants+1,dp);
    }
    else if(assistants>=n/2){
        ans = arr1[0]+solver(arr1+1,arr2+1,n-1,assistants-1,dp);
    }
    else{
        int option1 = arr2[0]+solver(arr1+1,arr2+1,n-1,assistants+1,dp);
        int option2 = arr1[0]+solver(arr1+1,arr2+1,n-1,assistants-1,dp);
        ans = min(option1,option2);
    }
    dp[n][assistants] = ans;
    return ans;
}

int main()
{
    int n;
    cin>>n;
    ll * arr1 = new ll[n];
    ll * arr2 = new ll[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i]>>arr2[i];
    }
    //Similar to stocks waala question, here also we have to find max profit generation, but here we cannot
    //drop any since we have to select all pilots.
    ll ** dp = new ll*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new ll[(n/2)+1];
        for(int j=0;j<=n/2;j++){
            dp[i][j]=-1;
        }
    }
    ll ans = solver(arr1,arr2,n,0,dp);
    cout<<ans<<endl;
    return 0;
}


