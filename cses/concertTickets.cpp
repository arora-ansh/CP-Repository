#include <iostream>
#include <algorithm>
#include <vector>
typedef long long int ll ;
using namespace std;
inline void fastio(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
}

int main(){
	int n,m;
	cin>>n>>m;
	ll tickets[n], people[m];
	for(int i=0;i<n;i++){
		cin>>tickets[i];
	}
	for(int i=0;i<m;i++){
		cin>>people[i];
	}
	sort(tickets,tickets+n);
	//sort(people,people+m);
	int low = 0;
	int high = n-1;
	for(int i=0;i<m;i++){
		int ans = -1;
		low = last;
		ll curprice = people[i];
		while(low<=high){
			cout<<low<<" "<<high<<endl;
			int mid = (low+high)/2;
			if(tickets[mid]<=curprice){
				ans = tickets[mid];
				low = mid + 1;
			}
			else{
				high = mid - 1;
			}
		}
		cout<<ans<<endl;
		last = ans;
	}
	return 0;
}