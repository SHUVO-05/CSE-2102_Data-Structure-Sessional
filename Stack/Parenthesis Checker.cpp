//the arithmetic expression is properly parenthesised
#include<iostream>
#include<conio.h>
using namespace std;
struct stack
{
    char info;
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
char pop(stack **top)
{
    char temp;
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
    stack *top;
    createStack(&top);
    while(*exp)
    {
        if(*exp=='('||*exp=='{'||*exp=='[')push(&top,*exp);
        else if(*exp==')'||*exp=='}'||*exp==']')
        {
            if(isEmpty(top))
            {
                cout<<"\nError: No matching open symbol"<<endl;
                disposeStack(&top);
                return;
            }
            else{
                ch=pop(&top);
                if(ch!=getMatchingSymbol(*exp))
                {
                    cout<<"\nError: Incorrect nesting of symbols"<<endl;
                    return;
                }
            }
        }exp++;
    }
    if(!isEmpty(top))
    {
        cout<<"\n Missing closing symbol(s)"<<endl;
        disposeStack(&top);
        return;
    }
    else cout<<"\n Input Expression is OK"<<endl;
}
int main()
{
    char *charExpression;
     charExpression=(char*)malloc(20);
    cout<<"Enter any expression"<<endl<<endl;
     cin.getline(charExpression,21);
    pranethesisChecker(charExpression);
    getch();
  return 0;
}
