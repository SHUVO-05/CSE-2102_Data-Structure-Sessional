//Array Based Stack Implementation.
#include <iostream>
#include<conio.h>
using namespace std;
#define MAX 10
struct stack
{
    int top;
    int elements[MAX];
};
//stack s;
void createStack(stack *ps)
{
    ps->top=-1;
}
bool isEmpty(stack *ps)
{
    return ((ps->top==-1)?true:false);
}
bool isFull(stack *ps)
{
    return ((ps->top==MAX-1)?true:false);
}
void push(stack *ps, int value)
{
    ps->elements[++ps->top]=value;
}
int pop(stack *ps)
{
    return (ps->elements[ps->top--]);
}
int peek(stack *ps)
{
    return (ps->elements[ps->top]);
}
int main()
{
    int choice, element;
    char c;
    stack s;
    createStack(&s);
    do
    {
        cout<<"    Options available  "<<endl;
        cout<<"-------------------------"<<endl;
        cout<<" 1. Push."<<endl;
        cout<<" 2. Pop."<<endl;
        cout<<" 3. Peek."<<endl;
        cout<<" 4. exit. "<<endl<<endl;
        cout<<" Enter your choice (1-4): ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            if(isFull(&s))
            {
                cout<<" Stack is full, press any key to continue"<<endl;
                    c=getch();
            }else{
            cout<<"Enter value:";
            cin>>element;
            push(&s,element);
            }
            break;
        case 2:
            if(isEmpty(&s)){
                cout<<" Stack is Empty. press any key to continue."<<endl;
                c=getch();
            }
            else{
                cout<<"Value Poped is "<<pop(&s)<<endl;
                cout<<" Press any key to continue...."<<endl;
                c=getch();
            }break;
        case 3:
            if(isEmpty(&s)){
                cout<<"Stack is Empty. press any key to continue."<<endl;
                c=getch();
            }else{cout<<"Value is top: "<<peek(&s)<<endl;
            cout<<"Press any key to continue.."<<endl;
            c=getch();
        }}
    }while(choice!=4);

    return 0;
}
