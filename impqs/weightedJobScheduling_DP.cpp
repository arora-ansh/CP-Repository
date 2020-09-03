/*
In this problem, the greedy part was to arrange the arrays based on their end times.
After this, we iterate over the array, wherein we store the best case till that particular point
On each case, we can either 1) not select an element and carry on with the max result found in prev case or 2) select the element and find the max case in from the previous elements stored in the DP array where the end time<=start time of present case
This can be optimized by using binary search, thus letting us solve the q in O(nlogn)
*/
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
