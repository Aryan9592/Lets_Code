// Chef initially had two non-empty arrays A and B, where both arrays contain distinct elements. Moreover, there is no common element in the arrays A and B.

// Chef forms another array C from the arrays A and B using the following process :
// -Let X denote the leftmost element of array A and Y denote the leftmost element of array B.
// -If Y is smaller than X, delete Y from B and append it to the end of C.
// -If X is smaller than Y, delete X from A and append it to the end of C.
// -If either array A or B becomes empty, append all the remaining elements of the other array to the end of C.
  
// Chef forgot the arrays A and B but remembers the array C. Find any two valid non-empty arrays A and B that will yield the given array C. 
// If it is not possible, print -1.

//   SAMPLE:
//                      INPUT                         OUTPUT
//                      2                             3
//                      6                             7 6 3
//                      7 6 3 8 2 9                   3
//                      2                             8 2 9
//                      2 1                           -1


#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n;
	cin>>n;
  
  // create an array to store the elements
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
  // creating another two arrays, our plan is to fill the array a till any bigger element than the first element of arr encountered
	vector<int> a, b;
	int num = arr[0], flag = 1;
	for(int i = 0; i < n; i++){
		if(arr[i] <= num && flag)
			a.push_back(arr[i]);
		else{
			flag = 0;
			b.push_back(arr[i]);
		}
	}
  // If all elements got pushed into array a, then print -1
	if (a.size() == n){
		cout<<-1<<endl;
	}
  // else print the len and elements of the arrays a and b
	cout<<a.size()<<endl;
	for(int i:a){
		cout<<i<<" ";
	}
	cout<<endl;

	cout<<b.size()<<endl;
	for(int i:b){
		cout<<i<<" ";
	}
	cout<<endl;
}


int main(){
	// make input output fast
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	// testcases
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
