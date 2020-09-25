#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

int main(){
	int n;
	ll x;
	cin>>n>>x;
	ll arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}	
	sort(arr,arr+n);
	ll ans = 0;
	int i=0;
	int j=n-1;
	while(i<=j){
		if(i==j){
			ans+=1;
			break;
		}
		else if(arr[i]+arr[j]<=x){
			i+=1;
			j-=1;
			ans+=1;
		}
		else{
			ans+=1;
			j-=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}