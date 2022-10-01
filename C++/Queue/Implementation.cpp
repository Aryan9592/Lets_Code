/*
    So basically Queue focuses on FIFO method...which means first in first out
    It's opposite to stack...whatever enters first..remains at top of the queue and pops out first
    Approach 1 of implementing a Queue is Linked List
    Arrpoach 2 of implementing a Queue is Arrays
*/ 

#include<iostream>
#include<queue>
using namespace std;

//1. Linked Lists
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Queue{
    Node* head = NULL;
    Node* tail = NULL;
    public:
        // Constructor: It initializes the data members as required
        Queue(){}

        // It returns a boolean value indicating whether the queue is empty or not
        bool isEmpty(){
            if (head == NULL || head -> next == NULL)
                return true;
            else
                return false;
        }

        // This function should take one argument of type integer. It enqueues the element into the queue.
        void enqueue(int data){
            if (head == NULL){
                Node* temp = new Node(data);
                head = temp;
                tail = temp;
            }
            else{
                Node* temp = new Node(data);
                tail -> next = temp;
                tail = temp;
            }
        }

        // It dequeues/removes the element from the front of the queue and in turn, return the eleement being
        // dequeued or removed. In case the queue is empty, it returns -1
        int dequeue(){
            if (head == NULL){
                return -1;
            }
            else{
                int ans = head -> data;
                Node* curr = head -> next;
                head -> next = NULL;
                head = curr;
                return ans;
            }
        }

        // It returns the element being kept at the front of the queue. In case the queue is empty, it returns -1.
        int front(){
            if(head == NULL)
                return -1;
            else
                return head -> data;
        }
};

class Queue_1{
    int* arr;
    int qfront;
    int rear;
    int size;

    public:
        Queue_1(){
            size = 10001;
            arr = new int[size];
            qfront = 0;
            rear = 0;
        }

        bool isEmpty(){
            if(qfront == rear)
                return true;
            else
                return false;
        }

        void enqueue(int data){
            if(rear == size)
                cout<<"Queue is full"<<endl;
            else{
                arr[rear] = data;
                rear++;
            }
        }

        int dequeue(){
            if(qfront == rear){
                return -1;
            }
            else{
                int ans = arr[qfront];
                arr[qfront] = -1;
                qfront++;
                if(qfront == rear){
                    qfront = 0;
                    rear = 0;
                }
                return ans;
            }
        }

        int front(){
            if(qfront == rear){
                return -1;
            }
            else
                return arr[qfront];
        }
};

int main(){
    Queue q;
    q.enqueue(5);
    q.enqueue(7);
    cout<<endl;
    cout<<q.front()<<endl;
    if(q.isEmpty()){
        cout<<"Queue is empty"<<endl;
    }
    else
        cout<<"Queue is not empty"<<endl;
    q.dequeue();
    q.dequeue();
    cout<<q.front()<<endl;
    if(q.isEmpty()){
        cout<<"Queue is empty"<<endl;
    }
    else
        cout<<"Queue is not empty"<<endl;
    cout<<endl;
    return 0;
}