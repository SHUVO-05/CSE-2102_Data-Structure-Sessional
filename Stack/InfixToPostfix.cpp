//Converting Infix notation to Postfix notation.
#include <iostream>
#include<conio.h>
using namespace std;
struct stack
{
    char info;
    struct stack *next;
};
void creatStack(stack **top)
{
    *top=NULL;
}
stack *getStack(char cm)
{
    stack *new_st=(stack*)malloc(sizeof(stack));
    new_st->info=cm;
    new_st->next=NULL;
    return new_st;
}
void push(stack **top, char cn)
{
    stack *point=getStack(cn);
    point->next=*top;
    *top=point;
}
char pop(stack **top)
{
    char temp;
    stack *point;
    temp=(*top)->info;
    point=*top;
    *top=(*top)->next;
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
char peek(stack *top)
{
    return (top->info);
}
bool isEmpty(stack *top)
{
    if(top==NULL)return true;
    else return false;
}
void insertEnd(stack **top,char item)
{
    stack *new_node=getStack(item);
    stack *point;
    if(*top==NULL)
        *top=new_node;
    else{
        point=*top;
    while(point->next!=NULL)
    {point=point->next;}
    point->next=new_node;
    }
}
int getPriority(char op)
{
    int priority;
    if(op=='/'||op=='*'||op=='%')
        priority =1;
    else if(op=='+'||op=='('||op=='-')priority=0;
    return priority;
}
void InToPost(char *s, char *t)
{
    stack *top;
    creatStack(&top);

    while(*s)
    {
             if((*s==' ')||(*s=='\t'))
             {
            s++;
            continue;
             }
             else if(*s=='('){push(&top,*s);s++;}
             else if(*s==')'){
                while((!isEmpty(top))&&(peek(top)!='('))
                {
                    *t=pop(&top);
                    t++; *t=' '; t++;
                }
                if(isEmpty(top)){cout<<"\n Error: Incorrect expression"<<endl; disposeStack(&top);exit(1);}
                pop(&top);
                s++;
             }
             else if(isdigit(*s)||isalpha(*s))
             {
                 *t=*s;
                 t++; *t=' ';t++;s++;
             }
             else if(*s=='+'||*s=='-'||*s=='*'||*s=='/'||*s=='%')
             {
                 while((!isEmpty(top))&&(peek(top)!='(')&&(getPriority(peek(top))>=getPriority(*s)))
                 {
                    *t=pop(&top);
                    t++; *t=' ';t++;
                 }
                 push(&top,*s);s++;
             }else
             {
                 cout<<"\n Error: Incorrect element of expression"<<endl;disposeStack(&top);exit(1);
             }
    }
    while((!isEmpty(top))&&(peek(top)!='('))
    {
        *t=pop(&top);t++;*t=' ';t++;
    }
   // if(peek(top)=='('){cout<<"\n Error"<<endl;}
    *t='\0';
}

void InToPos(char *s, char *t)
{
    stack *top;
    creatStack(&top);

    while(*s)
   {
       if(*s==' '||*s=='\t')
       {
           s++;continue;
       }
          else if(*s=='('){push(&top,*s);}
 else if(*s==')'){
                while((!isEmpty(top))&&(peek(top)!='('))
                {
                    *t = ' '; t++;
                    *t=pop(&top);
                    t++;
                }
                if(isEmpty(top)){cout<<"\n Error: Incorrect expression"<<endl; disposeStack(&top);exit(1);}
                pop(&top);
             }
          else if(isdigit(*s)||isalpha(*s))
            {
                *t=*s; t++;
            // *t=' '; t++;
             }
        else if(*s=='+'||*s=='-'||*s=='*'||*s=='/'||*s=='%')
        {
            *t=' ';t++;
           while((!isEmpty(top))&&(peek(top)!='(')&&(getPriority(peek(top))>=(getPriority(*s))))
                 {
                    *t=pop(&top);
                    t++; *t=' ';t++;
                 }
            push(&top,*s);
        }else
             {
                 cout<<"\n Error: Incorrect element of expression"<<endl;disposeStack(&top);exit(1);
             }
        s++;
   }if(*s=='\0'){*t=' ';t++;}
   while((!isEmpty(top))&&(peek(top)!='('))
    {
        *t=pop(&top);t++;*t=' ';t++;
    }
   // if(peek(top)=='('){cout<<"\n Error"<<endl;}
   *t='\0';

}
int main()
{
    char *ch,*p;
    ch=(char*)malloc(50);
    p=(char*)malloc(50);

   cin.getline(ch,50);
   InToPos(ch,p);
   cout<<"\n"<<p<<endl;
    return 0;
}
