#include <iostream>
using namespace std;

inline void fastio(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
}

int *dp = new int[20000001];

int solver(int cur){
    if(cur==1){
        return 0;
    }
    if(dp[cur]>-1){
        return dp[cur];
    }
    if(cur%3==0 && cur%2==0){
        int x = min(1+solver(cur/3),min(1+solver(cur/2),1+solver(cur-1)));
        dp[cur] = x;
        return x;
    }
    if(cur%3==0 && cur%2!=0){
        int x = min(1+solver(cur/3),1+solver(cur-1));
        dp[cur] = x;
        return x;
    }
    if(cur%3!=0 && cur%2==0){
        int x = min(1+solver(cur/2),1+solver(cur-1));
        dp[cur] = x;
        return x;
    }
    int x = 1 + solver(cur-1);
    dp[cur] = x;
    return x;
}

int main(){
    fastio();
    for(int i=0;i<=20000000;i++){
        dp[i] = -1;
    }
    int t;
    cin>>t;
    for(int T=0;T<t;T++){
        int x;
        cin>>x;
        cout<<"Case "<<T+1<<": "<<solver(x)<<endl;
    }
    return 0;
}