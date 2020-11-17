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
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	ll global_max = -1000000000;
	ll curmax = 0;
	for(int i=0;i<n;i++){
		curmax = curmax + arr[i];
		if(curmax>global_max){
			global_max = curmax;
		}
		if(curmax<0){
			curmax = 0;
		}
	}
	cout<<global_max<<endl;
	return 0;
}