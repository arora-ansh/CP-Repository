#include <iostream>
#include <algorithm>
typedef long long int ll ;
using namespace std;
inline void fastio(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
}

struct num{
	int num1;
	int pos;
};

bool compare(num n1, num n2){
	return(n1.num1<n2.num1);
}

int main(){
	int n,x;
	cin>>n>>x;
	struct num arr[n];
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		arr[i].num1 = temp;
		arr[i].pos = i;
	}
	sort(arr,arr+n,compare);
	bool ifans = false;
	for(int i=0;i<n;i++){
		int a = arr[i].num1;
		int b = x - a;
		int start = i+1;
		int end = n-1;
		int ans = -1;
		while(start<=end){
			int mid = (start+end)/2;
			if(arr[mid].num1==b){
				ans = arr[mid].pos;
				break;
			}
			else if(arr[mid].num1<b){
				start = mid+1;
			}
			else{
				end = mid-1;
			}
		}
		if(ans>-1){
			cout<<arr[i].pos+1<<" "<<ans+1<<endl;
			ifans = true;
			break;
		}
	}
	if(!ifans){
		cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}