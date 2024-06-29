//Ndigit Infix To Postfix evaluation implementation.
#include <iostream>
#include<cstring>
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
float evaluatePostfixExpression(char *exp, char *getvalue)
{
   float p1,p2,value,fpoint;
    stack *topv;
    creatStack(&topv);
    char* word = strtok(getvalue," ");
while(word!=NULL)
{
    float fpoint= atof(word);
    if(fpoint==0)break;
//cout<<fpoint<<"**"<<endl;
   pushf(&topv,fpoint);
   word=strtok(NULL," ");
}
//popf(&topv);
//pushf(&topv, 10);
//pushf(&topv, 20.5);
//cout<<popf(&topv)<<"="<<popf(&topv)<<endl;
    while(*exp)
    {

        if(*exp==' '||*exp=='\t'||*exp==','||*exp=='.'){*exp++;continue;}
        if(isdigit(*exp)){exp++;continue;}
       //if(isdigit(*exp)&&isdigit(*(exp+1))){pushf(&topv,((float)((*exp-'0')*10))+(float)(*(exp+1))-'0');exp++;}
        //if(isdigit(*exp)){pushf(&topv,(float)(*exp-'0'));}

            p2=popf(&topv);
            p1=popf(&topv);
            switch(*exp)
            {
                case '+': value = p1 + p2;break;
                case '-': value = p1 - p2; break;
                case '*': value = p1 * p2; break;
                case '/': value = p1 / p2; break;
                case '%': value = (int) p1%(int)p2;break;
                default: cout<<" Illegal operation == "<<*exp<<endl;disposeStack(&topv);exit(1);
            }
            pushf(&topv,value);
        exp++;
    }
    return value;
}
void Digit_separate(char *exp,char *quote)
{
     while(*exp)
    {
     if(*exp=='+'||*exp=='-'||*exp=='*'||*exp=='/'||*exp=='%')
       {
        exp++; continue;
       }
       if(*exp==','||*exp=='\t'){*quote=' ';quote++;*exp++;continue;}
       *quote=*exp;
       exp++;quote++;
    }
}
int main()
{
    int choice,dicision;
    char *InfixExpression,*PostfixExpression,*Digits,sk;
    InfixExpression=(char*)malloc(50);
    PostfixExpression=(char*)malloc(50);
    Digits=(char*)malloc(50);
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
         cin.getline(InfixExpression,50);
        cout<<" You want to check equation properly parenthesised?."<<endl;
        cout<<"\n 1. Yes.\n 2. No.\n Enter your choice:";
        cin>>dicision;
        cin.ignore();
        switch(dicision)
        {
            case 1: pranethesisChecker(InfixExpression);break;
            case 2: break;
        }
        InToPost(InfixExpression,PostfixExpression);
        cout<<"\n Your Polis notation Like that:"<<PostfixExpression<<endl;
        Digit_separate(PostfixExpression,Digits);
        cout<<"Answer : "<<evaluatePostfixExpression(PostfixExpression,Digits)<<endl;cin.ignore();break;
        case 2: cout<<"\nEnter your Postfix Expression: ";
        cin.getline(PostfixExpression,50);
        Digit_separate(PostfixExpression,Digits);
        cout<<"\n Answer: "<<evaluatePostfixExpression(PostfixExpression,Digits)<<endl;
        cout<<" Press any key to continue..."<<endl;cin.ignore();break;
    }
    }
    return 0;
}