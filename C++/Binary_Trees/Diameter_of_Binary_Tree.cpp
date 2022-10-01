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
    private:
        // Function to find the height of binary tree
        int height(struct Node* node){
            // base case
            if(node == NULL)
                return 0;
            int left = height(node -> left);
            int right = height(node -> right);

            int ans = max(left, right) + 1;
            return ans;
        }
    public:
        int diameter(struct Node* root){
            // base case
            if(root == NULL)
                return 0;
            
            // Recursion implemented
            int op1 = diameter(root -> left);
            int op2 = diameter(root -> right);
            int op3 = height(root -> left) + height(root -> right) + 1;

            int ans = max(op1, max(op2, op3));
            return ans;
        }

        pair<int, int> diameterFast(Node* root){
            // base case
            if(root == NULL){
                pair<int, int> p = make_pair(0, 0);
                return p;
            }

            pair<int, int> left = diameterFast(root -> left);
            pair<int, int> right = diameterFast(root -> right);

            int op1 = left.first;
            int op2 = right.first;
            int op3 = left.second + right.second + 1;

            pair<int, int> ans;
            ans.first = max(op1, max(op2, op3));
            ans.second = max(left.second, right.second) + 1;

            return ans;
        }
};

int main(){
    
    return 0;
}