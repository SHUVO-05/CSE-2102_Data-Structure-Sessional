//Binary Search
#include<iostream>
using namespace std;
void Print_A(int aray[],int len)
{
    cout<<"Array is: ";
    for(int i=0;i<=len;i++)
        cout<<aray[i]<<' ';
    cout<<endl;
}
int Binary_search(int ar[],int lb,int ub,int item)
{
   int mid;
   if(lb>ub) return -1;
   else{
    mid=(lb+ub)/2;
    if(item==ar[mid])return mid;
    else if(item<ar[mid])
        return Binary_search(ar,lb,mid-1, item);
        else Binary_search(ar,mid+1,ub,item);
   }

}
int main()
{

    int item,LB=0,UB, array[8]={33,51,67,85,99,123,313,457};
    UB=(sizeof(array)/4)-1;
    Print_A(array,UB);
    cout<<"Enter your item your want to search: ";
    cin>>item;
   int temp=Binary_search(array,LB,UB,item);

    if(temp!=-1)cout<<"Item "<<item<<" is found: "<<" at position "<<temp+1<<endl;
   else cout<<"Not found item"<<endl;
   return 0;
}

