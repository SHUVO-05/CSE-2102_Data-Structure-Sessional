// Insertion sort.
#include<iostream>
using namespace std;
void print(int ar[], int siz)
{
    for(int i=0; i<siz; i++)
        cout<<ar[i]<<" ";
    cout<<endl;
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
    insertionSort(array, 7);
    
    print(array, 7);
}