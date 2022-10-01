/*
    Here we are given two orders of trees.. inorder and preorder
    Our task is to simplify the original shape of that tree and write that in post-order
    for example: - input: N - 4
                        inorder[] = {1 6 8 7}
                        Preorder[] = {1 6 7 8}
                        Output: {1 6 7 8}
*/

#include<iostream>
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
class Solution{
    public:
    int findPosition(int in[], int element, int n){
        for(int i = 0; i < n ; i++){
            if(in[i] == element)
                return i;
        }
        return -1;
    }
    Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n){
        // base case 
        if(index >= n || inorderStart > inorderEnd){
            return NULL;
        }

        int element = pre[index++];
        Node* root = new Node(element);
        int position = findPosition(in, element, n);
        
        // recusive call
        root -> left = solve(in, pre, index, inorderStart, position - 1, n);
        root -> right = solve(in, pre, index, position - 1, inorderEnd, n);

        return root;
    }

    Node* buildTree(int in[], int pre[], int n){
        int preOrderIndex = 0;
        Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n);
        return ans;
    }
};

int main(){
    
    return 0;
}

