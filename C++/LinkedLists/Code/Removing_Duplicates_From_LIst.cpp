// Here we will create two functions..One will remove duplicates from a sorted list and an unsorted one

#include <iostream>
#include <map>
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

// For Sorted List
void UniqueSortedList(Node *&head)
{
    // empty list
    if (head == NULL)
    {
        return;
    }

    // non-empty list
    Node *curr = head;

    while (curr != NULL)
    {

        if (curr->next != NULL && curr->data == curr->next->data)
        {
            Node *next_next = curr->next->next;
            Node *nodetoDelete = curr->next;
            curr->next = next_next;
            delete nodetoDelete;
        }
        else // not equal
            curr = curr->next;
    }

    print(head);
}

// For Unsorted List
// 3 Approaches with different time and space complexities...

// 1st Approach - Using two loops -> space complexity = 1; time complexity = n^2.
void UnsortedList_1(Node *&head)
{
    // checking the list
    if (head == NULL)
    {
        cout << "NULL" << endl;
        return;
    }
    Node *temp = head;
    Node *curr = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        prev = temp;
        curr = temp->next;
        while (curr != NULL)
        {

            if (temp->data == curr->data)
            {
                Node *nodetoDelete = curr;
                curr = curr->next;
                prev->next = curr;
                delete nodetoDelete;
            }
            else
            {
                prev = prev->next;
                curr = curr->next;
            }
        }
        temp = temp->next;
    }

    print(head);
}

// 2nd Approach - Making the list sorted and then removing the duplicates -> space complexity = nlogn;
//                time complexity = 1
void UnsortedList_2(Node *&head)
{
    // checking List
    if (head == NULL)
    {
        cout << "NULL" << endl;
        return;
    }

    Node *temp = head;
    Node *curr = head;
    int swap = 0;

    while (temp != NULL)
    {
        curr = temp->next;
        while (curr != NULL)
        {
            if (curr->data < temp->data)
            {
                swap = curr->data;
                curr->data = temp->data;
                temp->data = swap;
            }
            curr = curr->next;
        }
        temp = temp->next;
    }
    UniqueSortedList(head);
}

// 3rd Approach - Using Map method -> Time complexity = n; Space complexity = n
void UnsortedList_3(Node *&head)
{
    // checking empty list
    if (head == NULL){
        cout << "NULL" << endl;
        return;
    }

    map<int,  bool> visited;
    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL){
        if (visited[curr -> data] == true){
            Node* NodetoDelete = curr;
            curr = curr -> next;
            prev -> next = curr;
            delete NodetoDelete;
        }
        else{
            visited[curr -> data] = true;
            prev = curr;
            curr = curr -> next;
        }
    }
    print(head);
}

int main()
{

    Node *node1 = new Node(23);
    Node *head = node1;
    Node *tail = node1;

    insertAtHead(head, tail, 8);
    insertAtHead(head, tail, 21);
    insertAtHead(head, tail, 13);
    insertAtHead(head, tail, 87);
    insertAtHead(head, tail, 7);
    insertAtHead(head, tail, 23);
    insertAtHead(head, tail, 87);
    insertAtHead(head, tail, 21);
    insertAtHead(head, tail, 8);

    cout << endl;
    print(head);
    cout << endl;
    UnsortedList_3(head);
    cout << endl;
    return 0;
}