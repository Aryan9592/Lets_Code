/*
    This code will make us create a special stack with time and space complexity as 1...
*/

#include<iostream>
#include<stack>
using namespace std;

int Min(int a, int b){
    if (a > b)
        return b;
    else
        return a;
}

class SpecialStack{
    // Define the data members
    stack<int> stack_1;
    int64_t num = -1;
    int value;
    int mini = INT8_MAX;
    /*----------------------- Public Functions of SpecialStack-----------------------*/

    // 1. push(data): This function should take one argument of type integer. It pushes the element 
    //                the stack and returns nothing
    public:
    void push(int data){
        stack_1.push(data);
        mini = Min(mini, data);
        if (num == -1)
            num = mini;
        else
            num = num*10 + mini;
    }

    // 2. pop(): It pops the element from the top of the stack and, in turn, returns the elment being popped
    //           or deleted. In case the stack is empty, it returns -1
    int pop(){
        if (stack_1.empty())
            num = -1;
            return -1;
        int ans = stack_1.top();
        stack_1.pop();
        mini = num % 10;
        num = num / 10;
        return ans;
    }

    // 3. top(): It returns the element being kept at the top of the stack. In case the stack is empty
    //           it returns -1.
    int top(){
        if(stack_1.empty()){
            num = -1;
            return -1;
        }
        return stack_1.top();
    }

    // 4. isEmpty(): It returns a boolean value indicating whether the stack is empty or not.
    bool isEmpty(){
        if (stack_1.empty()){
            num = -1;
            return true;
        }
        else
            return false;
    }

    // 5. getMin(): It returns the smallest element present in the stack. In case the stack is empty, it returns -1
    int getMin(){
        if (stack_1.empty()){
            num = -1;
            return -1;
        }
        else
            return mini;
    }

};

int main(){
    SpecialStack ans;
    ans.push(5);
    ans.push(8);
    ans.push(3);
    ans.push(2);
    ans.push(9);
    cout<<endl;
    cout<<ans.getMin()<<endl;
    cout<<ans.pop()<<endl;;
    cout<<ans.top()<<endl;
    ans.pop();
    cout<<ans.getMin()<<endl;
    return 0;
}