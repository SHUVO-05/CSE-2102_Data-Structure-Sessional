//Insertion Sort.
#include<iostream>
using namespace std;
void print(int ar[], int siz)
{
    for(int i=0;i<siz;i++)
        cout<<ar[i]<<' ';
        cout<<endl;
}
void insertion_sort(int ar[], int siz)
{
    int j,k,temp;
    for(k=1; k<siz; k++)
    {
        temp=ar[k];
        j=k-1;
        while((temp<ar[j])&&(j>=0))
        {
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1]=temp;
    }
}
int main()
{
    int Array[7]={56,0,5,0,3,9,1};
    print(Array,7);
   insertion_sort(Array,7);
    print(Array,7);
}
