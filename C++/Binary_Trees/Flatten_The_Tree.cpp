/*
    Given a binary tree, flatten it into linked list in-place (i.e space complexity - O(1)). Usage of
    auxillary data structure is not allowed. After flattening, left of each node should point to NULL and right
    should contain next node in preorder.
*/

#include<iostream>
using namespace std;

struct Node {
	int data;
	struct tNode* left;
	struct tNode* right;
};

class Solution{
    public:
    void flatten(Node* root){
        Node* curr = root;
        while(curr != NULL){
            if(curr -> left){
                Node* prev = curr -> left;
                while(prev -> right)
                    prev = prev -> right;
                
                prev -> right = curr -> right;
                curr -> right = curr -> left;
                curr -> left = NULL;
            }
            curr = curr -> right;
        }

    }
};

int main(){
    
    return 0;
}