#include<iostream>
#include<queue>
#include<string>
#include<unordered_map>
using namespace std;

string FirstNonRepeating(string A){
    unordered_map<char, int> count;
    queue<int> q;
    string ans = "";

    for(int i = 0; i< A.length(); i++){
        char ch = A[i];

        // increase count;
        count[ch]++;

        // push it in queue;
        q.push(ch);

        while(!q.empty()){
            if(count[q.front()] > 1){
                // repeating character
                q.pop();
            }
            else{
                // non-repeating character milgya
                ans.push_back(q.front());
                break;
            }
        }
        
        if(q.empty())
            ans.push_back('#');
    }
    return ans;
}


int main(){
    string yes = "aabc";
    cout<<FirstNonRepeating(yes);
    return 0;
}