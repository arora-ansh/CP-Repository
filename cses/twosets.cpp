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

void vecPusher(vi& arr, int x, int y) {
    arr.push_back(x); arr.push_back(y);
}

void vecPrinter(vi& arr) {
    cout<<arr.size()<<endl;
    for(auto x : arr) cout<<x<<" ";
    cout<<endl;
}

void solve(){
    cin>>n;
    vi arr1, arr2;
    if (n%4 == 1 || n%4 == 2) {
        cout<<"NO"; return;
    }
    else if (n%4 == 3) {
        arr1.push_back(1); arr1.push_back(2); arr2.push_back(3);
        for(int i = 4; i <= 3 + (n-3)/2; i++) {
            vecPusher( (i%2==0) ? arr1 : arr2, i, n-i+4);
        }
    }
    else {
        for(int i = 1; i <= n/2; i++) {
            vecPusher( (i%2==1) ? arr1 : arr2, i, n-i+1);
        }
    }
    cout<<"YES"<<endl;
    vecPrinter(arr1);
    vecPrinter(arr2);
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
Divide in 2 sets - 

1 - No lol
2 - No
3 - 1,2 and 3
4,8,12, .... multiples of 4 - Yes (1,x; 2, x-1; and so on)
5 - No (sum is odd)
6 - No (sum is odd)
7 - Yes (3,4,7 and 1,2,5,6)
8 - Yes
9 - No
10 - No
11 - 7 groups and (8,11) and (9,10)
12 - Yes
...

So - 
Multiples of 4 - yes (1,x), (2,x-1), ...
%4 == 3 - yes - Groups of 3 and then Multiples of 4 logic on remaining numbers 
*/

