// Dijkstra algortithm to find out shortest path in O(E + VlogV)
/*
I am getting lazy and will make my notes here itself. Shockingly enough, makes for easier reading as well *_* who knew.
SSSP Algos - 
Given G = (V, E), w and a source vertex S, find ∂(S, V) [the best path] from S to each v ∈ V, where ∂ is the shortest path connecting the two.

Note - Dijkstra doesn't do negative edges, you're better off with Belmman Ford if you're the kind. 


*/
#include<bits/stdc++.h>
using namespace std;

int dijsktra(int n, vector<vector<pair<int,int>>> graph, int start, int end){
    vector<int> distance(n,INT_MAX);
    vector<int> parent(n,-1);
    distance[start] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //FIRST IS WEIGHT SECOND IS NODE# NOT OPPOSITE FFS
    pq.push({0,start});
    while(!pq.empty()){
        int u = pq.top().second; pq.pop();
        for(auto node : graph[u]){
            int v = node.first;
            int wt = node.second;
            if(distance[v]>distance[u]+wt){
                distance[v] = distance[u]+wt;
                pq.push({distance[v],v});
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
    return distance[end];
}

int main(){
    int n = 4;
    vector<vector<pair<int,int>>> g(n);
    g[2].push_back({1,1});
    g[3].push_back({4,1});
    g[2].push_back({3,1});
    dijsktra(n,g,2,0);
    return 0;
}