#include<iostream>
#include<cmath>
using namespace std;

//Normal loop method -> O(n^3/2)
bool checkPrime(int x){
    int count = 0;
    int up = sqrt(x);
    //cout<<up<<endl;
    for(int i=1;i<=up;i++){
        if(x%i==0){
            if(i*i==x){
                count+=1;
            }
            else{
                count+=2;
            }
        }
    }
    //cout<<x<<" "<<count<<endl;
    if(count==2){
        return true;
    }
    else{
        return false;
    }
}

//Sieve of Eratosthenes method -> O(n*log(log(n)))
int sieve(int n){
    bool prime[n+1];
    for(int i=0;i<=n;i++){
        prime[i] = true;
    }
    for(int i=2;i*i<=n;i++){
        if(prime[i]==true){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=false;
            }
        }
    }
    int count = 0;
    for(int i=2;i<=n;i++){
        if(prime[i]){
            //cout<<i<<endl;
            count++;
        }
    }
    return count;
}

int main(){
	int n;
    cin>>n;
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(checkPrime(i)){
            ans++;
        }
    }
    cout<<ans<<endl;
	return 0;
}