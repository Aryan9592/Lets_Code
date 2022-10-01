#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node* random;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
            cout << "Memory is free for node with data " << value << endl;
        }
        else
            cout << "Memory is already free for node with data " << value << endl;
    }
};

// Approach_1
class Solution_1{ 
    private:
    void insertAtTail(Node* head, Node* &tail, int d){
        Node* temp = new Node(d);
        if (tail == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }
    public:
    Node* CopyList_1(Node* head){
        //Step 1: Create a clone list
        Node* CloneHead = NULL;
        Node* CloneTail = NULL;

        Node* temp = head;

        while(temp != NULL){
            insertAtTail(CloneHead, CloneTail, temp -> data);
            temp = temp -> next; 
        }

        //Step 2: Create a map
        unordered_map<Node*, Node*>Mapping;

        Node* originalNode = head;
        Node* cloneNode = CloneHead;
        while(originalNode != NULL && cloneNode != NULL){
            Mapping[originalNode] = cloneNode;
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }

        originalNode = head;
        cloneNode = CloneHead;

        while(originalNode != NULL){
            cloneNode -> random = Mapping[originalNode -> random];
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        return cloneNode;
    }
};

//Approach_2

class Solution_2{
    private:
    void insertAtTail(Node* head, Node* &tail, int d){
        Node* temp = new Node(d);
        if (tail == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }

    public:
    Node* CopyList_2(Node* &head){

        // step 1: create a clone list

        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp -> data);
            temp = temp -> next;
        }

        // step 2: cloneNodes add in between Original List
        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while(originalNode != NULL && cloneNode != NULL){
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;

            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode = NULL;
        }

        // step 3: random pointer copy

        temp = head;
        while(temp != NULL){
            if (temp -> next != NULL){
                temp -> next -> random = temp -> random ? temp -> random -> next : temp -> random;
            }
            temp = temp -> next -> next;
        }

        // step 4: revert changes done in step 2
        originalNode = head;
        cloneNode = cloneHead;

        while(originalNode != NULL && cloneHead != NULL){
            originalNode -> next = cloneNode -> next;
            originalNode = originalNode -> next;

            if (originalNode != NULL){
                cloneNode -> next = originalNode -> next;
            }
            cloneNode = cloneNode -> next;
        }

        // step 5: return ans;
        return cloneHead;
    }
};
