#include<iostream>

class disjointset{
    int n;
    int* parent;
    int* rank; // Essentially tree balancing mechanism, to maintain uniformity among height of trees on union
    int setcount;

    disjointset(int n){
        this.n = n;
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

    void union(int i, int j){
        int iparent = find(i);
        int jparent = find(j);
        if(iparent == jparent){
            return; //Already in same group
        }
        iprank = rank[iparent];
        jprank = rank[jparent];

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
}
