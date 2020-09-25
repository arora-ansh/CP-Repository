#include <iostream>
#define MOD 1000000007
using namespace std;

long long solver(int n, long long *dp){
	if(n<0){
		return 0;
	}
	if(n==0){
		return 1;
	}
	if(n==1){
		return 1;
	}
	if(dp[n]>-1){
		return dp[n];
	}
	long long ans = 0;
	for(int i=1;i<=6;i++){
		ans = (ans + solver(n-i,dp))%MOD;
	}
	dp[n] = ans;
	return ans;
}

int main(){
	int n;
	cin>>n;
	long long dp[n+1];
	for(int i=0;i<n+1;i++){
		dp[i] = -1;
	}
	cout<<solver(n,dp)<<endl;
	return 0;
}