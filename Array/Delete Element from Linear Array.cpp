//Delete Element From Linear Array.
#include<iostream>
using namespace std;
void print(int ar[], int siz)
{
    for(int i=0;i<siz;i++)
        cout<<ar[i]<<' ';
        cout<<endl;
}
int Binary_search_recursive(int ar[],int lb,int ub,int item)
{
    int mid;
    if(lb>ub) return -1;
    else {
        mid=(lb+ub)/2;
        if(item==ar[mid])return mid;
        else if(item<ar[mid])
            return Binary_search_recursive(ar,lb,mid-1, item);
        else Binary_search_recursive(ar,mid+1,ub,item);
    }

}
void delete_from_array_given_position(int *ar, int *siz, int k)
{
    int j;
    j=k+1;
    while(j<=*siz)
    {
        ar[j-1]=ar[j];
        j++;
    }
    (*siz)--;
}

void delete_sorted_array(int *ar, int *siz, int item)
{
    int j,k;
    k=Binary_search_recursive(ar,0,*siz-1,item);
    if(k==-1) {
        cout<<" Element not in the array."<<endl;
        return;
    }
    j=k+1;
    while(j<=*siz)
    {   ar[j-1]=ar[j];
        j++;
    }
    (*siz)--;
}
int main()
{
     int pos,array[8]= {321,150,235,65,573,5,789,1278};
     int siz=(sizeof(array)/sizeof(array[0]));
     print(array,siz);
    cout<<" Enter your position you want to delete: ";
    cin>>pos;
    delete_from_array_given_position(array,&siz,pos);
    print(array,siz);
}
