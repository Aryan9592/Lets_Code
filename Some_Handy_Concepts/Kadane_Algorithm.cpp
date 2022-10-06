/*
  This algorithm is used to find the maximum sum of the contiguous subarrays from a given array..
  For e.g - Let's an array A -> [-2, 1, -3, 4, -1, 2, 1, -5, 4]
            Then the maximum sum of any subarray of A is 6 and the subarray is [4, -1, 2, 1]
            
  Time Complexity - O(n)
  Approach - Initially there will be two variables..One used for storing the global maximum sum and the other will be used for storing the local sum.
           - Sum will be initialised to 0 and the maximum sum will be initialised to the first element of the array..Let MAX be the global maximum and SUM be the local
             one.
           - Then we will be iterating on each element and perfoming the following three steps:
           -  1. adding the element to the current sum -> SUM += curr_element
              2. updating the maxi element if SUM becomes greater than MAX else keeping MAX the same
              3. if current sum is less than 0 then make SUM = 0 else no effect
           - At last we will display the maximum element
*/

#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums){
	int sum = 0;
	int maxi = nums[0];

	for(int i = 0; i < nums.size(); i++){
		sum += nums[i];
		maxi = max(sum, maxi);

		if (sum < 0)
			sum = 0;
	}
	return maxi;
}

int main(){
	vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout<<maxSubArray(nums)<<endl;
	return 0;
}
