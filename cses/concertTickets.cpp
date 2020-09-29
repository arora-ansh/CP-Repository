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
	int n,m;
	cin>>n>>m;
	vector<integer>tickets[n];
	for(int i=0;i<n;i++){
		cin>>tickets[i];
		arr[i] = false;
	}
	int chindi[m];
	for(int i=0;i<m;i++){
		cin>>chindi[i];	
	}
	sort(tickets,tickets+n);
	//Accomodate for fact that once a ticket is sold, it can't be used it again
	for(int i=0;i<m;i++){
		int x = chindi[i];
		auto it = tickets.lower_bound(x);
		if(it==tickets.end()){
			cout<<-1<<endl;
		}
		else{
			cout<<*it<<endl;

		}
	}
	return 0;
}