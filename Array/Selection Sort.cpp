//Selection Sort.
#include<iostream>
using namespace std;
void print(int ar[], int siz)
{
    for(int i=0;i<siz;i++)
        cout<<ar[i]<<' ';
        cout<<endl;
}
void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void small_value(int ar[], int n, int k, int *loc)
{
    int small, j;
    small=ar[k-1];
    *loc=k-1;
    for(j=k; j<n; j++)
    {
        if(ar[j]<small)
        {   small=ar[j];
            *loc=j;
        }
    }
}
void selection_sort(int ar[], int siz)
{
    int loc, i;
    for(i=1; i<siz; i++)
    {
        small_value(ar,siz,i,&loc);
        swap(ar[i-1],ar[loc]);
    }
}
int main()
{
    int Array[7]={56,0,5,0,3,9,1};
    print(Array,7);
    selection_sort(Array,7);
    print(Array,7);
}
