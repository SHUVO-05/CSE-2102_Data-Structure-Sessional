//Linear Search
#include<iostream>
using namespace std;
void linear_search(int ar[],int len,int item)
{
   int i,flag;
   ar[len]=item;
   while(ar[i]!=item)
   {
       i++;
   }
   if(i==len)cout<<item<<" is not found "<<endl;
   else cout<<"Element is found   "<<i+1<<"  position"<<endl;
}
int main()
{

    int item, ar[8]={33,51,27,85,66,23,13,57};
    cout<<"Enter your item your want to search: ";
    cin>>item;
    linear_search(ar,8,item);
   return 0;
}
