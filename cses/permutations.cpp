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
	if(n<=3 && n>=2){
		cout<<"NO SOLUTION"<<endl;
	}
	else if(n==1){
		cout<<1<<endl;
	}
	else if(n==4){
		cout<<"2 4 1 3"<<endl;
	}
	else{
		for(int i=1;i<=n;i+=2){
			cout<<i<<" ";
		}
		for(int i=2;i<=n;i+=2){
			cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}