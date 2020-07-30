#include <bits/stdc++.h>
#include<string>
#include<iostream>
typedef long long int ll;
using namespace std;
//Can be broken down into multiple numbers, hence making it easier to solve

long long int n = 1000000007;

ll solve2(int *input, int size, ll *dp){
    if(size==0 || size==1){
        return 1;
    }
    if(dp[size]>0){
        return dp[size];
    }
    ll ans = 0;
    if(input[size-1]!=0)
    	ans += solve2(input,size-1,dp)%n;
    if(10*input[size-2]+input[size-1]<=26 && input[size-2!=0]){
        ans += solve2(input,size-2,dp)%n;
        ans = ans%n;
    }
    dp[size] = ans;
    return ans;
}

int main()
{
    string input;
    cin>>input;
    while(input!="0"){
        int * arr = new int[input.size()];
        ll dp[input.size()+1];
        for(int i=0;i<=input.size();i++){
            dp[i] = 0;
        }
        for(int i=0;i<input.size();i++){
            arr[i] = input[i] - '0'; //Conversion of string to int imppp
        }
        cout<<solve2(arr,input.size(),dp)<<"\n";
        cin>>input;
    }
    return 0;
}