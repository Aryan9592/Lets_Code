#include<bits/stdc++.h>
using namespace std;

int main(){
    int loops;
    cin>>loops;
    for(int i = 0; i < loops; i++){
        int size;
        cin>>size;
        map<int, int> ans;
        for(int j = 1; j <= size; j++){
            int x;
            cin>>x;
            ans[x]++;
        }
        long long result = 0;
        for(auto it: ans){
            long long final = it.second;
            result += (final * (final - 1))/2;
        }
        cout<<result<<endl;
    }
    return 0;
}