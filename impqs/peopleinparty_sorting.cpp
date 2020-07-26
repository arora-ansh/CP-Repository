/* Most people in a party at a single time problem 

Sample Input 1 :
5
900 1000 1100 1030 1600
1900 1300 1130 1130 1800
Sample Output 1:
4

*/

#include<bits/stdc++.h>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int n;
    cin>>n;
    int in[n],out[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>out[i];
    }
    sort(in,in+n);
    sort(out,out+n);
    int cur = 1, max = 1, count = in[0];
    int i = 1, j =0;
    while(i<n && j<n){
        if(in[i]<=out[j]){
            cur+=1;
            if(cur>max){
                max=cur;
                count = in[i];
            }
            i+=1;
        }
        else{
            cur-=1;
            j+=1;
        }
    }
    cout<<max<<endl;
   
}