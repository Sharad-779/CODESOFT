#include<iostream>
using namespace std;
int main(){
    char calculate;
    int num1,num2;
    cout<<"Enter the Operator"<<" ";
    cin>>calculate;
    cout<<"Enter 1st Number"<<" ";
    cin>>num1;
    cout<<"Enter 2nd Number"<<" ";
    cin>>num2;
    switch(calculate){
        case '+':
        cout<<num1+num2<<endl;
        break;
        case '-':
        cout<<num1-num2<<endl;
        break;
        case '*':
        cout<<num1*num2<<endl;
        break;
        case '/':
        cout<<num1/num2<<endl;
        break;
        default:
        cout<<"ERROR ,Incorrect Operator"<<endl;
        break;
    }
    return 0;
}
