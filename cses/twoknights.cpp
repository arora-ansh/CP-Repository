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
    cin>>n;
    cout<<0<<endl;
    if (n==1) return;
    ll x = 2, y = 3;
    ll a = 2, b = 4;
    for(int i=1; i<n; i++) {
        ll z = x * y;
        cout<<z<<endl;
        x += a; a += 2;
        y += b; b += 1;
    }
}

int main(){
    fastio();
    // int t;
    // cin>>t;
    // while(t--){
	//  	solve();
    // }
	solve();
    return 0;
}

/*
0 = 0 * 0
6 = 2 * 3
28 = 4 * 7 
96 = 8 * 12
252 = 14 * 18
550 = 22 * 25
1056 = 32 * 33
1848

*/

