/*
    Here we will make the code of the function which sort the list of 0s, 1s and 2s as the elements....
    Suppose if our list is 0->2->1->2->0->1->2->0
    Then our sorted list will be 0->0->0->1->1->2->2
*/

#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            this->next = NULL;
        }
    }
};

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        // new node create
        Node *temp = new Node(d);
        temp->next = head;
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

// Approach 1..
void Sorted(Node* &head){
    // checking empty list
    if (head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    int ZeroCount = 0;
    int OneCount = 0;
    int TwoCount = 0;

    Node* temp = head;
    
    while(temp != NULL){
        if(temp -> data == 0)
            ZeroCount++;
        else if (temp -> data == 1)
            OneCount++;
        else if (temp -> data == 2)
            TwoCount++;

        temp = temp -> next;
    }

    temp = head;

    while(temp != NULL){
        if (ZeroCount != 0){
            temp -> data = 0;
            ZeroCount--;
        }
        else if (OneCount != 0){
            temp -> data = 1;
            OneCount--;
        }
        else if (TwoCount != 0){
            temp -> data = 2;
            TwoCount--;
        }

        temp = temp -> next;
    }

    print(head);
}

// Approach 2..
void Sorted_1(Node* & head){
    Node* ZeroHead = NULL;
    Node* ZeroTail = NULL;
    Node* OneHead = NULL;
    Node* OneTail = NULL;
    Node* TwoHead = NULL;
    Node* TwoTail = NULL;

    Node* temp = head;
    
    // Creating three separate Linked lists
    while(temp != NULL){
        if (temp -> data == 0)
            insertAtHead(ZeroHead, ZeroTail, 0);
        else if (temp -> data == 1)
            insertAtHead(OneHead, OneTail, 1);
        else if (temp -> data == 2)
            insertAtHead(TwoHead, TwoTail, 2);
        
        temp = temp -> next;
    }

    // Merging Lists

    // 1s not a empty list
    if (OneHead != NULL)
        ZeroTail -> next = OneHead;
    // 1s a empty list
    else if (OneHead == NULL)
        ZeroTail -> next = TwoHead;
    
    OneTail -> next = TwoHead;

    // Shifting the head to the new merge list
    if (ZeroHead != NULL)
        head = ZeroHead;
    else if (OneHead != NULL)
        head = OneHead;
    else if (TwoHead != NULL)
        head = TwoHead;
    
    print(head);
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 0);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);
    insertAtHead(head, tail, 0);
    insertAtHead(head, tail, 1);

    cout<<endl;
    print(head);
    cout<<endl;
    Sorted_1(head);
    cout<<endl;

    return 0;
}