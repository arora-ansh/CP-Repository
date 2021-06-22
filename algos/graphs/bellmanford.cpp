/*
    Solves the huge af problem of negative edges issue faced by dijkstra, though in O(VE), whereas dijkstra if 
    done properly can give you succesful results in VlogV. Sus.
*/

int bellmanford(int n, vector<vector<pair<int,int>>> graph, int start, int end){
    vector<int> distance(n,INT_MAX);
    distance[start] = 0;
    for(int i)
}