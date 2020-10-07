#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
int main()
{
    fastio();
    ll c,n,x;
    cin>>n>>x;
    
    vector<ll> coins;
    
    for(int i=0;i<n;i++)
    {
        cin>>c;
        coins.push_back(c);
    }
    
    vector<ll> dp(x+1,0);
    
    for(ll i=1;i<=x;i++){
        dp[i]=INT_MAX;
        for(ll j=0;j<n;j++)
        {
            if(i-coins[j] >= 0)
            dp[i] = min(dp[i],dp[i-coins[j]]+1);
        }
    }
    if(dp[x]>=INT_MAX){
        cout<<-1<<endl;
    }
    else{
        cout<<dp[x]<<endl;
    }
    
}   