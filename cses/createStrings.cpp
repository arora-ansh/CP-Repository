#include <iostream>
#include <algorithm>
#include <string>
typedef long long int ll ;
using namespace std;
inline void fastio(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
}

int factorial(int n) { 
    return (n==1 || n==0)?1: n * factorial(n - 1);  
}

int main(){
	String str;
	cin>>str;
	int n = str.size();
	char *arr = new char[n];
	for(int i=0;i<n;i++){
		arr[i]=str[i];
	}
	sort(arr,arr+n);
	int ans = factorial(n);
	int cur = 1;
	for(int i=1;i<n;i++){
		if(arr[i]!=arr[i-1]){
			ans = ans/factorial(cur);
			cur = 1;
		}
		else{
			cur+=1;
		}
	}
	cout<<ans<<endl;
	//Create Program to permute through all possible perrmutations
	return 0;
}