// Try code.
#include<iostream>
using namespace std;
void print(int *arr, int siz)
{
    for(int i=0; i<siz; i++)
        cout<<arr[i]<<' ';
    cout<<endl;
}
void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void small(int ar[], int siz, int k, int *loc)
{
    int small,j;
    small=ar[k-1];
    *loc=k-1;
    for(j=k; j<siz; j++)
    {
        if(ar[j]<small)
        {   small=ar[j];
            *loc=j;
        }
    }
}
void selection_sort(int ar[], int siz)
{
    int i,loc;
    for(i=1; i<siz; i++)
    {
        small(ar,siz,i,&loc);
        swap(ar[i-1],ar[loc]);
    }
}
void insertion_sort(int ar[],int siz)
{
    int temp,j,k;
    for(k=1; k<siz; k++)
    {
        temp=ar[k];
        j=k-1;
        while((ar[j]>temp)&&(j>=0))
        {
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1]=temp;
    }
}
void Radix_sort(int ar[], int siz)
{
    int bucket[10][20], buckCount[10];
    int i,j,k,r,digitCount=0, divisor =1, largest, passNo;
    largest=ar[0];
    for(i=1; i<siz; i++)
    {
        if(ar[i]>largest)largest=ar[i];
    }
    while(largest>0)
    {
        digitCount++;
        largest/=10;
    }
    for(passNo=0; passNo<digitCount; passNo++)
    {
        for(k=0; k<10; k++)
            buckCount[k] = 0;
        for(i=0; i<siz; i++)
        {
            r=(ar[i]/divisor)%10;
            bucket[r][buckCount[r]++]=ar[i];
        }
        i=0;
        for(k=0; k<10; k++)
        {
            for(j=0; j<buckCount[k]; j++)
                ar[i++]=bucket[k][j];
        }
        divisor*=10;
    }
}

int main()
{
    int array[8]= {321,150,235,65,573,789,928,542};
    print(array,8);
//Radix_sort(array,8);
//selection_sort(array,8);
//   insertion_sort(array,10);
    print(array,8);
}