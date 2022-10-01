#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// Approach 1
queue<int> rev(queue<int> q){
    stack<int> s;

    while(!q.empty()){
        int element = q.front();
        q.pop();
        s.push(element);
    }
    
    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;
}

int main(){
    queue<int> ans;
    ans.push(5);
    ans.push(6);
    ans.push(7);
    rev(ans);
    // cout<<ans.pop();
    // cout<<ans.pop();

    return 0;
}

// Approach2
queue<int> modifyQueue(queue<int> q, int k){
    //algo
    //step 1: pop first k from Q and put into Stack
    stack<int> s;

    for(int i=0; i<k; i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }

    //step 2: fetch first (n-k) element from Q and push back

    int t = q.size() - k;

    while(t--){
        int val = q.front();
        q.pop();
        q.push(val);
    }
}
