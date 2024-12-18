//Merge Sort.
#include<iostream>
using namespace std;
#define MAX 20
void print(int ar[], int siz)
{
    for(int i=0;i<siz;i++)
        cout<<ar[i]<<' ';
        cout<<endl;
}
void subArray(int ar[], int lb, int lr,int rb, int rr)
{
    int na=lb, nb=rb, nc=lb, k, c[MAX];
    while((na<=lr)&&(nb<=rr))
    {   if(ar[na]<ar[nb])c[nc++]=ar[na++];
        else c[nc++]=ar[nb++];
    }
    if(na>lr) {
        while(nb<=rr)c[nc++]=ar[nb++];
    }
    else {
        while(na<=lr)c[nc++]=ar[na++];
    }
    for(k=lb; k<=rr; k++)
        ar[k]=c[k];

}

void merge_sort(int ar[], int st, int ed)
{
    int mid;
    if(st<ed)
    {   mid=(st+ed)/2;
        merge_sort(ar,st,mid);
        merge_sort(ar,mid+1,ed);
        subArray(ar,st,mid,mid+1,ed);
    }
//    print(ar,7);
}
int main()
{
    int Array[7]={56,0,5,0,3,9,1};
    print(Array,7);
    merge_sort(Array,0,7-1);
    print(Array,7);
}
