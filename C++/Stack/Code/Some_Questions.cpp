/*
1.    In this we will create a function which will tell whether a pattern is balanced 
    or not...
    For e.g: Here's a pattern in stack --> [({})] -> Balanced;
    Now here's another pattern in stack -> [({)}] -> Not Balanced
*/

#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;



bool isValidParenthesis(string expression){
    stack<char> s;
    for(int i = 0; i < expression.length(); i++){
        char ch = expression[i];

        // if opening bracket, stack path
        // if close bracket, stacktop check and pop

        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }
        else{
            // for closing bracket
            if(!s.empty()){
                char top = s.top();
                if((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')){
                    s.pop();
                }
                else
                    return false;

            }
            else
                return false;
        }
    }
    if (s.empty())
        return true;
    else
        return false;
}

// 2. Insert an element at the bottom of the stack...
void solve(stack<int>& s, int x){
    // base case
    if(s.empty()){
        s.push(x);
        return;
    }
    
    int num = s.top();
    s.pop();

    //recursive call
    solve(s, x);

    s.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x){
    solve(myStack, x);
    return myStack;
}

// 3. Reverse the stack using recursion;
void insertAtBottom(stack<int> &s, int element){
    // base case
    if(s.empty()){
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();

    //recursive call
    insertAtBottom(s, element);

    s.push(num);
}

void reverseStack(stack<int> &stack){
    // base case
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    //recursive call
    reverseStack(stack);

    insertAtBottom(stack, num);
}

// 4. Sort a Stack;
void sortedInsert(stack<int> &stack, int num){
    // base case
    if(stack.empty() || (!stack.empty() && stack.top() < num)){
        stack.push(num);
        return;
    }

    int n = stack.top();
    stack.pop();

    //recursive call
    sortedInsert(stack, num);

    stack.push(n);
}

void sortStack(stack<int> &stack){
    // base case
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    // recursive call
    sortStack(stack);

    sortedInsert(stack, num);

}

// 5. Finding the Redundant pairs
bool findRedundantBrackets(string &s){
    stack<char> st;
    for(int i = 0; i < s.length(); i++){
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else
        {
            // ch ya toh ')' hai ya lowercase letter

            if (ch == ')'){
                bool isRedundant = true;

                while(st.top() != '('){
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        isRedundant = false;
                    }
                    st.pop();
                }

                if(isRedundant == true){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}

//6. Minimum cost to make string valid
int findMinimumCost(string str){
    // odd condition
    if(str.length() % 2 == 1){
        return -1;
    }

    stack<char> s;
    for (int i = 0; i < str.length(); i++){
        char ch = str[i];
        
        if(ch == '{')
            s.push(ch);
        else{
            //ch is closed brace
            if(!s.empty() && s.top() == '{'){
                s.pop();
            }
            else{
                s.push(ch);
            }
        }
    }

    //stack n contains invalid expression
    int a = 0, b = 0;
    while(!s.empty()){
        if(s.top() == '{')
            b++;
        else
            a++;
        s.pop();
    }

    int ans = (a+1)/2 + (b+1)/2;
    return ans;
}

// 7. Next smaller element -> In this function our task is to find the next smaller element in a given array...
// For e.g: we have a array -> [2, 5, 3, 4, 1] then the answer will be [1, 3, 1, 1, -1]

vector<int> nextSmallerElement(vector<int> &arr, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = n-1; i >= 0; i--){
        int curr = arr[i];
        while(s.top() > curr)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main(){
    
    return 0;
}