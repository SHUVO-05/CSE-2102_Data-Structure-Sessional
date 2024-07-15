// Implementation of Quicksort algorithm.
#include<iostream>
using namespace std;
#define MAX 10
struct stack
{
    int info;
    struct stack *next;
};
void createStack(stack **top)
{
    *top=NULL;
}
bool isEmpty(stack *top)
{
    return((top==NULL)?true:false);
}
void push(stack **top,int value)
{
    stack *point=(stack*)malloc(sizeof(stack));
    if(point==NULL){
        cout<<"Unable to allocate to memory\n press any key to continue.."<<endl;
    }
    point->info=value;
    point->next=*top;
    *top=point;
}
int pop(stack **top)
{
    int temp;
    stack *point;
    temp=(*top)->info;
    point=(*top);
    (*top)=(*top)->next;
    free(point);
    return temp;
}
void disposeStack(stack **top)
{
    stack *point;
    while(*top!=NULL)
    {
        point=*top;
        *top=(*top)->next;
        free(point);
    }
}
void reduction(int a[],int beg,int end, int *loc)
{
    int left,right,temp;
    bool done;
    left=*loc=beg;
    right=end;
    while(!done)
    {
        while((a[*loc]<=a[right])&&(*loc!=right))
            right--;
        if(*loc==right) done=true;
        else{
            temp=a[*loc];
            a[*loc]=a[right];
            a[right]=temp;
            *loc=right;
        }
    if(!done)
    {
        while((a[*loc]>=a[left])&&(*loc!=left))
            left++;
        if(*loc==left)done=true;
        else
        {
            temp=a[*loc];
            a[*loc]=a[left];
            a[left]=temp;
            *loc=left;
        }
    }
  }
}
void QuickSortIterative(int a[],int n)
{
    int loc,beg,end;
    stack *top;
    createStack(&top);
    push(&top,0);
    push(&top,n-1);
    while(!isEmpty(top)){
        end=pop(&top);
        beg=pop(&top);
        reduction(a,beg,end,&loc);
        if(beg<loc-1){
            push(&top,beg);
            push(&top,loc-1);
        }
        if(end>loc+1)
        {
            push(&top,loc+1);
            push(&top,end);
        }
    }

}
int main()
{
    int i,n,a[MAX];
    cout<<"\nEnter the number of elements in array: ";
    cin>>n;
    if(n>MAX)
    {
         cout<<"Input size of any greater the declared size."<<endl;exit(1);
    }
    cout<<"\n Enter "<<n<<"elements"<<endl<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    QuickSortIterative(a,n);
    cout<<"\n\n Sorted list of elements"<<endl<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<' ';
    }
return 0;
}