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
    string s;
    cin>>s;
    unordered_map<char, int> m;
    for (auto ch : s) {
        if (m.find(ch) != m.end()) m[ch]++;
        else m[ch] = 1;
    }
    int oddCharCount = 0;
    char oddChar = '\0';
    for (auto it : m) {
        if (it.second % 2 == 1) { 
            oddCharCount++;
            oddChar = it.first;
        }
        if (oddCharCount > 1) { 
            cout<<"NO SOLUTION"<<endl;
            return;
        }
    }
    int frontCounter = 0;
    int backCounter = s.size();
    string ans(s.size(), ' ');
    for (auto it : m) {
        char ch = it.first;
        int count = it.second;
        if (ch != oddChar) {
            for (int i = 0; i<count; i+=2) {
                ans[frontCounter] = ch; ans[backCounter-1] = ch;
                frontCounter++; backCounter--;
            }
        }
    }
    if(oddCharCount){
        for(int i=0;i<m[oddChar];i++) {
            ans[frontCounter] = oddChar;
            frontCounter++;
        }
    }
    cout<<ans<<endl;
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
