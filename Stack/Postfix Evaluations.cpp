//Converting Infix notation to Postfix notation.
#include <iostream>
#include<conio.h>
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

int main()
{
    int choice;
    char *ch;
    ch=(char*)malloc(50);
cout<<"\n Enter your polish notation: ";
cin.getline(ch,50);
cout<<" Press any key to evaluation.."<<endl;cin.ignore();
cout<<" Answer :"<<evalu(ch)<<endl;
    return 0;
}