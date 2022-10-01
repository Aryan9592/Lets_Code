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

Node *kReverse(Node* &head, int k){
    // base call
    if (head == NULL){
        return NULL;
    }

    // step1: reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    while (curr != NULL && count < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step 3: Recursion
    if (next != NULL){
        head -> next = kReverse(next, k);
    }

    // step 4: return head of reversed list
    return prev;
}

int main(){

    //head pointed to head
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 12);
    print(head);

    insertAtHead(head, tail, 15);
    print(head);

    insertAtTail(head, tail, 20);
    print(head);

    insertAtPosition(head, tail, 3, 22);
    print(head);

    Node* ans = kReverse(head, 2);
    print(ans);

    return 0;
}