// Factorial using for/while loop
#include<iostream>
using namespace std;
//long double factorial(long double n)
//{
//    if(n==0) return 1;
//    else{
//        long double i, fact=1;
//        for(i=2;i<=n;i++)
//            fact*=i;
//        return fact;
//    }
//}
long double factorial(long double n)
{
    if(n==0) return 1;
    else{
        long double i=2, fact=1;
       while(i<=n){
            fact*=i;i++;
       }
        return fact;
    }
}
int main()
{

    long double number;
    while(1){
            cout<<"Enter integer number:";
    cin>>number;
    cout<<"\n Factorial is: "<<factorial(number)<<endl;}
}
