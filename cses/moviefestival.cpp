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

struct movie{
    int start;
    int end;
};

bool comp(struct movie m1, struct movie m2){
    return m1.end<m2.end;
}

int main(){
    fastio();
    int n;
    cin>>n;
    struct movie arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].start>>arr[i].end;
    }
    sort(arr,arr+n,comp);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i].start<<" "<<arr[i].end<<endl;
    // }
    int ans = 1;
    int cur = arr[0].end;
    for(int i=1;i<n;i++){
        if(arr[i].start>=cur){
            ans++;
            cur = arr[i].end;
        }
    }
    cout<<ans<<endl;
    return 0;
}


