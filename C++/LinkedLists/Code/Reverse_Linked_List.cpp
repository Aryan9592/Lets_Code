#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        int value = this->data;
        //memory free
        if (this -> next != NULL){
            delete next;
            this->next = NULL;
            cout<<"Memory is free for node with data "<<value<<endl;
        }
        else
            cout<<"Memory is already free for node with data "<<value<<endl;
    }
};

void insertAtHead(Node* &head, Node* &tail, int d){
    if (head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        //new node create
        Node*temp = new Node(d);
        temp -> next = head;
        head = temp;
    }
}

void insertAtTail(Node* head, Node* &tail, int d){
    if (tail == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        //new node create;
        Node* temp = new Node(d);
        tail -> next = temp;
        tail = tail -> next;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d){

    //inserting node at start
    if (position == 0){
        insertAtHead(head, tail, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while(cnt < position){
        temp = temp->next;
        cnt++;
    }

    if (temp -> next == NULL){
        insertAtTail(head, tail, d);
        return;
    }

    //Creating a node for d
    Node* NodetoInsert = new Node(d);
    NodetoInsert -> next = temp -> next;
    temp -> next = NodetoInsert;
}

void deleteNode(int position, Node* &head, Node* &tail){
    
    //deleting first or start node
    if (position == 0){
        Node* temp = head;
        head = head->next;
        //memory free start node
        temp->next = NULL;
        delete temp;
    }
    else{
        //deleting any middle or last node
        Node*curr = head;
        Node*prev = NULL;

        int cnt = 0;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        if (prev->next == NULL){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }

}

void print(Node* &head){
    Node* temp = head;

    while (temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int getLength(Node* &head){
    Node* temp = head;
    int Len = 0;

    while (temp != NULL){
        Len++;
        temp = temp -> next;
    }
    return Len;
}

// Iterative Way //
void Reverse(Node* &head){
    
    if (head == NULL || head -> next == NULL){
        return;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    print(prev);
}

// RECURSIVE APPROACH - 2

Node* reverse_3(Node* &head){
     // base case
    if (head == NULL || head -> next == NULL){
        return head;
    }

     Node* temp = reverse_3(head -> next);

     head -> next -> next = head;
     head -> next = NULL;

     return temp;

}

// Recursive part-1 // 
void reverse_1(Node* &head, Node* &curr, Node* &prev){

    // base case
    if (curr == NULL){
        head = prev;
        return;
    }

    Node* forward = curr -> next;
    reverse_1(head, forward, curr);
    curr -> next = prev;
}

// Recursive part-2 //
void reverse_2(Node* &head){

    Node* curr = head;
    Node* prev = NULL;
    reverse_1(head, curr, prev);
    print(head);
}



int main(){

    //head pointed to head
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 45);
    insertAtHead(head, tail, 34);
    insertAtTail(head, tail, 21);
    insertAtPosition(head, tail, 1, 90);
    
    cout<<endl;
    
    cout<<"Our Linked List is: ";
    print(head);

    cout<<endl;

    // By iteration //
    // cout<<"After Reversing the list using Iteration: ";
    // Reverse(head);

    // By Recursion
    cout<<"After Reversing the list using Recursion: ";
    // reverse_2(head);
    
    // Recursion 2nd Approach!!
    Node* recur = reverse_3(head);
    print(recur);
    cout<<endl;

    return 0;
}