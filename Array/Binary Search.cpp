//Binary Search.
#include<iostream>
using namespace std;
void print(int ar[], int siz)
{
    for(int i=0;i<siz;i++)
        cout<<ar[i]<<' ';
        cout<<endl;
}
//Only use for sorted array.
void Binary_search(int ar[],int len,int item)
{
    int lb=0,ub=len-1,i,mid=(lb+ub)/2;
    while(lb<=ub&&ar[mid]!=item)
    {
        if(item<ar[mid])
            ub=mid-1;
        else
            lb=mid+1;
        mid=(lb+ub)/2;
    }
    if(ar[mid]==item)cout<<"Item "<<item<<" is found: "<<" at position "<<mid+1<<endl;
    else cout<<"Not found item"<<endl;
}
//Only use for sorted array.
int Binary_search_recursive(int ar[],int lb,int ub,int item)
{
    int mid;
    if(lb>ub) return -1;
    else {
        mid=(lb+ub)/2;
        if(item==ar[mid])return mid;
        else if(item<ar[mid])
            return Binary_search_recursive(ar,lb,mid-1, item);
        else Binary_search_recursive(ar,mid+1,ub,item);
    }

}
int main()
{
    int item,Array[8]= { 5, 65, 150, 235, 321, 573, 789, 1278};
    print(Array,8);
    cout<<" Enter your Item you want to search: ";
    cin>>item;
    Binary_search(Array,8,item);
}
