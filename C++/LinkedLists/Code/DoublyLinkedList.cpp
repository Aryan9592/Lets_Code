#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*prev;
    Node*next;

    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        int value = this->data;
        //memory free
        if (this -> next != NULL){
            delete next;
            this->next = NULL;
            this->prev = NULL;
            cout<<"Memory is free for node with data "<<value<<endl;
        }
        else
            cout<<"Memory is already free for node with data "<<value<<endl;
    }
};

// Traversing a doubly linked list
void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

// Getting the length of list
int getLength(Node* &head){
    Node* temp = head;
    int Len = 0;

    while(temp != NULL){
        Len++;
        temp = temp -> next;
    }
    return Len;
}

//Inserting a node at the head
void InsertAtHead(Node* &head,Node* &tail, int d){
    if (head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        head -> prev = temp;
        temp -> next = head;
        head = temp;
    }
}

//Inserting a node at the tail
void InsertAtTail(Node* &head, Node* &tail, int d){
    if (tail == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

//Inserting a node at a random position
void insertAtPosition(Node* &head, Node* &tail, int position, int d){

    //inserting node at start
    if (position == 0){
        InsertAtHead(head,tail, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while(cnt < position){
        temp = temp->next;
        cnt++;
    }

    if (temp -> next == NULL){
        InsertAtTail(head, tail, d);
        return;
    }

    //Creating a node for d
    Node* NodetoInsert = new Node(d);
    NodetoInsert -> next = temp -> next;
    temp -> next -> prev = NodetoInsert;
    temp -> next = NodetoInsert;
    NodetoInsert -> prev = temp;
}

void DeleteNode(int position, Node* &head, Node* &tail){

    //deleting first or start node
    if (position == 0){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 0;
        while(cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        if (prev->next == NULL){
            tail = prev;
        }
        curr -> next = NULL;

        delete curr;
    }
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;
    print(head);

    InsertAtHead(head,tail, 19);
    print(head);

    InsertAtTail(head, tail, 0);
    print(head);

    InsertAtHead(head, tail, 27);
    print(head);

    insertAtPosition(head, tail, 2, 100);
    print(head);

    DeleteNode(3, head, tail);
    cout<<"Head: "<<head -> data<<endl;
    cout<<"Tail: "<<tail -> data<<endl;

    print(head);

    cout<<"The length of the linked list is "<<getLength(head);
    return 0;
}