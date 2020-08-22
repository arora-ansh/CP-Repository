/*
This is a 3D DP problem, in which we calculate LCS as normal, but since the value of k, that is length of subsequence that we have to find, we have optimized based on whether we choose a particular element of a LCS or not. 
Egs if abcdef and cdefg are the strings, and k is 3, then the LCS would be cdef, but we have to choose so that the biggest 3 characters are selected only.
So, we add an option(Knapsack like) whether we'll choose that particular element or not. In case of a match of chars of string, we perform 3 checks
- We select the character, pass solver(i+1,j+1,k-1),
- We don't select the character and pass solver (i+1,j,k) and (i,j+1,k)
- We find the max of all 3.
In case of no match, we have 2 options-
- solver(i+1,j,k) and solver(i,j+1,k)
Memoize answers as they are found ez time complexity reduction. Tho iska Iterative solution abhi dekhna padega 
*/
#include <bits/stdc++.h>
using namespace std;

int solver(string s1, string s2, int size1, int size2, int i, int j, int k, int *** dp){
    if(i==0||j==0){
        return 0;
    }
    if(k==0){
        return 0;
    }
    if(dp[i][j][k]>-1){
        return dp[i][j][k];
    }
    int ans;
    if(s1[size1-i]==s2[size2-j]){
        int option1 = ((int) s1[size1-i])+solver(s1,s2,size1,size2,i+1,j+1,k-1,dp);
        if(option1==((int) s1[size1-i]) && k>1){
            option1 = 0;
        }
        int option2 = solver(s1,s2,size1,size2,i+1,j,k,dp);
        int option3 = solver(s1,s2,size1,size2,i,j+1,k,dp);
        ans = max(option1,max(option2,option3));
    }
    else{
        int option1 = solver(s1,s2,size1,size2,i+1,j,k,dp);
        int option2 = solver(s1,s2,size1,size2,i,j+1,k,dp);
        ans = max(option1,option2);
    }
    dp[i][j][k] = ans;
    return ans;
    
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        string b1,b2;
        int k;
        cin>>b1>>b2>>k;
        int m = b1.length();
        int n = b2.length();
        int ***dp = new int**[101];
        for(int i=0;i<101;i++){
            dp[i] = new int*[101];
            for(int j=0; j<101; j++){
                dp[i][j] = new int[101];
                for(int l=0;l<101;l++){
                    dp[i][j][l] = -1;
                }
            }
        }
        int ans = solver(b1,b2,m,n,m,n,k,dp);
        cout<<ans<<endl;
    }
    return 0;
}
