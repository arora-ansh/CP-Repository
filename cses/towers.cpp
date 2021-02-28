#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <queue> 
#include <string.h>
#include <string>
using namespace std;
#define MOD 1000000007

inline void fastio(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
}

typedef long long int ll;
typedef long double ld;

int main(){
    fastio();
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> towers;
    towers.push_back(arr[0]);
    for(int i=1;i<n;i++){
        int low = 0;
        int end = towers.size()-1;
        int ans = -1;
        while(low<=end){
            int mid = (low+end)/2;
            if(towers[mid]>arr[i]){
                ans = mid;
                end = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        //cout<<arr[i]<<" "<<ans<<endl;
        if(ans!=-1){
            towers[ans] = arr[i];
        }
        else{
            towers.push_back(arr[i]);
        }
    }
    cout<<towers.size()<<endl;
    return 0;
}


