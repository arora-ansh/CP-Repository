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

struct task{
    int time;
    int dl;
};

bool comp(struct task t1, struct task t2){
    return t1.time<t2.time;
}

int main(){
    fastio();
    int n;
    cin>>n;
    struct task arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].time>>arr[i].dl;
    }
    sort(arr,arr+n,comp);
    ll ftime = arr[0].time;
    ll ans = arr[0].dl-ftime;
    for(int i=1;i<n;i++){
        ftime+=arr[i].time;
        ans+=(arr[i].dl-ftime);
    }
    cout<<ans<<endl;
    return 0;
}

// TRY OUT EXCHANGE ARGUMENT FOR POC OF THIS