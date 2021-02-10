#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool comp(pair<int,bool> p1, pair<int,bool> p2){
    return p1.first<p2.first;
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,bool> > arr;
    for(int i=0;i<n;i++){
        int temp1,temp2;
        cin>>temp1>>temp2;
        arr.push_back(make_pair(temp1,true));//true is start time
        arr.push_back(make_pair(temp2,false));//false is end time
    }
    sort(arr.begin(),arr.end());
    int cur = 0, ans = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i].second){
            cur+=1;
        }
        else{
            cur-=1;
        }
        ans = max(cur,ans);
    }
    cout<<ans<<endl;
    return 0;
}