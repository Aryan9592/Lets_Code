/*
    Here we will create a stack function with two different approaches - Array and Linked Lists
*/

#include<iostream>
using namespace std;

// With the help of Array
class Stack_1{
    // properties
    public:
        int *arr;
        int top;
        int size;
    
    // behaviour
    Stack_1(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if((size - top) > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack OverFlow"<<endl;
        }
    }

    void pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    int peek(){
        if (top >= 0 && top < size){
            return arr[top];
        }
        else{
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1)
            return true;
        else
            return false;
    }
};

// with the help of linked lists
class Node{
    public:
        int data;
        Node* next;
        
        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }
};

class Stack_2{
    public:
    Node* head = NULL;
    Node* tail = NULL;
        Stack_2(){}

        void push(int element){
            Node* temp = new Node(element);
            if (head == NULL){
                head = temp;
                tail = temp;
            }
            else{
                temp -> next = head;
                head = temp;
            }
        }

        void pop(){
            if (head == NULL){
                cout<<"Stack UnderFlow"<<endl;
            }
            else{
                Node* curr = head;
                head = head -> next;
                curr -> next = NULL;
            }
        }

        int peek(){
            if (head == NULL){
                cout<<"Stack is empty"<<endl;
            }
            else
                return head -> data;
        }

        bool is_empty(){
            if (head == NULL)
                return true;
            else
                return false;
        }
};

int main(){
    
    Stack_2 s;

    s.push(22);
    s.push(43);
    s.push(44);

    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    cout<<s.is_empty()<<endl;
    s.pop();
    s.pop();
    cout<<s.is_empty()<<endl;
    s.pop();
    cout<<s.is_empty()<<endl;
    cout<<s.peek()<<endl;


    return 0;
}