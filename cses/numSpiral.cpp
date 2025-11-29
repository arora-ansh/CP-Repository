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
    ll y, x;
    cin>>y>>x;
    ll maxCase = max(y,x);
    ll ans = 0;
    if (maxCase%2 == 1) {
        // Odd Case
        if (y >= x) {
            ans = ((maxCase - 1) * (maxCase - 1));
            ans += x;
        }
        else {
            ans = (maxCase * maxCase);
            ans += (1 - y);
        }
    }
    else {
        // Even Case
        if (y <= x) {
            ans = ((maxCase - 1) * (maxCase - 1));
            ans += y;
        }
        else {
            ans = (maxCase * maxCase);
            ans += (1 - x);
        }
    }
    cout<<ans<<endl;
}

int main(){
    fastio();
    int t;
    cin>>t;
    while(t--){
	 	solve();
    }
	//solve();
    return 0;
}

/*
2, 3 -> 8

we will find max of row, col -> this will give us spiral level we are at 

In case of (2,3) -> 3
We will start calc at 2**2

For odd max cases, if row index > col index -> number will be smaller
For even max cases (Ex 4), if row index < col index -> number will be smaller

Now lets look at spiral number 3 
Odd 
3,1 will be smallest -> 5
3,2 -> 6
3,3 -> 7
2,3 -> 8
1,3 -> 9

Lets try boiling it to formula of form (maxCase ** 2) + F(y,x) (y = row, x = col)

Odd cases -> 

5,1 -> 17
5,5 -> 21
2,5 -> 24
1,5 -> 25

Even case ->

1, 4 -> 10
2, 4 -> 11
3, 4 -> 12
4, 4 -> 13 

*/