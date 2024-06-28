//N digit postfix evaluation with some problem notation.
#include <iostream>
#include<conio.h>
#include<cstring>
using namespace std;
struct stack
{
    float ans;
    struct stack *next;
};
void creatStack(stack **top)
{
    *top=NULL;
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

void pushf(stack **top,float value)
{

    char c;
    stack *point=new stack;
    if(point==NULL){
        cout<<"Unable to allocate to memory\n press any key to continue.."<<endl;
        c=getch();
    }
    point->ans=value;
    point->next=*top;
    (*top)=point;

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


float evaluatePostfixExpression(char *exp, char *getvalue)
{
    float p1,p2,value,fpoint;
    stack *topv;
    creatStack(&topv);
    char* word = strtok(getvalue," ");
while(word!=NULL)
{
    float fpoint= atof(word);
//cout<<fpoint<<"**"<<endl;
   pushf(&topv,fpoint);
   word=strtok(NULL," ");
}
popf(&topv);
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
void divide(char *exp,char *quote)
{
    while(*exp)
    {
     if(*exp=='+'||*exp=='-'||*exp=='*'||*exp=='/'||*exp=='%')
       {
        exp++; continue;
       }
       *quote=*exp;
       exp++;quote++;
    }


}
int main()
{
    int choice;
    char *ch,*getvalue;
    ch=(char*)malloc(50);
    getvalue=(char*) malloc(50);

cout<<"\n Enter your polish notation: ";
cin.getline(ch,50);
divide(ch,getvalue);
cout<<" Press any key to evaluation.."<<endl;cin.ignore();
cout<<" Answer :"<<evaluatePostfixExpression(ch,getvalue)<<endl;
    return 0;
}