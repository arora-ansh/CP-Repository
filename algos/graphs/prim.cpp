#include<bits/stdc++.h>
using namespace std;

// n = number of nodes in graph, graph is set of adjaceny lists for the graph in form p<i,i> where first is index of node and second is weight
void MST(int n, vector<vector<pair<int,int>>> graph){
    vector<bool> mst(n,false); //Set for vertices that have already been included in the MST, can also use bool vector
    vector<int> key(n,INT_MAX);
    vector<int> parent(n,-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //first will store weight, second will store node #
    key[0] = 0; //Starting node value set to 0
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        int u = pq.top().second; pq.pop();
        if(mst[u]) continue;
        cout<<u<<endl;
        mst[u] = true;
        for(auto node : graph[u]){
            int v = node.first;
            int wt = node.second;
            if(!mst[v] && wt<key[v]){
                key[v] = wt;
                pq.push(make_pair(wt,v));
                parent[v] = u;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(parent[i] == -1){
            cout<<" -> "<<i<<endl; continue;
        }
        cout<<parent[i]<<" -> "<<i<<endl;
    }
}

int main(){
    int n = 5;
    vector<vector<pair<int,int>>> graph(n,vector<pair<int,int>>());
    graph[0].push_back(make_pair(1,3));
    graph[0].push_back(make_pair(2,8));
    graph[0].push_back(make_pair(4,5));
    graph[1].push_back(make_pair(3,4));
    graph[2].push_back(make_pair(0,3));
    graph[2].push_back(make_pair(2,6));
    graph[2].push_back(make_pair(4,6));
    graph[3].push_back(make_pair(4,5));
    graph[3].push_back(make_pair(2,3));
    graph[4].push_back(make_pair(1,7));
    graph[4].push_back(make_pair(2,3));
    MST(n,graph);
    return 0;
}