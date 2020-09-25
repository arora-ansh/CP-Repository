#include <iostream>
typedef long long int ll;
using namespace std;

int main(){
	int n;
	cin>>n;
	ll arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	ll *dp = new ll[n];
	for(int i=1;i<n;i++) dp[i]=0;
	dp[0] = arr[0];
	ll ans = 0;
	for(int i=1;i<n;i++){
		//cout<<arr[i]<<" "<<dp[i-1]<<endl;
		if(arr[i]<dp[i-1]){
			ans+=(dp[i-1]-arr[i]);
			//cout<<ans<<endl;
			dp[i] = dp[i-1];
		}
		else{
			dp[i] = arr[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}