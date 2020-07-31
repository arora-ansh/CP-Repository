typedef long long int ll;

ll solve(int *coins, int types, int value, ll **dp){
    if(value == 0){
        return 1;
    }
    if(value<0){
        return 0;
    }
    if(types == 0){
        return 0;
    }
    if(dp[value][types]>-1){
        return dp[value][types];
    }
    ll ans1 = solve(coins,types,value-coins[0],dp);
    ll ans2 = solve(coins+1,types-1,value,dp);
    dp[value][types] = ans1+ans2;
    return (ans1+ans2);
}


int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	ll **dp = new ll*[value+1];
    for(int i=0;i<value+1;i++){ //Method for declaring a 2D Dynamic Array
        dp[i] = new ll[numDenominations+1];
    }
    for(int i=0;i<value+1;i++){
        for(int j=0;j<numDenominations+1;j++){
            dp[i][j]=-1;
        }
    }
    ll ans = solve(denominations, numDenominations, value, dp);
    delete [] dp;
    return ans;
}