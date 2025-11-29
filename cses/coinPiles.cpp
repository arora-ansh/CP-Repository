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
    cin>>m>>n;
    if ((m+n)%3 != 0) {
        cout << "NO" << endl;
        return;
    }
    if ((2*m - n) % 3 == 0 && (2*n - m) % 3 == 0 
        && (2*m - n)*(2*n - m) >= 0) 
            cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    fastio();
    int t;
    cin>>t;
    while(t--){
	 	solve();
    }
	// solve();
    return 0;
}

/*
Each time either 2 from P1 and 1 from P2 (M1) or 1 from P1 and 2 from P2 (M2)- 

Lets say can take out x times by M1 and y times by M2

then my numbers m and n should be 

m = 2x + y
n = x + 2y

For this equation to have real solutions, x and y should be solvable for whole numbers

(m+n) = 3x + 3y
(m+n)/3 = x + y

Thus m+n should be divisible by 3

Now, x + y should still have real solutions 

Ex - 0, 9 will have complex solutions

For eqns - a1x + b1y = c1, a2x + b2y = c2 
    where a1 = 2, b1 = 1, c1 = m; a2 = 1, b2 = 2, c2 = n
D = a1*b2 - a2*b1 = 4 - 1 = 3
Dx = c1*b2 - c2*b1 = 2m - n
Dy = c2*a1 - c1*a2 = 2n - m

Both Dx % D == 0 and Dy % D == 0 should satisfy

*/

