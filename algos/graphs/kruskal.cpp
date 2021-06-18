/*
To form MST of a graph, pick edges with minimum lengths but skip edges that lead to formation of cycle
*/
#include<bits/stdc++.h>
using namespace std;

class disjointset{

    public: 

    int n;
    int* parent;
    int* rank; // Essentially tree balancing mechanism, to maintain uniformity among height of trees on union
    int setcount;

    disjointset(int n){
        this->n = n;
        setcount = n;
        parent = new int[n];
        rank = new int[n];
        for(int i=0;i<n;i++) parent[i] = i;
        for(int i=0;i<n;i++) rank[i] = i;
    }

    int find(int i){
        if(parent[i]==i){
            return i;
        }
        int result = find(parent[i]);
        parent[i] = result; //Memoization to efficiencize
        return result; 
        //Recursively look for the parent of i (that way we will know the root of the tree of the set i belongs to)
    }

    int getCount(){
        return setcount;
    }

    bool connected(int i, int j){
        return find(i)==find(j); //If both have same parent, they are connected
    }

    void merge(int i, int j){
        int iparent = find(i);
        int jparent = find(j);
        if(iparent == jparent){
            return; //Already in same group
        }
        int iprank = rank[iparent];
        int jprank = rank[jparent];

        if(iprank<jprank){
            parent[i] = jparent;
        }
        else if(iprank>jprank){
            parent[j] = iparent;
        }
        else{
            parent[j] = iparent;//Arbitrarily
            rank[iparent]++;
        }
        setcount--;
    }
};

// n = number of nodes in graph, graph is set of adjacency lists for the graph in form p<i,i> where first is index of node and second is weight
void kruskal(int n, vector<vector<pair<int,int>>> graph){
    disjointset* ds = new disjointset(n);
    vector<int> parent(n,-1);
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<n;i++){
        for(pair<int,int> p : graph[i]){
            edges.push_back({p.second, {i,p.first}});
        }
    }
    sort(edges.begin(), edges.end());
    int mstcount = 1;
    int mstlength = 0;
    int i = 0;
    while(mstcount<n && !edges.empty()){
        int wt = edges.front().first;
        int v1 = edges.front().second.first;
        int v2 = edges.front().second.second;
        edges.erase(edges.begin());
        int x = ds->find(v1), y = ds->find(v2);
        // cout<<x<<" "<<y<<endl;
        //Cyclic condition check
        if(x==y){
            continue;
        }
        else{
            cout << v1 << " - " << v2 << endl;
			mstlength += wt;
			ds->merge(v1, v2);
            mstcount++;
        }
    }
    cout<<"Total Length of MST = "<<mstlength<<endl;
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
    kruskal(n,graph);
    return 0;
}
