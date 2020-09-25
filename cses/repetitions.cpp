#include <iostream>
#include <string>
using namespace std;

int main(){
	string str;
	cin>>str;
	int ans = 1;
	int cur = 1;
	char c = str[0];
	int x = str.length();
	for(int i=1;i<x;i++){
		if(str[i]==c){
			cur+=1;
			if(cur>ans){
				ans = cur;
			}
		}
		else{
			cur = 1;
			c = str[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}