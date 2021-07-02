// Cycle Checking using Graph coloring -> Works for DCGs and UCGs both

bool cycle(vector<int> adj[], vector<int>& color, int u){
    if(color[u]==1) return true;
    if(color[u]==0){
        color[u] = 1;
        for(int v : adj[u]){
            if(cycle(adj,color,v)) return true;
        }
    }
    color[u] = 2;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<int> color(V,0);
    for(int i=0;i<V;i++){
        if(color[i]==0){
            if(cycle(adj,color,i)) return true;
        }
    }
    return false;
}

//Check if graph is Bipartite (using coloring)
bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(graph.size(),0);
        vector<int> visited(graph.size(),false);
        for(int root=0;root<n;root++){
            if(!visited[root]){
                queue<int> q;
                q.push(root);
                color[root] = 1;
                while(!q.empty()){
                    int x = q.front(); q.pop();
                    if(visited[x]) continue;
                    visited[x] = true;
                    for(int i : graph[x]){
                        if(color[i]==color[x]){
                            return false; //If neighbor has same color, this means that tree condition is dissatisfied
                        }
                        if(!color[i]){
                            color[i] = (color[x]==1) ? 2 : 1;
                            q.push(i); //Assign neighbors the opposite color to check for tree condition
                        }
                    }
                }
            }
        }
        return true;
    }

//Finding a Graph's Sink
int findJudge(int n, vector<vector<int>>& trust) {
    vector<vector<int>> graph(n,vector<int>(n,0));
    for(vector<int> v : trust){
        graph[v[0]-1][v[1]-1] = 1;
    }
    int i=0, j=0;
    while(i<n && j<n){
        if(graph[i][j]){
            i+=1;
        }
        else{
            j+=1;
        }
    }
    if(i<n){
        bool sink = true;
        for(int a=0;a<n;a++){
            if(graph[i][a]) sink = false;
            if(i==a){
                continue;
            }
            if(!graph[a][i]) sink = false;
        }
        if(sink){
            return i+1;
        }
    }
    return -1;
}