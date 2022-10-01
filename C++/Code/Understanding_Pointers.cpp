#include<iostream>
using namespace std;

int main(){
   char arr[5] = "abcd";
   char *p = &arr[2];
   cout<<*(p + 1)<<endl;
   return 0;
}