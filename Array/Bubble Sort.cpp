//Bubble Sort.
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
void bubble_sort(int array[], int siz)
{
    int i,j,flag;
    for(i=0; i<siz-1; i++)
    {
        flag=0;
        for(j=1; j<siz-i; j++)
        {
            if(array[j-1]>array[j])
            {   swap(array[j-1],array[j]);
                flag=1;
            }

        }
        if(flag==0)break;
    }
}
int main()
{
    int Array[7]={56,0,5,0,3,9,1};
    print(Array,7);
    bubble_sort(Array,7);
    print(Array,7);
}
