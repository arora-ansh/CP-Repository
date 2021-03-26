#include <iostream>
#include <list>
using namespace std;

class Graph{
    public:
        int v;
        list<int> *l;   //Adjaceny Lists for each vertex, array of adjaceny lists being maintained

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
    return 0;
}