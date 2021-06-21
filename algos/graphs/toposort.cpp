/*
    Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, 
    vertex u comes before v in the ordering.
*/

#include<bits/stdc++.h>
using namespace std;

void topoSortHelper(int u, vector<bool>& visited, stack<int>& s, vector<vector<int>> graph){
    visited[u] = true;
    for(int v : graph[u]){
        if(!visited[v]){
            topoSortHelper(v,visited,s,graph);
        }
    }
    s.push(u);
}

void topoSort(int n, vector<vector<int>> graph){
    stack<int> s;
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            topoSortHelper(i,visited,s,graph);
        }
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\n";
}

/*
    A better approach to solving this is using the concept of indegrees and outdegrees - 
    Indegree = # of edges coming into a node
    First node in the topo sort will ofcourse be a node with indegree 0. If none such exist, there is a deadlock case
    Algorithm - 
    1. Initialize a queue, Q to keep a track of all the nodes in the graph with 0 in-degree.
    2. Iterate over all the edges in the input and create an adjacency list and also a map of node v/s in-degree.
    3. Add all the nodes with 0 in-degree to Q.
    4. The following steps are to be done until the Q becomes empty.
        a. Pop a node from the Q. Let's call this node, N.
        b. For all the neighbors of this node, N, reduce their in-degree by 1. If any of the nodes' in-degree reaches 0, add it to the Q.
        c. Add the node N to the list maintaining topologically sorted order.
        d. Continue from step 4.a.
*/

vector<int> findOrder(int n, vector<vector<int>>& prereqs) { //Returns empty array if no TopoOrder possible
    vector<vector<int>> graph(n);
    vector<int> indegree(n,0);
    for(auto v : prereqs){
        graph[v[0]].push_back(v[1]);
        indegree[v[1]]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){ //These points can act as potential starting points and thus will appear first
            q.push(i);
        }
    }
    if(q.empty()) return {}; //If no starting point for topo order, no possible solution
    vector<int> topoOrder;
    while(!q.empty()){
        int u = q.front(); q.pop();
        topoOrder.push_back(u);
        for(int v : graph[u]){//We decrease the indegree of each adjacent node to u by 1
            //Consider this to be that to do course v, we will now have to do 1 lesser prereq (u)
            indegree[v]--;
            //If the neigbor reaches an indegree of 0, they are ready to go onto the topo order
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }
    if(topoOrder.size()==n){ 
        //If all the nodes have been added to topoorder, this means that deadlock case wasnt found, and thus we can return the final topoorder.
        return topoOrder;
    }
    return {};
}

void addEdge(vector<vector<int>>& graph, int u, int v){
    graph[u].push_back(v);
}

int main(){
    int n = 10;
    vector<vector<int>> graph(n);
    addEdge(graph,0,2);
    addEdge(graph,0,3);
    addEdge(graph,1,3);
    addEdge(graph,1,5);
    addEdge(graph,2,9);
    addEdge(graph,3,9);
    addEdge(graph,3,7);
    addEdge(graph,4,7);
    addEdge(graph,5,8);
    topoSort(n,graph);
    return 0;
}