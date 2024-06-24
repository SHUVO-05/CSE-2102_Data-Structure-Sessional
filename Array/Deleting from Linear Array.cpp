//Deleting from a Linear Array
#include<iostream>
using namespace std;
void Print_A(int aray[],int len)
{
    cout<<"Array is: ";
    for(int i=0;i<len;i++)
        cout<<aray[i]<<' ';
    cout<<endl;
}

void Scan_A(int aray[],int len)
{
    for(int i=0;i<len;i++)
    {
    cout<<"Enter your "<<i+1<<"th element: ";
        cin>>aray[i];

    }
}
void delet_A(int ar[], int &siz,int position)
{
    int  flag=-1;
    while(position>=0&&position<siz)
    {
        ar[position]=ar[position+1];
        position++;
        flag=1;
    }
    if(flag==1)
    siz--;
    else cout<<"Position Invalid"<<endl;
}
int main()
{

    int siz,position;
    cout<<"Enter array size: ";
   cin>>siz;
    int ar[siz];
    Scan_A(ar,siz);
    Print_A(ar,siz);
    cout<<"Enter your deleting position: ";
    cin>>position;
    delet_A(ar,siz,position);
    Print_A(ar,siz);
   return 0;
}
