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

int lengthOfLongestSubstring(vi s) {
    map<int,int> curmap;
    int curmax = 0;
    int ans = 0;
    int n = s.size();
    for(int i=0;i<n;i++){ 
        if(curmap.find(s[i])==curmap.end()){ //If the character doesn't already occur, then simply means hasn't occurred in the current substring either
            curmap[s[i]] = i+1;
            curmax++;
            if(curmax>ans){
                ans = curmax;
            }
        }
        else{//Then may or may not belong to current substring
            if((i+1)-curmap.find(s[i])->second > curmax){//This is for the case where the particular alphabet that repeats belongs before the starting point of current substring
                curmax++;
            }
            else{//If the character has occurred before in the substring being checked rn
                curmax = (i+1) - curmap.find(s[i])->second;
            }
            curmap[s[i]] = i+1;
            if(curmax>ans){
                ans = curmax;
            }
        }
    }
    return ans;
}

void solve(){
	cin>>n;
    vi s;
    F(i,n){ 
        int temp;
        cin>>temp;
        s.push_back(temp);
    }
    cout<<lengthOfLongestSubstring(s)<<endl;
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
