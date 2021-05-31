#include <iostream>

int gcd(int a,int b)
{
    //cout<<a<<" "<<b<<endl;
	if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
    return 0;
}