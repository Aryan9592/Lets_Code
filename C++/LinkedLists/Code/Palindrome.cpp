/*
    Here we will implement a function palan which will tell whether a linked list is a palindrom or not
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

bool Check_Palan(Node *&head)
{

    // Creating a new linked list;
    Node *NewHead = NULL;
    Node *NewTail = NULL;

    Node *temp = head;
    int n = 0;

    // Copying the elements of original list in the new one in a reverse way!!
    while (temp != NULL)
    {
        insertAtHead(NewHead, NewTail, temp->data);
        temp = temp->next;
    }
    temp = head;
    Node *Newtemp = NewHead;

    while (temp != NULL)
    {
        if (temp->data != Newtemp->data)
        {
            n = 1;
            break;
        }
        temp = temp->next;
        Newtemp = Newtemp->next;
    }
    if (n == 1)
        return false;
    else
        return true;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    // insertAtHead(head, tail, 1);
    // insertAtHead(head, tail, 1);
    // insertAtHead(head, tail, 2);
    // insertAtHead(head, tail, 2);
    // insertAtHead(head, tail, 1);

    // cout<<endl;
    // cout<<"Original List is --> ";
    // print(head);
    // cout<<endl;
    if (Check_Palan(head))
        cout << "This is a Palindrome" << endl;
    else
        cout << "This is not a Palindrome" << endl;
    cout << endl;

    return 0;
}