#include <iostream>
#define MOD 1000000007
typedef long long int ll;
using namespace std;

int main(){
	ll n;
	cin>>n;
	ll *dp = new ll[n+1];
	dp[0] = 0;
	dp[1] = 1;
	for(int i=2;i<n+1;i++){
		dp[i] = (dp[i-1]%MOD + dp[i-2]%MOD)%MOD;
	}
	cout<<dp[n]<<endl;
	return 0;
}