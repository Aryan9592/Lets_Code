/*
    Here we will be adding two linked lists and representing the sum in the third one...
    For example - First Linked list --> 4 -> 5
                  Second Linked list --> 3 -> 4 -> 5
    Hence the final linked list we should get will be --> 3 -> 9 -> 0
*/

#include <iostream>
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
            delete next;
            this->next = NULL;
            cout << "Memory is free for node with data " << value << endl;
        }
        else
            cout << "Memory is already free for node with data " << value << endl;
    }
};

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

Node* reverse(Node* &head){
    
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void addTwoLists(Node* &head1, Node* &head2){
    int carry = 0;

    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while(head1 != NULL || head2 != NULL || carry != 0){

        int val1 = 0;
        if (head1 != NULL)
            val1 = head1 -> data;
        
        int val2 = 0;
        if (head2 != NULL)
            val2 = head2 -> data;
        
        int sum = carry + val1 + val2;

        int digit = sum % 10;

        //create node and add in answer Linked List
        insertAtHead(ansHead, ansTail, digit);

        carry = sum/10;
        if (head1 != NULL)
            head1 = head1 -> next;
        
        if (head2 != NULL)
            head2 = head2 -> next;
    }
    print(ansHead);
}

int main(){
    Node* head1 = NULL;
    Node* tail1 = NULL;

    // Linked List 1
    insertAtHead(head1, tail1, 5);
    insertAtHead(head1, tail1, 4);
    insertAtHead(head1, tail1, 3);

    Node* head2 = NULL;
    Node* tail2 = NULL;

    // Linked List 2
    insertAtHead(head2, tail2, 5);
    insertAtHead(head2, tail2, 4);

    cout<<endl;
    cout<<"First Linked List --> ";
    print(head1);
    cout<<endl;
    cout<<"Second Linked List --> ";
    print(head2);
    cout<<endl;

    head1 = reverse(head1);
    head2 = reverse(head2);
    
    cout<<"Result --> ";
    addTwoLists(head1, head2);
    cout<<endl;
    return 0;
}

