#include <iostream>
#include <list>
using namespace std;

void bfs(int **edges, int n, int start, bool *visited){
	list<int> queue; //We maintain a queue
	visited[start] = true;
	queue.push_back(start);

	while(!queue.empty()){
		int x = queue.front();
		cout<<x<<endl;
		queue.pop_front();
		for(int i=0;i<n;i++){
			if(x==i){
				continue;
			}
			if(edges[x][i]==1 && !visited[i]){
				visited[i] = true;
				queue.push_back(i);
			}
		}
	}
}

//Note for BFS/DFS on unconnected graph, just iterate over the visited array to check whether there is some island that might be still left to visit

void dfs(int **edges, int n, int start, bool *visited){//Start is starting vertex of that particular iteration
	cout<<start<<endl;
	visited[start] = true;
	for(int i=0;i<n;i++){
		if(i==start){
			continue;
		}
		if(edges[start][i]==1 && !visited[i]){
			dfs(edges,n,i,visited);
		}
	}
}

int main(){
	int n, e;
	cin>>n>>e;
	int **edges = new int*[n];
	for(int i=0;i<n;i++){
		edges[i] = new int[n];
		for(int j=0;j<n;j++){
			edges[i][j]=0;
		}
	}
	for(int i=0;i<e;i++){
		int v1, v2;
		cin>>v1>>v2;
		edges[v1][v2]=1;
		edges[v2][v1]=1;
	}
	bool *visited = new bool[n];
	for(int i=0;i<n;i++){
		visited[i] = false;
	}
	bfs(edges,n,0,visited);
	delete [] visited;
	for(int i=0;i<n;i++){
		delete [] edges[i];
	}
	delete [] edges;
	return 0;
}