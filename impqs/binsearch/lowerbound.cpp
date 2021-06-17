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

void solve(){
	cin>>n>>k;
    vi arr(n);
    F(i,n) cin>>arr[i];
    while(k--){
        int query;
        cin>>query;
        if(query>arr[n-1]){ cout<<n+1<<endl; continue;}
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]>=query){
                ans = mid+1;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        cout<<ans<<endl;
    }
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
