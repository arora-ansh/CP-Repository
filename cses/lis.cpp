#include <bits/stdc++.h>
using namespace std;

//7 3 5 3 6 2 9 8
/*
7
3
3 5
3 5
3 5 6
2 5 6
2 5 6 9
2 5 6 8
*/

int main() {
  int n;
  cin >> n;
  vector<int> dp;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    auto it = lower_bound(dp.begin(), dp.end(), x);
    if (it == dp.end()) {
      dp.push_back(x);
    } else {
      *it = x;
    }
  }
  for(int i : dp) cout<<i<<" ";
  cout<<endl;
  cout << dp.size() << endl;
}