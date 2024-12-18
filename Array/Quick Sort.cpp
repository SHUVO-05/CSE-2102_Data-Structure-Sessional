//Quick Sort.
#include<iostream>
using namespace std;
void print(int ar[], int siz)
{
    for(int i=0;i<siz;i++)
        cout<<ar[i]<<' ';
        cout<<endl;
}
void subarray(int ar[], int beg, int end, int *loc)
{
    int left, right, temp;
    bool done=false;
    *loc=left=beg;
    right=end;
    while(!done)
    {
        while((ar[*loc]<=ar[right])&&(*loc!=right))right--;
        if(*loc==right)done=true;
        else {
            temp=ar[*loc];
            ar[*loc]=ar[right];
            ar[right]=temp;
            *loc=right;
        }
        if(!done) {
            while((ar[*loc]>=ar[left])&&(*loc!=left))left++;
            if(*loc==left)done=true;
            else {
                temp=ar[*loc];
                ar[*loc]=ar[left];
                ar[left]=temp;
                *loc=left;
            }
        }
    }
}
void quick_sort_recursive(int ar[],int lb, int ub)
{   int loc;
    if(lb<ub)
    {
        subarray(ar,lb,ub,&loc);
        quick_sort_recursive(ar,lb,loc-1);
        quick_sort_recursive(ar,loc+1,ub);
    }
}
int main()
{
    int Array[7]={56,0,5,0,3,9,1};
    print(Array,7);
    quick_sort_recursive(Array,0,7-1);
    print(Array,7);
}
