/*
    Here we have to insert N no. of stacks into a array
*/

#include<iostream>
#include<stack>
using namespace std;

class NStack{
    int *arr;
    int *top;
    int *next;

    int n, s;

    int freespot;

    public:
        // Initialize your data structure
        NStack(int N, int S){
            n = N;
            s = S;
            arr = new int[s];
            top = new int[n];
            next = new int[s];

            // top intilization
            for(int i = 0; i < n; i++){
                top[i] = -1;
            }

            // next intialization
            for(int i = 0; i < s; i++){
                next[i] = i+1;
            }
            // update last index value of next to -1
            next[s-1] = -1;

            // initialize freespot
            freespot = 0;
        }

        // Pushes'X' into the Nth stack, Returns true if it gets pushed into the stack, and false otherwise
        bool push(int x, int m){
            // check for overflow
            if(freespot == -1)
                return false;
            
            // find index
            int index = freespot;

            // update freespot
            freespot = next[index];

            // insert element into array
            arr[index] = x;

            // update next
            next[index] = top[m-1];

            // update top
            top[m-1] = index;

            return true;
        }

        // Pops top element from Nth Stack, Returns -1 if the stack is empty, otherwise return
        // the popped element
        int pop(int m){
            // check underflow condition
            if(top[m-1] == -1){
                return -1;
            }
            // Just reverse the push conditions
            int index = top[m-1];
            top[m-1] = next[index];
            next[index] = freespot;
            freespot = index;
            return arr[index];
        }
};

int main(){
    NStack Arrays(4, 8);
    Arrays.push(4, 1);
    Arrays.push(5, 1);
    Arrays.push(6, 2);
    Arrays.push(8, 3);
    Arrays.push(10, 2);
    Arrays.push(12, 3);
    cout<<Arrays.pop(1)<<endl;
    cout<<Arrays.pop(3)<<endl;
    return 0;
}