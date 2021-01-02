/*
In heaps,
Insertion - O(logn)
Deletion - O(logn)
Min/Max Element - O(1)
Useful where the min/max element needs to be found out multiple times

It is basically a tree like data structure where value stored in a node < value stored in each of its children
Operations - 
• CreateHeap(H) : Create an empty heap H.
• Insert(x,H) : Insert a new key with value x into the heap H.
• Extract-min(H) : delete the smallest key from H.
• Decrease-key(p, ∆, H) : decrease the value of the key p by amount ∆.
• Merge(H1,H2) : Merge two heaps H1 and H2.

Here we will implement a binary tree using an array. A complete binary tree can be implemented in such a manner.
Zero index - 
- Index of Left Child = 2*i+1
- Index of Right Child = 2*i+2
- Index of Parent = Floor of (i-1)/2

A binary heap is one where the heap can be redrawn into a complete binary tree.
Egs - H 4 14 9 17 23 21 29 91 37 25 88 33

Variables maintained -
H[] - Array for the Heap
Size - Size of Heap Array

*/

#include <iostream>
using namespace std;

int Heap[];
int size;

int find_min(int H[]){
    return H[0];
}

// In this we will have to return min value and also remove it from the heap. Done in O(logn) time
int extract_min(int H[]){
    int x = H[0];
    H[0] = H[size-1];
    H[size-1] = x;
    size--;
    heapify(0,H);
    return x;
}

//Here x has to be inserted into the tree. First, insert the node into the last position and then keep switching it with its parent 
//until its larger than the parent.
void insert(int H[], int x){
    int i = size;
    H[size] = x;
    size++;
    while(i>0 && H[i]<H[(i-1)/2]){
        int temp = H[i];
        H[i] = H[(i-1)/2];
        H[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

// We can build a heap incrementally in nlogn time. -> Trivial Solution
/*
Proper Method to Build binary heap -
1) Copy all elements into given array H
2) Heap Property naturally holds for all leaf nodes in the given tree (n/2) in number.
3) Heapify for the other elements.
*/

//Heapify function where parents are swapped if bigger
void heapify(int i, int H[]){
    n = size - 1;
    bool flag = true;
    while(i<=(n-1)/2 && flag){
        int min = i;//Let us consider parent to be smallest initially
        if(H[i]>H[2*i+1]){
            min = 2*i+1;//2i+1th element is made smallest in this case
        }
        if(2*i+2<=n && H[min]>H[2*i+2]){
            min = 2*i+2;
        }
        if(min!=i){
            int temp = H[i];
            H[i] = H[min];
            H[min] = temp;
            i = min;
        }
        else{
            flag = false;
        }
    }
}

int main(){
    return 0;
}

