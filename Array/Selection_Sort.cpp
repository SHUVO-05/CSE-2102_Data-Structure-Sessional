// Selection Sort.
#include<iostream>
using namespace std;
void print(int ar[], int siz)
{
    for(int i=0; i<siz; i++)
        cout<<ar[i]<<" ";
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
    int temp, loc, i;
    for(i=1; i<siz; i++)
    {   small_value(ar,siz,i,&loc);
    swap(ar[i-1],ar[loc]);
    /*
        temp=ar[i-1];
        ar[i-1]=ar[loc];
        ar[loc]=temp;*/
    }
}

void insertionSort(int ar[], int siz)
{
    int j,k,temp;
    for(k=1; k<siz; k++)
    {
        temp=ar[k];
        j=k-1;
        while((temp>ar[j])&&(j>=0))
        {
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1]=temp;
    }
}


int main()
{
    int array[7]= {7, 5,8, 4, 1, 9, 2};
    print(array,7);
    selection_sort(array, 7);

    print(array, 7);
}