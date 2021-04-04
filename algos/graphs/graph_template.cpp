#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class Graph{
    public:
        int v;          //Number of vertices
        list<int> *l;   //Adjaceny Lists for each vertex, array of adjaceny lists being maintained
        unordered_map<int, bool> visited;   // For DFS

        Graph(int x){
            v = x;
            l = new list<int>[v];
        }
        
        void addEdge(int u, int v, bool bi = true){ //In case of non-bidirection, direction is u->v
            l[u].push_back(v);
            if(bi){
                l[v].push_back(u);
            }
        }

        void printAdjLists(){
            for(int i=0;i<v;i++){
                cout<<i<<" -> ";
                for(int x : l[i]){
                    cout<<x<<" ";
                }
                cout<<endl;
            }
        }

        void BFS(int s){ //s is starting node
            bool *visited = new bool[v];
            for(int i=0;i<v;i++){
                visited[i] = false;
            }
            list<int> queue;
            visited[s] = true;
            queue.push_back(s);
            while(!queue.empty()){
                s = queue.front();
                cout<<s<<" ";
                queue.pop_front();
                for(int x : l[s]){
                    if(!visited[x]){
                        visited[x] = true;
                        queue.push_back(x);
                    }
                }
            }
        }

        void DFS(int s){ //s is starting node
            visited[s] = true;
            cout<<s<<" ";
            for(int x : l[s]){
                if(!visited[x]){
                    DFS(x);
                }
            }
        }
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,3);
    g.printAdjLists();
    g.BFS(0);
    cout<<endl;
    g.DFS(0);
    cout<<endl;
    return 0;
}