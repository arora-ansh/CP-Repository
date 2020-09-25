#include <iostream>
#include <algorithm>
typedef long long int ll ;
using namespace std;
inline void fastio(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
}

int main(){
	int n,q;
	cin>>n>>q;
	ll arr[n];
	ll *dp = new ll[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	dp[0] = arr[0];
	for(int i=1;i<n;i++){
		dp[i] = dp[i-1] + arr[i];
	}
	while(q--){
		int x1,x2;
		cin>>x1>>x2;
		if(x1>1){
			cout<<dp[x2-1]-dp[x1-2]<<endl;
		}
		else{
			cout<<dp[x2-1]<<endl;
		}
	}
	return 0;
}