#include<iostream>
#include<cmath>

using namespace std;

//Constants to represent type of solutions to an equation
const int NO_SOLUTION = 0;
const int ONE_REAL_SOLUTION = 1;
const int TWO_REAL_SOLUTIONS = 2;
const int ALL_REALS = 3;
const int NO_REAL_SOLUTION = 4;

//quadratic: Solves the quadaratic equation - ax^2 + bx + c = 0
//Input: a,b,c - coefficient of equation
//Output: 1. Type of solution(return value)
//        2. outX1, outX2 - solutions to equation (output parameters)
//Assumptions: 1. If equation has one solution it will be returned in outX1
//             2. If equation has no real solutions the value in outX1 and outX2 are not defined
int quadratic(double a, double b, double c, double& outX1, double& outX2);


//linear: Solves a linear equation - ax + b = 0
//Input: a, b - coefficients of equation
//Output: 1. Type of solution(return value)
//        2. outX - solution to equation (output parameters)
//Assumptions: If equation has no solutions the value returned at outX is not defined
int linear(double a, double b, double& outX);

int main(){
    double a, b, c, x1, x2;

    cout<<"Please enter the coefficient of quadratic equation: ";
    cin>>a>>b>>c;
    cout<<"The equation: "<<a<<"x^2 + "<<b<<"x + "<<c<<" = 0"<<endl;

    switch (quadratic(a,b,c,x1,x2)){
        case TWO_REAL_SOLUTIONS:
            cout<<"Solutions: "<<x1<<" "<<x2<<endl; break;
        case ONE_REAL_SOLUTION:
            cout<<"One solution: "<<x1<<endl; break;
        case NO_REAL_SOLUTION:
            cout<<"No real solution"<<endl; break;
        case NO_SOLUTION:
            cout<<"No solutions"<<endl; break;
        case ALL_REALS:
            cout<<"All real numbers are solutions"<<endl; break;
        default:
            cout<<"Error"<<endl; break;
    }
    return 0;
}

int quadratic(double a, double b, double c, double& outX1, double& outX2){
    double delta,x1,x2;
    if (a!=0.0){
        delta = b*b - 4*a*c;
        if (delta > 0){
            x1 = (-b + sqrt(delta))/(2*a);
            x2 = (-b - sqrt(delta))/(2*a);
            outX1 = x1;
            outX2 = x2;
            return TWO_REAL_SOLUTIONS;
        }
        else if (delta == 0){
            x1 = -b/(2*a);
            outX1 = x1;
            return ONE_REAL_SOLUTION;
        }
        else
            return NO_REAL_SOLUTION;
    }
    else
        return linear(b, c, outX1);
}

int linear(double a, double b, double& outX){
    double x;
    if (a != 0){
        x = -b/a;
        outX = x;
        return ONE_REAL_SOLUTION;
    }
    else if ((a == 0) && (b == 0)){
        x = 0;
        outX = x;
        return ALL_REALS;
    }
    else  // in this case a == 0 && b != 0
        return NO_SOLUTION;
}