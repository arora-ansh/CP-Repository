//Matrix Parenthesization Problem
#include <iostream>
using namespace std;

int solver(int * p, int i, int j, int ** dp){
	if(i==j){
		return 0;
	}
	if(dp[i][j]>0){
		return dp[i][j];
	}
	int min = INT_MAX;
	int count;
	for(int k=i;k<j;k++){
		count = solver(p, i, k, dp) + solver(p, k + 1, j, dp) + p[i - 1] * p[k] * p[j]; 
		if (count < min) 
			min = count; 
	}
	dp[i][j] = min;
	return min;
}

int main(){
	int arr[] = {1,2,3,4,3,4, 5, 8};
	int n = 8;
	int ** dp = new int*[n+1];
	for (int i = 0; i < n+1; i++){
		dp[i] = new int[n+1];
	}
	int ans = solver(arr,1,n-1,dp);
	cout<<ans<<endl;
	return 0;
}

