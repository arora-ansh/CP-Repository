#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
//array ka har element ko include/exclude karke nikaalna hai values.
//DP Problem hi hai lol
struct jobs{
    int start;
    int end;
    int profit;
    int mx;
};

bool comparator(struct jobs j1, struct jobs j2){
	return(j1.end<j2.end);    
}

int main()
{
    int n;
    cin>>n;
    struct jobs arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].start>>arr[i].end>>arr[i].profit;
    }
    sort(arr,arr+n,comparator);
    arr[0].mx = arr[0].profit;
    for(int i=1;i<n;i++){
        arr[i].mx = arr[i-1].mx;
        if(arr[i].mx<arr[i].profit){
            arr[i].mx=arr[i].profit;
        }
            //Rather than poora loop, use binary search
        int start = 0;
        int end = i-1;
        bool found = false;
        int x = arr[0].mx;
        while(start<=end){
            int mid = (start+end)/2;
        	if(arr[mid].end<=arr[i].start){
        		x = arr[mid].mx;
                found = true;
        		start = mid+1;
        	}
       		else{
            	end = mid - 1;
        	}
    	}
        if(found){
        	arr[i].mx = max(arr[i].mx,x+arr[i].profit);
        }
            /*
            if(arr[j].end<=arr[i].start){
                arr[i].mx = max(arr[i].mx,arr[j].mx+arr[i].profit);
                break;
            }
            */
    }
    //for(int i=0;i<n;i++) cout<<arr[i].mx<<" ";
    //cout<<endl;
    cout<<arr[n-1].mx<<endl;
    return 0;
}
