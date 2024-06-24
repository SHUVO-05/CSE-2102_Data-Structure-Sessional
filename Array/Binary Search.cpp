//Binary Search
#include<iostream>
using namespace std;
void Print_A(int aray[],int len)
{
    cout<<"Array is: ";
    for(int i=0;i<len;i++)
        cout<<aray[i]<<' ';
    cout<<endl;
}
void Binary_search(int ar[],int len,int item)
{
   int lb=0,ub=len,i,mid=(lb+ub)/2;
   while(lb<=ub&&ar[mid]!=item)
   {
       if(item<ar[mid])
        ub=mid-1;
       else
        lb=mid+1;
        mid=(lb+ub)/2;
   }
   if(ar[mid]==item)cout<<"Item is found: "<<endl;
   else cout<<"Not found item"<<endl;
}
int main()
{

    int item, ar[8]={33,51,67,85,99,123,313,457};
    Print_A(ar,8);
    cout<<"Enter your item your want to search: ";
    cin>>item;
    Binary_search(ar,8,item);
   return 0;
}
