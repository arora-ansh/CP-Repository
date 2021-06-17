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

#define F(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
typedef pair<int, int>	pii; 	//Pair Int Int
typedef vector<int>		vi;		//Vector Int
typedef vector<pii>		vpii;	//Vector of Pair Int Int
typedef vector<vi>		vvi;	//Vector of Vector Int
const int N = 2e6+13;
vi g[N];
int a[N];
int n, m, k;

inline void fastio(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
}

typedef long long int ll;
typedef long double ld;

bool possible(int n, int m, int val,int k){
    long long int pillows = 0;
    // if((val-(n-k))<=0 || (val-(k-1))<=0) return false;
    if(k%2==0){
        pillows+=(k/2)*(2*val - (k-1));
    }
    else{
        pillows+=(k)*(val - ((k-1)/2));
    }
    if((n-k)%2==0){
        pillows+=(n-k+1)*(val-((n-k)/2));
    }
    else{
        pillows+=((n-k+1)/2)*(2*val-n+k);
    }
    pillows-=val;
    // cout<<val<<" "<<k<<" "<<pillows<<endl;
    if(pillows<=m) return true;
    return false;
}

void solve(){
	cin>>n>>m>>k;
    int low = 1;
    int high = m;
    int ans = low;
    while(low<=high){
        int mid = (low+high)/2;
        if((mid-(n-k))<=0 || (mid-(k-1))<=0){
            low = mid + 1;
            continue;
        }
        if(possible(n,m,mid,k)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout<<ans<<endl;
}

int main(){
    fastio();
    // int t;
    // cin>>t;
    // while(t--){
	// 	solve();
    // }
	solve();
    return 0;
}
