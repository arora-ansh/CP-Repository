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
#define ar array
using namespace std;
const int mxN =1e3+2;
const int di[4]={1,0,-1,0},dj[4]={0,1,0,-1};
const char dc[4]={'D','R','U','L'} ;
int n,m,si,sj,ti,tj,d[mxN][mxN];
string s[mxN],p[mxN] ;
bool e(int i,int j){
  return (i<n&&i>=0&&j<m&&j>=0&&s[i][j]=='.') ;
}
signed main() {
  cin >> n >> m ;
  for(int i=0;i<n;i++)
    cin >> s[i] ; 
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(s[i][j]=='A')
        si=i,sj=j,s[i][j]='.';
      if(s[i][j]=='B')
        ti=i,tj=j,s[i][j]='.';
    }
    p[i]=string(m,0) ;
  }
  queue<ar<int,2> > qu ;
  qu.push({si,sj}) ;
  while(!qu.empty()){
    ar<int,2>u = qu.front();
    qu.pop() ;
    for(int k=0;k<4;k++){
      int ni=u[0]+di[k],nj=u[1]+dj[k];
      if(!e(ni,nj))
        continue ;
      qu.push({ni,nj});
      s[ni][nj]='#';
      d[ni][nj]=k ;
      p[ni][nj]=dc[k] ;
    }
  }
  if(p[ti][tj]){
    string t ;
    cout << "YES"<< endl ;
    while(si^ti || sj^tj){
      t+=p[ti][tj] ;
      int dd=d[ti][tj]^2;
      ti+=di[dd];
      tj+=dj[dd];
    }
    reverse(t.begin(),t.end());
    cout << t.size() <<"\n";
    cout << t ;
  }
  else
    cout << "NO";
}