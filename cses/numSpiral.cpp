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
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		ll row,col;
		cin>>row>>col;
		ll x = max(row,col);
		ll ans = 0;
		if(x%2==0){
			//x is even
			if(row>col){
				ans = (x*x)+1-col;
			}
			else{
				ans = ((x-1)*(x-1))+row;
			}
		}
		else{
			//x is odd
			if(row>col){
				ans = ((x-1)*(x-1))+col;
			}
			else{
				ans = (x*x)+1-row;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}