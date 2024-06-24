
//Bubble sort
#include<iostream>
using namespace std;
void Print_A(int aray[],int len)
{

    for(int i=0;i<len;i++)
        cout<<aray[i]<<' ';
    cout<<endl;
}

void swap_v(int &a, int &b)
{
    int tmp=a;
    a=b;
    b=tmp;
}
void Bubble_sort(int ar[], int len)
{
    int i,j,flag;
    for(i=0;i<len-1;i++)
       {
            flag=0;
        for(j=0;j<len-i-1;j++)
        {
        if(ar[j]>ar[j+1])
            {swap_v(ar[j],ar[j+1]);
            flag=1;
            }

        }
        if(flag==0)break;
    }
}
int main()
{

    int ar[8]={33,51,27,85,66,23,13,57};
     cout<<"Unsorted Array : ";
    Print_A(ar,8);
     cout<<"Your sorted Array : ";
    Bubble_sort(ar,8);
    Print_A(ar,8);
   return 0;
}
