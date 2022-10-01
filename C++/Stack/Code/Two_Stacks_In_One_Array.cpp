#include<iostream>
using namespace std;

class TwoStack{
    int *arr;
    int top1;
    int top2;
    int size;

    public:
        TwoStack(int s){
            this -> size = s;
            top1 = -1;
            top2 = s;
            arr = new int[s];
        }

        void push1(int num){
            // atleast a empty space present
            if ((top2 - top1) > 1 ){
                top1++;
                arr[top1] = num;
            }
            else{
                cout<<"Stack OverFlow"<<endl;
            }
        }

        void push2(int num){
            // atleast a empty space present
            if ((top2 - top1) > 1 ){
                top2--;
                arr[top1] = num;
            }
            else{
                cout<<"Stack OverFlow"<<endl;
            }
        }

        int pop1(){
            if (top1 >= 0){
                int ans = arr[top1];
                top1--;
                return ans;
            }
            else{
                return -1;
            }
        }

        int pop2(){
            if (top2 < size){
                int ans = arr[top2];
                top2++;
                return ans;
            }
            else{
                return -1;
            }
        }
};

int main(){
    
    return 0;
}

