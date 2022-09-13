/*
    You are given an array A.
    
    A pair (i, j) (1<= i < j <= N) is said to be good if gcd(Ai, Aj) = lcm(Ai, Aj).
    Here gcd denoted the greatest common divisor and lcm denotes the least common multiple.
    
    Find the total number of good pairs present in the given array.
    
    SAMPLE:
                    Input                       Output
                    4                           1
                    3                           2
                    1 2 1                       3
                    4                           5
                    11 11 16 16
                    5
                    2 5 2 2 8
                    8
                    1 4 4 8 2 8 8 12
    
    Input Format:
        1. The first line of input will contain a single integer T, denoting the number of test cases
        2. The first line of each test contains an integer of the length of the array A.
        3. The second line of each test case contains N space-separated integers A1, A2, ... An.
    
    Output Format:
        For each test case, output on a new line the total number of such good pairs possible in the given array
                   
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    // For the N no. of test cases
    int loops;
    cin>>loops;
    for(int i = 0; i < loops; i++){
        // Initialising the size of our DataStructure
        int size;
        cin>>size;
        // Here map will be used..Actually our idea will be to add that element to its respective index and increase that count value to 1
        // For example: if first element is 12..then at 12th index the value will be increased by 1.
        // Also in starting map automatically initialised all index to 0
        map<int, int> ans;
        for(int j = 1; j <= size; j++){
            // Asking for the input of the element in the next two lines
            int x;
            cin>>x;
            // Increasing the count
            ans[x]++;
        }
        // Initialising the variable to store the number of good pairs
        long long result = 0;
        for(auto it: ans){
            // storing the value of the element's count in final
            long long final = it.second;
            // This is the main idea..Suppose if you have 3 elements -> 1 1 1
            // Then you will be having 3 good pairs; Another way of looking at it is No. of good pairs = (freq(x) * (freq(x)-1))/2,
            // where freq(x) is the no. of times that particular element is in our data..
            result += (final * (final - 1))/2;
        }
        // printing out the result
        cout<<result<<endl;
    }
    return 0;
}
