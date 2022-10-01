/*
    In this case, the queue will be circular in nature...
    For e.g: Elements in queue are 8 -> 9 -> 3 -> 6 -> 4 and it's size was 5...suppose we popped the element and filled other two elements
    at the back of the queue not in the front...then circular queue can be used
*/

#include<iostream>
using namespace std;

class Circular_Queue{
    int *arr;
    int qfront;
    int rear;
    int size;

    public:
        // Intialize your data structure
        Circular_Queue(int n){
            size = n;
            arr = new int[size];
            qfront = -1;
            rear = -1;
        }

        // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, otherwise false
        bool enqueue(int value){
            if ((rear == qfront - 1) || (qfront == -1 and rear == size - 1))
                return false;
            else if(rear == size - 1){
                rear = 0;
                arr[rear] = value;
                return true;
            }
            else{
                rear++;
                arr[rear] = value;
                return true;
            }
        }

        // Dequeues top element from queue. Returns -1 if stack is empty otherwise return the element which got dequeued
        int dequeue(){
            if(qfront == rear)
                return -1;
            else{
                if(qfront == size - 1){
                    qfront = 0;
                }
                else
                    qfront++;
                int ans = arr[qfront];
                arr[qfront] = -1;
                return ans;
            }
            
        }
};

int main(){
    Circular_Queue Ary(5);
    cout<<Ary.enqueue(6)<<endl;
    cout<<Ary.enqueue(7)<<endl;
    cout<<Ary.enqueue(8)<<endl;
    cout<<Ary.enqueue(9)<<endl;
    cout<<Ary.enqueue(10)<<endl;
    cout<<Ary.enqueue(11)<<endl;
    cout<<Ary.dequeue()<<endl;
    cout<<Ary.dequeue()<<endl;
    cout<<Ary.dequeue()<<endl;
    cout<<Ary.dequeue()<<endl;
    cout<<Ary.dequeue()<<endl;
    return 0;
}