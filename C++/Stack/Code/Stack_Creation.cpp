#include<iostream>
#include<stack>
using namespace std;

int main(){
    
    // creation of stack
    stack <int> s;

    // push operation - pushes the element in the stack;
    s.push(2);
    s.push(3);

    // pop - removes the top element from the stack
    s.pop();

    // top - gives the top element of the stack
    cout<<endl;
    cout<<"Printing the top element - "<<s.top()<<endl;

    // empty - tells whether the stack is empty or not
    cout<<endl;
    if (s.empty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }

    //size - tells the size of the stack
    cout<<"Size of stack is "<<s.size()<<endl;
    
    cout<<endl;
    return 0;
}