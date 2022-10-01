/*
    In this we will be given a histogram graph (the graph in which many rectangles bars are stacked together)..
    Our motive is to find the largest rectangle there...
    Our Approach will be...as we know the width of all bars will be constant in start..But here we can extend them
    with one condition...Like a bar of length 4 can't be extend its width in bar of length 3..but it can extend in bar
    of length 5...
    Hence what we will do is...find the previous and next smaller lengths of rectangles to which we are working
    Then extend the area of our bar..and find the area
    Doing this process with each of the rectangle ..we will get the largest area
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution{
    private:
        vector<int> nextSmallerElement(vector<int> arr, int n){
            stack<int> s;
            s.push(-1);
            vector<int> ans(n);

            for(int i = n-1; i >= 0; i--){
                int curr = arr[i];
                while(s.top() != -1 && s.top() > curr)
                {
                    s.pop();
                }
                // ans is stack ka top
                ans[i] = s.top();
                s.push(i);
            }
            return ans;
        }

        vector<int> prevSmallerElement(vector<int> arr, int n){
            stack<int> s;
            s.push(-1);
            vector<int> ans(n);

            for(int i = 0; i < n; i++){
                int curr = arr[i];
                while(s.top() != -1 && s.top() > curr)
                {
                    s.pop();
                }
                // ans is stack ka top
                ans[i] = s.top();
                s.push(i);
            }
            return ans;
        }
    public:
        int largestRectangleArea(vector<int> &heights){
            int n = heights.size();

            vector<int> next(n);
            next = nextSmallerElement(heights, n);

            vector<int> prev(n);
            prev = prevSmallerElement(heights, n);

            int area = 0;
            for(int i = 0; i < n; i++){
                int l = heights[i];

                if(next[i] == -1){
                    next[i] = n;
                }
                int b = next[i] - prev[i] - 1;
                int newArea = l*b;
                area = max(area, newArea);
            }
            return area;
        }
};

int main(){
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    Solution s;
    int result = s.largestRectangleArea(heights);
    cout<<result<<endl;
    return 0;
}