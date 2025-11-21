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
	int arr[n-1];
	for(int i=0;i<n-1;i++){
		cin>>arr[i];
	}
	sort(arr,arr+(n-1));
	bool x = false;
	for(int i=0;i<n-1;i++){
		if(arr[i]!=i+1){
			x = true;
			cout<<i+1<<endl;
			break;
		}
	}
	if(!x){
		cout<<n<<endl;
	}
	return 0;
}

// Faster method to do it using memory rather than time 
// #horizontal scaling lol

void solve(){
    cin>>n;
    vi arr(n);
    F(i, n-1) {
        int x; cin>>x; arr[x-1] = 1;
    }
    F(i,n) {
        if (arr[i] == 0) {
            cout<<(i+1);
            break;
        }
    }
}