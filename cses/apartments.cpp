#include <iostream>
#include <algorithm>
typedef long long int ll ;
using namespace std;
inline void fastio(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
}

struct wants{
	ll low;
	ll high;
};

bool compare(wants w1, wants w2){
	return(w1.low<w2.low);
}

int main(){
	int n,m;
	ll k;
	cin>>n>>m>>k;
	struct wants arr[n];
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		arr[i].low = x-k;
		arr[i].high = x+k;
	}
	ll flats[m];
	for(int i=0;i<m;i++){
		cin>>flats[i];
	}
	sort(flats,flats+m);
	sort(arr,arr+n,compare);
	int ans=0;
	int j=0;
	int i=0;
	/*
	for(int i=0;i<n;i++){
		if(ans>=m || j>=m){
			break;
		}
		cout<<arr[i].low<<" "<<arr[i].high<<" "<<flats[j]<<endl;
		if(arr[i].low<=flats[j] && arr[i].high>=flats[j]){
			
			ans+=1;
			j+=1;
		}
		else if(arr[i].low>flats[j]){
			j+=1;
		}
		else if(arr[i].high<flats[j]){
			continue;
		}
	}
	*/
	while(i<n && j<m && ans<m){
		//cout<<arr[i].low<<" "<<arr[i].high<<" "<<flats[j]<<endl;
		if(arr[i].low<=flats[j] && arr[i].high>=flats[j]){
			i+=1;
			ans+=1;
			j+=1;
		}
		else if(arr[i].low>flats[j]){
			j+=1;
		}
		else if(arr[i].high<flats[j]){
			i+=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}