#include<iostream>
#include<map>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    } 
};

// Function to return a tree created from postorder and inorder traversals
void createMapping(int in[], map<int, int> &nodeToIndex, int n){
    for(int i = 0; i < n; i++){
        nodeToIndex[in[i]] = i;
    }
}

Node* solve(int in[], int post[], int &index, int inorderStart,
            int inorderEnd, int n, map<int, int> &nodeToIndex){
    // base case
    if(index >= n || inorderStart > inorderEnd){
        return NULL;
    } 

    // create a root node for element
    int element = post[index++];
    Node* root = new Node(element);

    // find element's index in inorder
    int position = nodeToIndex[element];

    // recursive calls
    root -> left = solve(in, post, index, inorderStart, position - 1, n, nodeToIndex);
    root -> right = solve(in, post, index, position+1, inorderEnd, n, nodeToIndex);

    return root;
}

Node* buildTree(int in[], int post[], int n){
    int postOrderIndex = n-1;
    map<int, int> nodeToIndex;

    // create nodes to index mapping
    createMapping(in, nodeToIndex, n);

    Node* ans = solve(in, post, postOrderIndex, 0, n-1, n, nodeToIndex);
    return ans;
}