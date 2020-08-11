#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long int ll;
//Here solving the question on paper gives us the trick we need to apply DP
int main()
{
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    ll sum[n];
    sum[0]=arr[0];
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+arr[i];
    }
    ll * dp = new ll[n-k];
    for(int i=0;i<n-k;i++){
        dp[i] = 0;
    }
    int ans = 0;
	//We will first calculate the unfairness of first k elements
    for(int i=1;i<k;i++){
        dp[0]+=(i*arr[i]-sum[i-1]);
    }
    ans = dp[0];
    for(int i=1;i<n-k;i++){
        dp[i] = dp[i-1]+(k-1)*(arr[i-1]+arr[k+i-1])-2*(sum[k+i-2]-sum[i-1]);
        if(ans>dp[i]){
            ans = dp[i];
        }
    }
    cout<<ans<<endl;
    delete [] dp;
    return 0;
}
