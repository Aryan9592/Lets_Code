/*
    You are given an array A of length N.
    The interesting value of a subarray is defined as the product of the maximum and minimum elements of the subarray.
    Find the minimum and maximum interesting value over all subarrays for the given array.
    Note: A subarray is obtained by deletion of several (possibly zero) elements from the beginning of the array and several (possibly zero) elements from 
    the end of the array.
    
    SAMPLE:
                      Input                       Output
                      2                           9 9
                      2                           4 49
                      3 3
                      3
                      2 0 7
*/

#include <bits/stdc++.h>
using namespace std;

// defining it for the future long long use
#define ll long long

void solve(){
    // Asking the user to input size of array
    int n;
    cin>>n;
    
    // Intialsing our array
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        // Inserting the elements
        cin>>arr[i];
    }
    // Sorting the array
    sort(arr.begin(), arr.end());
    // Here the strategy was to find the maximum and minimum product in all the three cases of arrays formed...
    // The three cases are: 1. Array could consist of all positive numbers 2. Array could consist of all negative numbers 3. Array could consist of both positive and
    // negative numbers
    ll mx = max(arr[0]*(ll)arr[0], arr[n-1]*(ll)arr[n-1]);
    ll mn = min({arr[0]*(ll)arr[n-1], arr[0]*(ll)arr[0], arr[n-1]*(ll)arr[n-1]});
    cout<<mn<<" "<<mx<<endl;
}

int main() {
    // make input output fast
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    //testcase
    int t;
