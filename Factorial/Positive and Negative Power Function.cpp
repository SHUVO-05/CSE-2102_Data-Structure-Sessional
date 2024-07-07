// Power function using for/while loop
#include<iostream>
using namespace std;
long double power(long double m, long double n)
{
    if(n==0) return 1;
    else{
        long double i, result=m,temp=n;
            n=abs(n);
        for(i=1;i<n;i++)
            result*=m;
    if(temp<0)return (1/result);
        return result;
    }
}
//long double power(long double m, long double n)
//{
//    if(n==0) return 1;
//    else{
//        long double i=1, result=m;
//       while(i<n){
//            i++;
//            result*=m;
//       }
//        return result;
//    }
//}
int main()
{

    long double number,pr;
    while(1){
            cout<<"Enter integer number and power value: ";
    cin>>number>>pr;

    cout<<"\n Factorial is: "<<power(number,pr)<<endl;}
}

