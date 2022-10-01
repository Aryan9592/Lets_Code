#include<iostream>
#include<vector>
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

// Function to return a list containing elements of left view of the Binary tree.
void solve(Node* root, vector<int> &ans, int level){
    // base case
    if (root == NULL)
        return;
    
    // we entered into a new level
    if(level == ans.size())
        ans.push_back(root -> data);
    
    solve(root -> right, ans, level + 1);
    solve(root -> left, ans, level + 1);
}

vector<int> leftView(Node* root){
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

int main(){
    
    return 0;
}