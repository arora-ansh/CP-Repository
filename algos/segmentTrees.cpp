#include <iostream>
using namespace std;

void buildTree(int *arr, int *tree, int start, int end, int treeNode){
	if(start == end){
		tree[treeNode] = arr[start];
		return;
	}
	int mid = (start+end)/2;
	buildTree(arr,tree,start,mid,2*treeNode);
	buildTree(arr,tree,mid+1,end,2*treeNode+1);
	tree[treeNode] = tree[2*treeNode]+tree[2*treeNode+1];
}

int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int n = 9; //Size of array
	int *tree = new int[2*n]; //Segment Tree declaration

	buildTree(arr,tree,0,8,1);//array jiska tree build karna, tree declaration(dynamic), first index of array, last index of array, where to start from on tree

	for(int i=1;i<2*n;i++){
		cout<<tree[i]<<" ";
	}
	cout<<endl;
	return 0;
}