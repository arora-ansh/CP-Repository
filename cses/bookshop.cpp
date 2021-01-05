// classic knapsack lol
#include <iostream>
using namespace std;

inline void fastio(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
}

int solver(int price[], int pages[],int mleft,int cur,int n,int **dp){
    if(cur==n || mleft<=0){
        return 0;
    }
    if(dp[cur][mleft]>-1){
        return dp[cur][mleft];
    }
    if(price[cur]<=mleft){
        int x = max(solver(price,pages,mleft-price[cur],cur+1,n,dp)+pages[cur],solver(price,pages,mleft,cur+1,n,dp));
        dp[cur][mleft] = x;
        return x;
    }
    else{
        int x = solver(price,pages,mleft,cur+1,n,dp);
        dp[cur][mleft] = x;
        return x;
    }
}

int main(){
    fastio();
    int n,x;
    cin>>n>>x;
    int price[n];
    int pages[n];
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    int **dp = new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int[x+1];
        for(int j=0;j<=x;j++){
            dp[i][j]=-1;
        }
    }
    cout<<solver(price,pages,x,0,n,dp)<<endl;
    return 0;
}