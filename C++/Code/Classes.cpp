#include<iostream>
#include<cmath>
using namespace std;

class Simple_Calci{
    protected:
        float num1, num2;
    public:
        Simple_Calci(float a, float b){
            num1 = a;
            num2 = b;
        }
        int add(){
            return (num1 + num2);
        }
        int subtract(){
            return (num1 - num2);
        }
        int multiply(){
            return (num1 * num2);
        }
        float divide(){
            return (num1/num2);
        }
};

class Scientific_Calci{
    protected:
        float num, num0;
    public:
        Scientific_Calci(float c, float d = 0){
            num = c;
        }
        float Find_Log(){
            return log(num);
        }
        float Find_Sin(){
            return sin(num);
        }
        float Find_Cos(){
            return cos(num);
        }
        float Find_square(){
            return (num*num);
        }
};

class Compile : public Simple_Calci, public Scientific_Calci{
    public:
        Compile(float i, float j):Simple_Calci(i, j), Scientific_Calci(i){}
};

int main(){
    int val;
    float a, b, c, result;

    cout<<"THIS IS A CALCULATOR WHICH IS CAPABLE OF DOING TOTAL 8 OPERATIONS:"<<endl;
    cout<<"Press 1 for addition of two numbers..."<<endl;
    cout<<"Press 2 for Subtraction of two numbers..."<<endl;
    cout<<"Press 3 for Mulitplication of two numbers..."<<endl;    
    cout<<"Press 4 for Dividing two numbers..."<<endl;
    cout<<"Press 5 for finding log of a number..."<<endl;
    cout<<"Press 6 for finding Sin value of a number..."<<endl;
    cout<<"Press 7 for finding Cos value of a number..."<<endl;
    cout<<"Press 8 for finding square of a number..."<<endl;
    
    cin>>val;

    if (val >= 1 && val <= 4){
        cout<<"Enter num1: ";
        cin>>a;
        cout<<"Enter num2: ";
        cin>>b;
        Compile ob1(a, b);

        if (val == 1)
            result = ob1.add();
        else if (val == 2)
            result = ob1.subtract();
        else if (val == 3)
            result = ob1.multiply();
        else
            result = ob1.divide();
        cout<<"Your answer is: "<<result<<endl;
    }
    else if (val >= 5 && val <= 8){
        cout<<"Enter num: ";
        cin>>c;
        Compile ob2(c,0);

        if (val == 5)
            result = ob2.Find_Log();
        else if (val == 6)
            result = ob2.Find_Sin();
        else if (val == 7)
            result = ob2.Find_Cos();
        else
            result = ob2.Find_square();
        cout<<"Your answer is: "<<result<<endl;
    }
    else
        cout<<"Invalid operation!!...Type Carefully"<<endl;
        

    return 0;
}