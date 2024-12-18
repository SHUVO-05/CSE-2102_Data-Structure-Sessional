//Radix Sort.
#include<iostream>
using namespace std;
void print(int ar[], int siz)
{
    for(int i=0;i<siz;i++)
        cout<<ar[i]<<' ';
        cout<<endl;
}
void radix_sort(int ar[], int siz)
{
    int i,j,k,r,digitCount=0,divisor=1,largest=ar[0],pN,radix[10][20],rCount[10];
    for(i=1; i<siz; i++)
        if(largest<ar[i])largest=ar[i];
    while(largest>0)
    {
        digitCount++;
        largest/=10;
    }
    for(pN=0; pN<digitCount; pN++)
    {
        for(k=0; k<10; k++)
            rCount[k]=0;
        for(i=0; i<siz; i++)
        {
            r=(ar[i]/divisor)%10;
            radix[r][rCount[r]++]=ar[i];
        }
        i=0;
        for(k=0; k<10; k++)
        {
            for(j=0; j<rCount[k]; j++)
                ar[i++]=radix[k][j];
        }
        divisor*=10;
    }
}
int main()
{
    int Array[7]={56,0,5,0,3,9,1};
    print(Array,7);
    radix_sort(Array,7);
    print(Array,7);
}
