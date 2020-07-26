/* ULIMATE
ALGORITHM
AND
PROBLEM
COMPILATION */

//MERGE SORT

void merge(int *arr,int start,int end,int mid){
    int s1 = mid-start+1;
    int s2 = end - mid;
    int arr1[s1];
    int arr2[s2];
    for(int i=0;i<s1;i++){
        arr1[i]=arr[start+i];
    }
    for(int i=0;i<s2;i++){
        arr2[i]=arr[mid+1+i];
    }
    int i = 0, j = 0, k = start;
    while(i<s1 && j<s2){
        if(arr1[i]<=arr2[j]){
            arr[k]=arr1[i];
            i+=1;
            k+=1;
        }
        else{
            arr[k]=arr2[j];
            j+=1;
            k+=1;
        }
    }
    if(i<s1){
        while(i<s1){
            arr[k]=arr1[i];
            i+=1;
            k+=1;
        }
    }
    else if(j<s2){
        while(j<s2){
            arr[k]=arr2[j];
            j+=1;
            k+=1;
        }
    }
    
}

void sort(int *arr,int start,int end){
    if(start<end){
        int mid = (start+end)/2;
        sort(arr,start,mid);
        sort(arr,mid+1,end);
        merge(arr,start,end,mid);
    }
}

//QUICK SORT

int partition(int *arr,int start,int end){
    int x = arr[end];
    int j = start-1;
    for(int i = start; i<=(end-1);i++){
        if(arr[i]<x){
            j+=1;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int t = arr[end];
    arr[end] = arr[j+1];
    arr[j+1] = t;
    return(j+1);
    
}

void sort(int *arr,int start,int end){
    if(start>=end){
        return;
    }
    else{
        int c = partition(arr,start,end);
        sort(arr,start,c-1);
        sort(arr,c+1,end);
    }
}

// SPLIT FUNCTION IN C++

	string wordlist;
    cin>>wordlist;
    vector<string> words;
    int cur = -1;
    while(wordlist.find(";",cur+1)!=string::npos){
        int x = wordlist.find(";",cur+1);
        int w = cur+1;
        cout<<w<<" "<<x<<endl;
        words.push_back(wordlist.substr(w,(x-w)));
        cur = x;
    }
    int x = wordlist.find(";",cur+1);
    int w = cur+1;
    cout<<w<<" "<<x<<endl;
    words.push_back(wordlist.substr(w,(x-w)));
    cur = x;
    for(int i=0;i<words.size();i++){
        cout<<words[i]<<endl;
    }

//