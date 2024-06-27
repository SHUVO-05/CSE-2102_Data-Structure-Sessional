//Stack use Infix Postfix operation implementation.
#include <iostream>
#include<conio.h>
using namespace std;
struct stack
{
    float ans;
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
float peekv(stack *top)
{
    return (top->ans);
}
bool isEmpty(stack *top)
{
    if(top==NULL)return true;
    else return false;
}
int getPriority(char op)
{
    int priority;
    if(op=='/'||op=='*'||op=='%')
        priority =1;
    else if(op=='+'||op=='('||op=='-')priority=0;
    return priority;
}
void pushf(stack **top,float value)
{
    float c;
    stack *point=(stack*)malloc(sizeof(stack));
    if(point==NULL){
        cout<<"Unable to allocate to memory\n press any key to continue.."<<endl;
        c=getch();
    }
    point->ans=value;
    point->next=*top;
    *top=point;

}
float popf(stack **top)
{
    float temp;
    stack *point;
    temp=(*top)->ans;
    point=(*top);
    (*top)=(*top)->next;
    free(point);
    return temp;
}
char getMatchingSymbol(char ch)
{
    char matchingChar;
    switch(ch)
    {
    case '(':matchingChar=')';break;
    case ')':matchingChar='(';break;
    case '{':matchingChar='}';break;
    case '}':matchingChar='{';break;
    case '[':matchingChar=']';break;
    case ']':matchingChar='[';
    }
    return matchingChar;
}
void pranethesisChecker(char *exp)
{
    char ch;
    stack *topk;
    creatStack(&topk);
    while(*exp)
    {
        if(*exp=='('||*exp=='{'||*exp=='[')push(&topk,*exp);
        else if(*exp==')'||*exp=='}'||*exp==']')
        {
            if(isEmpty(topk))
            {
                cout<<"\nError: No matching open symbol"<<endl;
                disposeStack(&topk);
                return;
            }
            else{
                ch=pop(&topk);
                if(ch!=getMatchingSymbol(*exp))
                {
                    cout<<"\nError: Incorrect nesting of symbols"<<endl;
                    return;
                }
            }
        }exp++;
    }
    if(!isEmpty(topk))
    {
        cout<<"\n Missing closing symbol(s)"<<endl;
        disposeStack(&topk);
        return;
    }
    else cout<<"\n Input Expression is OK"<<endl;
}

float evalu(char *exp)
{
    stack *topv;
    creatStack(&topv);
    float p1,p2,value;
    while(*exp)
    {


        if(*exp==' '||*exp=='\t'||*exp==','){*exp++;continue;}
        if(isdigit(*exp)){pushf(&topv,(float)(*exp-'0'));}
        else{

            p2=popf(&topv);
            p1=popf(&topv);
            switch(*exp)
            {
                case '+': value = p1 + p2;break;
                case '-': value = p1 - p2; break;
                case '*': value = p1 * p2; break;
                case '/': value = p1 / p2; break;
                case '%': value = (int) p1%(int)p2;break;
                default: cout<<" Illegal operation"<<endl;disposeStack(&topv);exit(1);
            }
            pushf(&topv,value);
        }
        exp++;
    }
    return value;
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
    int choice,dicision;
    char *ch,*p,sk;
    ch=(char*)malloc(50);
    p=(char*)malloc(50);
    while(1){
    cout<<" Option Available Here "<<endl;
    cout<<" ________________________ "<<endl;
    cout<<" 1. I want to input Infix notation."<<endl;
   // cout<<" 2. Input expression is properly parenthesised?."<<endl;
    cout<<" 2. I want to input Postfix notation."<<endl<<endl;
    cout<<"Enter your choice(1-2):";
    cin>>choice;
cin.ignore();
    switch(choice)
    {
        case 1: cout<<"\nEnter your Infix Expression: ";
         cin.getline(ch,50);
        cout<<" You want to check equation properly parenthesised?."<<endl;
        cout<<"\n 1. Yes.\n 2. No.\n Enter your choice:";
        cin>>dicision;
        cin.ignore();
        switch(dicision)
        {
            case 1: pranethesisChecker(ch);break;
            case 2: break;
        }
        InToPost(ch,p);
        cout<<"Answer : "<<evalu(p)<<endl;cin.ignore();break;
        case 2: cout<<"\nEnter your Postfix Expression: ";
        cin.getline(ch,50);
        cout<<"\n Answer: "<<evalu(ch)<<endl;
        cout<<" Press any key to continue..."<<endl;cin.ignore();break;
    }
    }
    return 0;
}