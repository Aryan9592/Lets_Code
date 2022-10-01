#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

class Solution{
    public:
    // function to store the zig zag order traversal of tree in a list
    vector <int> zigZagTraversal(Node* root){
        vector<int> result;
        if(root == NULL)
            return result;
        
        queue<Node*> q;
        q.push(root);

        bool leftToRight = true;

        while(!q.empty()){
            int size = q.size();
            vector<int> ans(size);

            // Level Process
            for(int i = 0; i < size; i++){
                
                Node* frontNode = q.front();
                q.pop();

                int index = leftToRight ? i : size - i - 1;
                ans[index] = frontNode -> data;

                if(frontNode -> left)
                    q.push(frontNode -> left);
                
                if(frontNode -> right)
                    q.push(frontNode -> right);
            }
            // direction changes
            leftToRight = !leftToRight;

            for(auto i: ans){
                result.push_back(i);
            }
        }
        return result;
    }
};

int main(){
    
    return 0;
}