#include<iostream>
#include<cstring>
using namespace std;

int solver(string s1, string s2, int m, int n, int ** dp, int size1, int size2){
    if(m==0){
        return n;
    }
    if(n==0){
        return m;
    }
    if(dp[m][n]>-1){
        return dp[m][n];
    }
    int ans = 0;
    if(s1[size1-m]==s2[size2-n]){
        ans = solver(s1,s2,m-1,n-1,dp,size1,size2);
    }
    else{
        ans = min(1+solver(s1,s2,m-1,n,dp,size1,size2),min(1+solver(s1,s2,m,n-1,dp,size1,size2),1+solver(s1,s2,m-1,n-1,dp,size1,size2)));
    }
    dp[m][n] = ans;
    return ans;
}

int editDistance(string s1, string s2){

  	int m = s1.length();
    int n = s2.length();
    int ** dp = new int*[m+1];
    for(int i=0;i<=m;i++){
        dp[i]=new int[n+1];
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] = -1;
        }
    }
    return solver(s1,s2,m,n,dp,m,n);
    
}
