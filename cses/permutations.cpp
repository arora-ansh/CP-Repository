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
    cin >> n;
    if (n == 1) {
        cout<<1; return;
    }
    if (n < 4) {
        cout<<"NO SOLUTION"; return;
    }
    for(int i = 2; i <= n; i += 2) {
        cout<<i<<" ";
    }
    for(int i = 1; i <= n; i += 2) {
        cout<<i<<" ";
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

// 1 -> No 
// 2 -> No
// 3 -> No
// 4 -> 2 4 1 3
// 5 -> 2 4 1 3 5
// 6 -> 2 4 6 1 3 5
// 7 -> 2 4 6 1 3 5 7
