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
	while(n!=1){
		if(n%2==0){
			cout<<n<<" ";
			n/=2;
		}
		else{
			cout<<n<<" ";
			n = 3*n + 1;
		}
	}
	cout<<n<<endl;
	return 0;
}