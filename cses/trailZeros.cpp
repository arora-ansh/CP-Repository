#include <iostream>
#include <algorithm>
typedef long long int ll ;
using namespace std;
inline void fastio(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
}

int main(){
	ll n;
	cin>>n;
	ll ans = 0;
	ll div = 5;
	while(div<=n){
		ans+=(n/div);
		div*=5;
	}
	cout<<ans<<endl;
	return 0;
}