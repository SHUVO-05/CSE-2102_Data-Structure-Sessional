// Traversing a Linear array
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
int main()
{

    int siz;
    cout<<"Enter array size: ";
    cin>>siz;
    int ar[siz];
    Scan_A(ar,siz);
    Print_A(ar,siz);
  return 0;
}
