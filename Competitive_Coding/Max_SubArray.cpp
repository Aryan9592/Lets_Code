/*
  Given two arrays A and B of sizes N and M respectively. You can apply the following operation until the array B is non-empty:
  - Choose either the first or the last element of array B.
  - Insert the chosen element to either the front or the back of array A.
  - Delete the chosen element from array B.
  
 Find the maximum sum of any subarray of the array A that you can achieve after performing exactly M operations.
 
 Note: A subarray of an array is formed by deleting some (possibly zero) elements from the beginning of the array and some (possible zero) elements 
       from the end of the array. A subarray can be empty as well.
       
 SAMPLE:
                      INPUT                 OUTPUT
                      3                     205
                      5                     81
                      3 26 -79 72 23        24
                      2
                      66 44
                      1
                      81
                      1
                      -97
                      5
                      10 -5 14 -20 4
                      3
                      -10 5 -2
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int mod = 1000000007;

// Using kadane's algorithm here
int kadane(vector<int> &v){
	int global_max = INT_MIN, local_max = INT_MIN;
	int n = v.size();
	for(int i = 0; i < n; i++){
		local_max = max(local_max + v[i], v[i]);
		global_max = max(global_max, local_max);
	}
	return global_max;
}

void solve(){
	int n; cin>>n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin>>a[i];
	
	int m; cin>>m;
	vector<int> b(m), pos;
	for(int i = 0; i < m; i++){
		cin>>b[i];

		if(b[i] > 0)
			pos.push_back(b[i]);
	}

	// adding +ve elements of B to the rear side of A
	vector<int> temp1 = a;
	for(int i = 0; i < pos.size(); i++) temp1.push_back(pos[i]);

	// adding +ve elements of B to the front side of A
	vector<int> temp2 = pos;
	for(int i = 0; i < n; i++) temp2.push_back(a[i]);

	int left = kadane(temp1);
	int right = kadane(temp2);

	cout<<max(left, right)<<endl;
}

int main(){
	// for fast inputs and outputs
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int tc;
	cin>>tc;

	while(tc--){
		solve();
	}
	return 0;
}
