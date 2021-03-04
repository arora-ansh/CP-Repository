#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <queue> 
#include <string.h>
#include <string>
using namespace std;
#define MOD 1000000007

inline void fastio(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
}

typedef long long int ll;
typedef long double ld;

struct project{
    int start;
    int end;
    int reward;
};

bool comp(struct project p1, struct project p2){
    return p1.end<p2.end;
}

int main(){
    fastio();
    int n;
    cin>>n;
    struct project arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].start;
        cin>>arr[i].end;
        cin>>arr[i].reward;
    }
    sort(arr,arr+n,comp);
    ll *dp = new ll[n+1];
    dp[1] = arr[0].reward;
    for(int i=2;i<=n;i++){
        ll prof = arr[i-1].reward;
        int l = -1;
        int low = 0, high = i-2;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid].end<arr[i-1].start){
                l = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        if(l!=-1){
            prof+=dp[l+1];
        }
        dp[i] = max(dp[i-1],prof);
    }
    cout<<dp[n]<<endl;
    return 0;
}


