// Array Base Queue Implementation.
#include <iostream>
#include<conio.h>
using namespace std;
#define MAX 5
struct queue
{
    int front, rear;
    int elements[10];
};
void createQueue(queue *pq)
{
    pq->front=pq->rear=-1;
}
bool isEmpty(queue *pq)
{
    return ((pq->front==-1)?true:false);
}
bool isFull(queue *pq)
{
    return((pq->front==0)&&(pq->rear==MAX-1)?true:false);
}
void Enqueue(queue *pq, int value)
{
    int i;
    if(isEmpty(pq))pq->front=pq->rear=0;
    else if (pq->rear==(MAX-1))
    {
        for(i=pq->front;i<=pq->rear;i++)
        {
            pq->elements[i-pq->front]=pq->elements[i];
        }
        pq->rear=pq->rear-pq->front+1;
        pq->front=0;
    }
    else
    {
         pq->rear++;
    }
    pq->elements[pq->rear]=value;
}
int Dequeue(queue *pq)
{
    int temp;
    temp=pq->elements[pq->front];
    if(pq->front==pq->rear)pq->front=pq->rear=-1;
    else pq->front++;
    return temp;

}
int peek(queue *pq)
{
    return (pq->elements[pq->front]);
}
int main()
{
   int choice,element;
   queue q;
   char c;
   createQueue(&q);
   do
   {
       cout<<" \n Options available"<<endl;
       cout<<" ------------------------"<<endl;
       cout<<" 1. Enqueue"<<endl;
       cout<<" 2. Dequeue"<<endl;
       cout<<" 3. Peek."<<endl;
       cout<<" 4. Exit."<<endl<<endl;
       cout<<"Enter ur choice (1-4):";
       cin>>choice;

    switch(choice)
        {
        case 1:
            if(isFull(&q))
            {
                cout<<" Queue is full, press any key to continue"<<endl;
                     c=getch();
            }else{
            cout<<"Enter value:";
            cin>>element;
            Enqueue(&q,element);
            }
            break;
        case 2:
            if(isEmpty(&q)){
                cout<<" Queue is Empty. press any key to continue."<<endl;
                 c=getch();
            }
            else{
                cout<<"Value Deueue is "<<Dequeue(&q)<<endl;
                cout<<" Press any key to continue...."<<endl;
                 c=getch();
            }break;
        case 3:
            if(isEmpty(&q)){
                cout<<"Queue is Empty. press any key to continue."<<endl;
                c=getch();
            }else{cout<<"Value is top: "<<peek(&q)<<endl;
            cout<<"Press any key to continue.."<<endl;
            c=getch();
        }}
    }while(choice!=4);
    return 0;
}
