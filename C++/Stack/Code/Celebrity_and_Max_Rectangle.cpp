/*
    1. Our first problem is celebrity problem..
       In this we are given a situation in which n persons went to a party..Out of those one is a celebrity
       - Celebrity is the person who don't know anyone in the party.
       - But everyone knows celebrity
       Our task is to find the celebrity from the given vector matrix
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
private:
    bool knows(vector<vector<int>> &M, int a, int b, int n)
    {
        if (M[a][b] == 1)
            return true;
        else
            return false;
    }

public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> s;
        // step1: push all elements in stack
        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }

        // step2: Take two elements out of stack and compare who knows the other...
        // if a person knows the other than he would be rejected and the other
        // person will be pushed back into the stack

        while (s.size() > 1)
        {

            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            if (knows(M, a, b, n))
                s.push(b);
            else
                s.push(a);
        }
        int candidate = s.top();
        // step3: single element in the stack will be our celebrity

        bool rowCheck = false;
        int zeroCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[candidate][i] == 0)
            {
                zeroCount++;
            }
        }

        // all zeroes
        if (zeroCount == n)
        {
            rowCheck = true;
        }

        // column check
        bool colCheck = false;
        int oneCount = 0;

        for (int i = 0; i < n; i++)
        {
            if (M[i][candidate] == 1)
                oneCount++;
        }

        if (oneCount == n - 1)
        {
            colCheck = true;
        }

        if (rowCheck == true && colCheck == true)
            return candidate;
        else
            return -1;
    }
};

/*
    2. Max Rectangle..
        In this problem we are given a binary Matrix M of size nXm. Find the maximum area of a rectangle
        formed only of 1s in the given matrix
*/
const int MAX = 4;
class Rectangle
{
private:
    vector<int> nextSmallerElement(int* arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (s.top() != -1 && s.top() > curr)
            {
                s.pop();
            }
            // ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(int* arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];
            while (s.top() != -1 && s.top() > curr)
            {
                s.pop();
            }
            // ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(int* heights, int n)
    {
        vector<int> next(n);
        next = nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int area = 0;
        for (int i = 0; i < n; i++)
        {
            int l = heights[i];

            if (next[i] == -1)
            {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newArea = l * b;
            area = max(area, newArea);
        }
        return area;
    }

public:
    int maxArea(int M[MAX][MAX], int n, int m)
    {
        //compute area for first row
        int area = largestRectangleArea(M[0], m);

        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                // row update: by adding previous rpw's value
                if (M[i][j] != 0)
                    M[i][j] = M[i][j] + M[i - 1][j];
                else
                    M[i][j]  = 0;
            }

            // entire row is updated now
            area = max(area, largestRectangleArea(M[i], m));
        }
        return area;
    }
};

int main()
{

    return 0;
}