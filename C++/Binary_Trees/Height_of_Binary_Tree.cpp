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
};

int main(){
    Node s(5);
    s.left = new Node(7);
    s.right = new Node(8);
    s.right->left = new Node(10);
    Solution at;
    cout<<at.height(&s)<<endl;;
    return 0;
}