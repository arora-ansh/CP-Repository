//Kadane's Algorithm for finding max sum possible from contiguous arrays
//DP used, since we store the value as it is being calculated and use it for our purpose
#include <iostream>
using namespace std;

int main(){
	int arr[8] = {-2,-3,4,-1,-2,1,-2,5,-3};
	int global_max = 0;
	int curmax = 0;
	for(int i=0;i<9;i++){
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
