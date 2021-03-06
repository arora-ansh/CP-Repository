#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <queue> 
#include <string.h>
#include <string>
using namespace std;
#define MOD 1000000007

inline void fastio(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
}

typedef long long int ll;
typedef long double ld;

int main(){
    fastio();
    int n;
    cin>>n;
    ll x = n*(n+1)/2;
    if(x%2!=0){
        cout<<0<<endl;
        return 0;
    }
    x/=2;
    ll **dp = new ll*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new ll[x+1];
    }
    dp[0][0] = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=x;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=i){
                dp[i][j]+=dp[i-1][j-i];
                dp[i][j]%=MOD;
            }
        }
    }
    cout<<dp[n-1][x]<<endl;
    return 0;
}


