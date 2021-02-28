#include <iostream>
using namespace std;

struct times{
    int start,end;
};

int main(){
    int n;
    cin>>n;
    struct times arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].start>>arr[i].end;
    }
    
    return 0;
}