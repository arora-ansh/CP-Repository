#include <iostream>
#include <algorithm>
#define MOD 1000000007 
using namespace std;

inline void fastio(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
}

int main(){
    fastio();
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }  
    sort(arr,arr+n);
    long long int dp[x+1];
    if(arr[0]>x){
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<=x;i++){
        dp[i] = 0;
    }
    int start = arr[0];
    dp[start] = 1;
    for(int i=start+1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(arr[j]<i){
                dp[i]=(dp[i]%MOD+dp[i-arr[j]]%MOD)%MOD;
            }
            else if(arr[j]==i){
                dp[i]+=1;
            }
            else{
                break;
            }
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}