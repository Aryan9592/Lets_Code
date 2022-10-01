/*
    Here we will be given two linked lists which would be already sorted...We have to merge them both and sort it down
    For Example - First list -->  2 -> 3 -> 5; Second list --> 1 -> 4 -> 5;
    Our answer should be -->  1 -> 2 -> 3 -> 4 -> 5 -> 5;
*/

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

void print(Node* &head){
    Node* temp = head;

    while (temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

void Merge_Sort(Node* &head1, Node* &head2){
    // Creating head and tail of new list
    Node* MergeHead = NULL;
    Node* MergeTail = NULL;

    Node* temp1 = head1;
    Node* temp2 = head2;
    int pos = 0;

    while(temp1 != NULL && temp2 != NULL){
        if (temp1 -> data <= temp2 -> data){
            insertAtPosition(MergeHead, MergeTail, pos, temp1 -> data);
            temp1 = temp1 -> next;
            pos++;
        }
        else if (temp1 -> data > temp2 -> data){
            insertAtPosition(MergeHead, MergeTail, pos, temp2 -> data);
            temp2 = temp2 -> next;
            pos++;
        }
    }

    if (temp1 == NULL)
        MergeTail -> next = temp2;
    else if (temp2 == NULL)
        MergeTail -> next = temp1;
    
    print(MergeHead);
}

int main(){

    Node* head1 = NULL;
    Node* tail1 = NULL;
    
    Node* head2 = NULL;
    Node* tail2 = NULL;

    insertAtPosition(head1, tail1, 0, 2);
    insertAtPosition(head1, tail1, 1, 3);
    insertAtPosition(head1, tail1, 2, 5);
    insertAtPosition(head2, tail2, 0, 1);
    insertAtPosition(head2, tail2, 1, 4);
    insertAtPosition(head2, tail2, 2, 5);

    cout<<endl;
    cout<<"First linked list -> ";
    print(head1);
    cout<<endl;
    cout<<"Second linked list -> ";
    print(head2);
    cout<<endl;

    cout<<"After Merging -> ";
    Merge_Sort(head1, head2);

    
    return 0;
}