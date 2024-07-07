// Factorial using Recursive.
#include<iostream>
using namespace std;
long double factorial(long double n)
{
    if(n==0) return 1;
    return n*factorial(n-1);
}
int main()
{

    long double number;
    while(1){
            cout<<"Enter integer number:";
    cin>>number;
    cout<<"\n Factorial is: "<<factorial(number)<<endl;}
}
