/*
  Chef is a very lazy person. Whatever work is supposed to be finished in x units of time, he finishes it in m * x units of time. But there is always a limit to 
  laziness, so he delays the work by at max d units of time. Given x, m, d find the maximum time taken by Chef to complete the work.
  
  SAMPLE:
                Input               Output
                3                   1
                1 1 0               2
                1 3 1               4
                2 2 3
*/

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int a, b, c;
	    cin>>a>>b>>c;
	    if (c == 0)
	        cout<<a<<endl;
	    else{
	        int mul = a*b;
	        for (int i = 0; i < c; i++){
	            if (a >= mul)
	                break;
	            else
	                a++;
	        }
	        cout<<a<<endl;
	    }
	}
	return 0;
}
