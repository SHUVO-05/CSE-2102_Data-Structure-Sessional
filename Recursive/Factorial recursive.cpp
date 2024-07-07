// Factorial using Recursive.
#include<iostream>
using namespace std;
long double factorial(int n)
{
    if(n==0) return 1;
    return n*factorial(n-1);
}
int main()
{

    int number;
    while(1){
            cout<<"Enter integer number:";
    cin>>number;
    cout<<"\n Factorial is: "<<factorial(number)<<endl;}
}
