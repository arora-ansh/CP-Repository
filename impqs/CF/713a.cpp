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

void solve(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<int> arr2(arr);
	sort(arr2.begin(),arr2.end());
	for(int i=0;i<n;i++){
		if(arr[i]!=arr2[1]){
			cout<<i+1<<endl;
			break;
		}
	}
}

int main(){
    fastio();
    int n;
    cin>>n;
    while(n--){
		solve();
    }
    return 0;
}