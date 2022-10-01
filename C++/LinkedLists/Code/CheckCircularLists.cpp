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
        int value = this -> data;
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

void InsertNode(Node* &tail, int element, int d){
    
    //empty list
    if (tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        // non-empty list
        // assuming that the element is present in the list

        Node* curr = tail;
        
        while(curr -> data != element){
            curr = curr -> next;
        }

        //element found -> curr is representing current node which is the element one
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
} 

void print(Node* &tail){
    Node* temp = tail;

    //empty list
    if (temp == NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    do{
        cout<<tail -> data<<" ";
        tail = tail -> next;
    }while(tail != temp);

    cout<<endl;
}

void DeleteNode(Node* &tail, int value){
    
    //empty list
    if (tail == NULL){
        cout<<"List is empty, please check again..."<<endl;
        return;
    }
    else{
        //Non-empty

        //assuming that the "value" is present in the Linked List
        Node* hit = tail;
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value){
            prev = curr;
            curr = curr -> next;
            if (prev == hit){
                cout<<"This element is not present in the list"<<endl;
                return;
            }
        }

        prev -> next = curr -> next;

        // 1 Node Linked List
        if (curr == prev){
            tail = NULL;
        }

        // 2 Node Linked List
        else if (tail == curr){
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;

    }
}

void Check_List(Node* tail){
    // checking whether list is empty or not
    if (tail == NULL){
        cout<<"List is Empty"<<endl;
    }
    // checking for other cases
    else{
        Node* curr = tail -> next;
        while(curr != NULL && curr != tail){
            curr = curr -> next;
        }
        if (curr == tail){
            cout<<"True"<<endl;
        }
        else
            cout<<"False"<<endl;
    }
    
}

int main(){
    
    Node* tail = NULL;

    InsertNode(tail, 0, 3);
    print(tail);

    InsertNode(tail, 3, 4);
    print(tail);
    InsertNode(tail, 3, 10);
    print(tail);
    InsertNode(tail, 4, 27);
    print(tail);
    InsertNode(tail, 27, 9);
    print(tail);

    Check_List(tail);
    return 0;
}