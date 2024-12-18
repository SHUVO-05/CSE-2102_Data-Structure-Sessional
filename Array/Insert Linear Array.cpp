//Insert Linear Array.
#include<iostream>
using namespace std;
void print(int ar[], int siz)
{
    for(int i=0;i<siz;i++)
        cout<<ar[i]<<' ';
        cout<<endl;
}
void insert_array_given_position(int *ar,int *siz, int item, int k)
{   int j;
    j=*siz-1;
    while(j>=k) {
        ar[j+1]=ar[j];
        j--;
    }
    ar[k]=item;
    (*siz)++;
}

void insert_sorted_array(int *ar, int *siz, int item)
{
    int k;
    k=*siz-1;
    while((item<ar[k])&&(k>=0))
    {   ar[k+1]=ar[k];
        k--;
    }
    ar[k+1]=item;
    (*siz)++;

}
int main()
{
    int item,pos,array[8]= {321,150,235,65,573,5,789,1278};
    int siz=sizeof(array)/sizeof(array[0]);
    print(array,siz);
    cout<<" Enter your Item & Position your want to insert: ";
    cin>>item>>pos;
    insert_array_given_position(array,&siz,item,pos);
}
