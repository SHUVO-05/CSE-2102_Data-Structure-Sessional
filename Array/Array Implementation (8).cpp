// Array Implementation.
#include<conio.h>
#include<iostream>
#include<iomanip>
#define MAX 20
using namespace std;
void in_order_traverse(int ar[], int m)
{
    int i;
    cout<<"\n Array In_Order_Traverse: ";
    for(i=0; i<m; i++)
        cout<<ar[i]<<' ';
    cout<<endl;
}
void reverse_order_traverse(int ar[], int m)
{
    int i;
    cout<<"\n Reverse_Order_Traverse: ";
    for(i=m-1; i>=0; i--)
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
    int loc, i;
    for(i=1; i<siz; i++)
    {
        small_value(ar,siz,i,&loc);
        swap(ar[i-1],ar[loc]);
    }
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
void linear_search(int ar[],int siz,int item)
{
    int i=0;
    ar[siz]=item;
    while(ar[i]!=item)
    {
        i++;
    }
    if(i==siz)cout<<item<<" is not found "<<endl;
    else cout<<"Element is found   "<<i+1<<"  position"<<endl;
}

//Only use for sorted array.
void Binary_search(int ar[],int len,int item)
{
    int lb=0,ub=len-1,i,mid=(lb+ub)/2;
    while(lb<=ub&&ar[mid]!=item)
    {
        if(item<ar[mid])
            ub=mid-1;
        else
            lb=mid+1;
        mid=(lb+ub)/2;
    }
    if(ar[mid]==item)cout<<"Item "<<item<<" is found: "<<" at position "<<mid+1<<endl;
    else cout<<"Not found item"<<endl;
}
//Only use for sorted array.
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
    char h;
    int pos,item,choice, i, array[]= {321,150,235,65,573,5,789,1278};
    int size=(sizeof(array)/sizeof(array[0]));
    while(1) {
        cout<<"\n\n    Array Implementation    "<<endl;
        cout<<" ___________________________ "<<endl;
        cout<<" 0. Exit. "<<endl;
        cout<<" 1. In_order_Traverse. "<<endl;
        cout<<" 2. Reverse_order_Traverse. "<<endl;
        cout<<" 3. Bubble_Short. "<<endl;
        cout<<" 4. Insertion_Sort. "<<endl;
        cout<<" 5. Selection_Sort. "<<endl;
        cout<<" 6. Merge_Sort. "<<endl;
        cout<<" 7. Radix_sort. "<<endl;
        cout<<" 8. Quick Sort. "<<endl;
        cout<<" 9. Linear Search. "<<endl;
        cout<<"10. Binary Search(Only use for Sorted Array). "<<endl;
        cout<<"11. Insert Array. "<<endl;
        cout<<"12. Delet Item From Linear Array. "<<endl;
        cout<<"\n\n\t Enter your choice: "<<endl;
        cin>>choice;
        switch(choice)
        {
        case 0:
            return 0;
            break;
        case 1:
            in_order_traverse(array,size);
            cout<<" Press any key to continoue... ";
            h=getch();
            h=getch();
            break;
        case 2:
            reverse_order_traverse(array,size);
            cout<<" Press any key to continoue... ";
            h=getch();
            h=getch();
            break;
        case 3:
            bubble_sort(array,size);
            cout<<" Press any key to continoue... ";
            h=getch();
            h=getch();
            break;
        case 4:
            insertion_sort(array,size);
            cout<<" Press any key to continoue... ";
            h=getch();
            h=getch();
            break;
        case 5:
            selection_sort(array,size);
            cout<<" Press any key to continoue... ";
            h=getch();
            h=getch();
            break;
        case 6:
            merge_sort(array,0,size-1);
            cout<<" Press any key to continoue... ";
            h=getch();
            h=getch();
            break;
        case 7:
            radix_sort(array,size);
            cout<<" Press any key to continoue... ";
            h=getch();
            h=getch();
            break;
        case 8:
            quick_sort_recursive(array,0,size-1);
            cout<<" Press any key to continoue... ";
            h=getch();
            h=getch();
            break;
        case 9:
            cout<<" Type your item you want to search: ";
            cin>>item;
            linear_search(array,size,item);
            cout<<" Press any key to continoue... ";
            h=getch();
            h=getch();
            break;
        case 10:
            cout<<" Enter your Item you want to search: ";
            cin>>item;
            Binary_search(array,8,item);
            cout<<" Press any key to continoue... ";
            h=getch();
            h=getch();
            break;
        case 11:
            cout<<" Enter your Item & Position your want to insert: ";
            cin>>item>>pos;
            insert_array_given_position(array,&size,item,pos);
            cout<<" Press any key to continoue... ";
            h=getch();
            h=getch();
            break;
        case 12:
            cout<<" Enter your position you want to delete: ";
            cin>>pos;
            delete_from_array_given_position(array,&size,pos);
            cout<<" Press any key to continoue... ";
            h=getch();
            h=getch();
            break;


        }
    }
}
