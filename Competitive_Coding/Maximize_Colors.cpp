/*
  For the human eye, primary colours are red, green, and blue.

  Combining 1 drop each of any two primary colours produces a new type of secondary colour. For example, mixing red and green gives yellow, mixing green and 
  blue gives cyan, and, mixing red and blue gives magenta.

  You have X, Y and Z drops of red, green, and blue colours respectively. Find the maximum total number of distinct colours (both primary and secondary) 
  you can have at any particular moment.

  Note: You cannot mix a secondary colour with a primary or another secondary colour to get a new type of colour.
  
  SAMPLE:
                Input                   Output
                4                       2
                1 0 1                   3
                3 3 0                   3
                1 1 1                   0
                0 0 0
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    // For fast inputs and outputs
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
    int t;
    cin>>t;
    while(t--){
        // Asking the user for the drops
        int x, y, z;
        cin>>x>>y>>z;
        int cnt = 0;
        // Checking if each red, green and blue drop is present or not
        if(x > 1)
            cnt++;
        if(y > 1)
            cnt++;
        if(z > 1)
            cnt++;
        int ans = 0;
        // It will give us the result 0 0 0 -> 0 or 1 1 1 -> 3
        if(x > 0)
            ans++;
        if(y > 0)
            ans++;
        if(z > 0)
            ans++;
        // Making the pairs
        ans += ((cnt*(cnt-1))/2);
        // Finding the maxmimum and minimum drop value
        int mini = min({x, y, z});
        int maxi = max({x, y, z});
        // Only three cases possible
        if(mini == 2 && maxi == 2)
            cout<<4<<endl;
        else if(mini == 2)
            cout<<5<<endl;
        else
            cout<<ans<<endl;
    }

    return 0;
}
