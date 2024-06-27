// Various operations on linked stack.
#include<iostream>
#include<conio.h>
using namespace std;
//#define MAX 10
struct stack
{
    int info;
    struct stack *next;
};
//stack *top;
void createStack(stack **top)
{
    *top=NULL;
}
bool isEmpty(stack *top)
{
    return((top==NULL)?true:false);
}
//bool isFull(stack *top)
//{
//    return((top->info=(MAX-1))?true:false);
//}
void push(stack **top,int value)
{
    char c;
    stack *point=(stack*)malloc(sizeof(stack));
    if(point==NULL){
        cout<<"Unable to allocate to memory\n press any key to continue.."<<endl;
        c=getch();
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
//int peek(stack *top)
//{
//    return (top->info);
//}
int peek(stack *top) {
    char ch;
  if (isEmpty(top)) {
        cout<<" Stack is Empty. press any key to continue."<<endl;
        ch=getch();
  } else {
    cout<<" Value is "<<top->info<<endl;
  }
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
int main()
{
    char c;
    int choice, element;
    stack *top;
    createStack(&top);
    do
    {
        cout<<"     Options available"<<endl;
        cout<<" -----------------------"<<endl;
        cout<<" 1. Push."<<endl;
        cout<<" 2. Pop."<<endl;
        cout<<" 3. Peek."<<endl;
        cout<<" 4. Delete Stack."<<endl;
        cout<<" 5. Exit."<<endl<<endl;
        cout<<" Enter your choice (1-5): ";
        cin>>choice;
        switch(choice)
        {
        case 1:
//            if(isFull(top))
//            {
//                cout<<" Stack is full, press any key to continue"<<endl;
//                    c=getch();
//            }else{
            cout<<"Enter value:";
            cin>>element;
            push(&top,element);
            break;
        case 2:
            if(isEmpty(top)){
                cout<<" Stack is Empty. press any key to continue."<<endl;
                c=getch();
            }
            else{
                cout<<"Value Poped is "<<pop(&top)<<endl;
                cout<<" Press any key to continue...."<<endl;
                c=getch();
            }break;
        case 3:
            peek(top);
            break;
        case 4:
            disposeStack(&top);
            break;
        }
        }while (choice!=5);


    return 0;
}
