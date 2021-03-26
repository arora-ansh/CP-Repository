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
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll **dp = new ll*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new ll[n+1];
    }
    for(int i=1;i<=n;i++){
        dp[i][i] = arr[i-1];
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n-i;j++){
            int x = j;
            int y = j+i;
            if(x+1>y-1){
                dp[x][y] = max(dp[x+1][y],dp[x][y-1]);
            }
            else{
                dp[j][j+i] = dp[x+1][y-1]+max(arr[x-1],arr[y-1]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[1][n]<<endl;
    return 0;
}


