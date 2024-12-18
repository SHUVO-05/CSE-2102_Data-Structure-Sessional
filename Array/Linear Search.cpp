//Linear Search.
#include<iostream>
using namespace std;
void print(int ar[], int siz)
{
    for(int i=0;i<siz;i++)
        cout<<ar[i]<<' ';
        cout<<endl;
}
void linear_search(int ar[],int siz,int item)
{
    int i=0;
    ar[siz]=item;
    while(ar[i]!=item)
    {
        i++;
    }
    if(i==siz)cout<<item<<" is not found "<<endl;
    else cout<<"Element is found   "<<i+1<<"  position"<<endl;
}
int main()
{
    int item,Array[8]= {321,150,235,65,573,5,789,1278};
    print(Array,8);
    cout<<" Type your item you want to search: ";
    cin>>item;
    linear_search(Array,8,item);
}
