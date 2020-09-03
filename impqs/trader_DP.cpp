//Another 3D Dynamic Programming problem where 3D DP Tables involved. Yahan pe onGoing waala point was extra
//which had to be taken into account. Based on that options were created. rather easy lol

#include <bits/stdc++.h>
using namespace std;

int solver(int *arr, int n, int k, int onGoing, int ***dp){
    if(n==0){
        return 0;
    }
    if(k==0){
        return 0;
    }
    if(dp[n][k][onGoing]>-1){
        return dp[n][k][onGoing];
    }
    int ans;
    if(onGoing==1){//Ya toh can sell or move to the next as it is
        int option1 = solver(arr+1,n-1,k,onGoing,dp);
        int option2 = arr[0]+solver(arr+1,n-1,k-1,0,dp);
        ans = max(option1,option2);
    }
    else{//Ya toh khareed sakta hun ya phir aise hi aage waale pe jaa sakta
        int option1 = solver(arr+1,n-1,k,onGoing,dp);
        int option2 = solver(arr+1,n-1,k,1,dp)-arr[0];
        ans = max(option1,option2);
    }
    dp[n][k][onGoing] = ans;
    return ans;
}

int main()
{
    int q;
    cin>>q;
    while(q--){
        int k, n;
        cin>>k>>n;
        int arr[n];
        for(int i=0;i<n;i++){ 
            cin>>arr[i];
        }
        int *** dp = new int**[n+1];
        for(int i=0;i<=n;i++){
            dp[i] = new int*[k+1];
            for(int j=0;j<=k;j++){
            	dp[i][j] = new int[2];
                for(int m=0;m<2;m++){
                    dp[i][j][m] = -1;
                }
            }
        }
        cout<<solver(arr,n,k,0,dp)<<endl;
    }
    return 0;
}
