#include <iostream>
#include <algorithm>
#define MOD 1000000007
typedef long long int ll ;
using namespace std;
inline void fastio(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
}

int main(){
	int n;
	cin>>n;
	ll ans = 1;
	for(int i=0;i<n;i++){
		ans = ((ans%MOD)*(2%MOD))%MOD;
	}
	cout<<ans<<endl;
	return 0;
}
