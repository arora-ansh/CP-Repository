#include <iostream>
#include <queue>
using namespace std;

class treeNode {
    public : 
        int data;
        treeNode *left;
        treeNode *right;

        treeNode(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

void preOrderTraversal(treeNode *node){
    if(node==NULL){
        return;
    }
    cout<<node->data<<" ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

void postOrderTraversal(treeNode *node){
    if(node==NULL){
        return;
    }
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout<<node->data<<" ";
}

void inOrderTraversal(treeNode *node){
    if(node==NULL){
        return;
    }
    inOrderTraversal(node->left);
    cout<<node->data<<" ";
    inOrderTraversal(node->right);
}

void levelOrderTraversal(treeNode *root){
    queue<treeNode> q;
    q.push(root);
    while(q.empty()==false){
        treeNode *cur = q.front();
        cout<<cur->data<<" ";
        q.pop();
        if(cur->left){
            q.push(cur->left);
        }
        if(cur->right){
            q.push(cur->right);
        }
    }
}

int countNodes(treeNode *node){
    if(node==NULL){
        return 0;
    }
    return 1+countNodes(node->left)+countNodes(node->right);
}

int treeHeight(treeNode *node){
    if(node==NULL){
        return 0;
    }
    return 1+max(treeHeight(node->left),treeHeight(node->right));
}

treeNode * treeCopy(treeNode *root){
    if(root==NULL){
        return;
    }
    treeNode *copy = new treeNode(root->data);
    copy->left = treeCopy(node->left);
    copy->right = treeCopy(node->right);
    return copy;
}

void bstsearch(treeNode *root, int x){
    treeNode current = root;
    while(current!=NULL){
        if(current.data==x){
            return true;
        }
        else if(current.data>x){
            return bstsearch(current->left, x);
        }
        else if(current.data<x){
            return bstsearch(current->right, x);
        }
    }
    return false;
}

void bstinsert(treeNode *root, treeNode x){//x is treenode to be inserted to the bst
    if(root==NULL){
        return;
    }
    if(root->data >= x->data){
        if(root->left==NULL){
            root->left = x;
        }
        else{
            bstinsert(root->left,x);
        }
    }
    else{
        if(root->right==NULL){
            root->right = x;
        }
        else{
            bstinsert(root->right,x);
        }
    }
}

//bstcheck can be done by either modifying inorder traversal or by this method
bool bstcheck(treeNode *root, int min, int max){
    if(root==NULL){
        return true;
    }
    return(root->data>min && root->data<max && bstcheck(root->left,min,root->data) && bstcheck(root->right,root->data,max));
}

int main(){
    
    return 0;
}