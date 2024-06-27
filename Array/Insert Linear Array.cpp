// Inserting a Linear array
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
void insert_A(int ar[], int &siz,int position,int item)
{

    int j=siz;
    if(position>(j+1)){cout<<"Position Invalid"<<endl; exit(1);}
    while(j>=position)
    {
        ar[j+1]=ar[j];
        j--;
    }
    ar[position]=item;
    siz++;
}
int main()
{

    int siz,item,position;
    cout<<"Enter array size: ";
   cin>>siz;
    int ar[siz];
    Scan_A(ar,siz);
    Print_A(ar,siz);
    cout<<"Enter item & position which position you insert: ";
    cin>>item>>position;
    insert_A(ar,siz,position,item);
    Print_A(ar,siz);
   return 0;
}
