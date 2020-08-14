//Largest common subsequence problem, solved by both iterative and memoization methods

int solver(string s1, string s2, int m, int n, int ** dp, int size1, int size2){
    if(m==0 || n==0){
        return 0;
    }
    if(dp[m][n]>-1){
        return dp[m][n];
    }
    int ans = 0;
    if(s1[size1-m]==s2[size2-n]){
        ans = 1 + solver(s1,s2,m-1,n-1,dp,size1,size2);
    }
    else{
        ans = max(solver(s1,s2,m,n-1,dp,size1,size2), solver(s1,s2,m-1,n,dp,size1,size2));
    }
    dp[m][n] = ans;
    return ans;
}

int lcs(string s1, string s2)
{
    //Recursion+Memoization
    int m = s1.length();
    int n = s2.length();
    int ** dp = new int*[m+1];
    for(int i=0;i<m+1;i++){
        dp[i] = new int[n+1];
    }
    /*for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            dp[i][j]=-1;
        }
    }
    int ans = solver(s1,s2,m,n,dp,m,n); */
    
    //Iteration
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(s1[m-i]==s2[n-j]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int ans = dp[m][n];
    return ans;
}
