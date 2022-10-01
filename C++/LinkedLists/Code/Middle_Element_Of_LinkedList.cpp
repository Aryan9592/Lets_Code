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

void Mid_Element(Node* &head, int len_list){
    int new_len = 0;
    Node* curr = head;
    if (len_list % 2 == 0){
        new_len = (len_list/2) + 1;
        int cnt;
        for (cnt = 0; cnt < new_len-1; cnt++){
            curr = curr->next;
    }
    }
    else{
        new_len = len_list/2;
        int cnt;
        for (cnt = 0; cnt < new_len; cnt++){
            curr = curr->next;
        }
    }
    cout<<curr -> data<<endl;
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

    insertAtHead(head, tail, 34);
    print(head);

    cout<<"Middle element of the Linked list is: ";
    Mid_Element(head, getLength(head));

    cout<<endl;

    return 0;
}