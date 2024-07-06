// Various operations of Linear Linked list use Queue.
#include<iostream>
#include<conio.h>
using namespace std;
struct Queue
{
    int info;
    struct Queue *next,*front,*rear;
};
void createQueue(Queue *pq)
{
    pq->front=pq->rear=NULL;
}
bool isEmpty(Queue *pq)
{
    return ((pq->front==NULL)?true:false);
}
void Enqueue(Queue *pq, int item)
{
    char c;
    Queue *point;
    point=(Queue*)malloc(sizeof(Queue));
     if(point==NULL){
        cout<<"Unable to allocate to memory\n press any key to continue.."<<endl;
        c=getch();
    }
    point->info=item;
    point->next=NULL;
    if((point->rear)==0)
{
       cout<<pq->rear<<endl;
       (pq->front)=point;
       (pq->rear)=point;
cout<<"Enqueue if condition"<<endl;
}
    else{
        ((pq->rear)->next)=point;
        (pq->rear)=point;
        cout<<"Enqueue else condition"<<endl;
    }
}
int Dequeue(Queue *pq)
{
    int temp;
    Queue *point;
    temp=(pq->front)->info;
    point=pq->front;
    if((pq->front)==(pq->rear)){(pq->front)=(pq->rear)=NULL;}
    else {(pq->front)=(pq->front)->next;}
    free(point);
    return temp;
}
int Peek(Queue *pq)
{
    return ((pq->front)->info);
}
void disposeQueue(Queue *pq)
{
    Queue *point;
    while(pq->front!=NULL)
    {
        point=pq->front;
        pq->front=(pq->front)->next;
        free(point);
    }
    pq->rear=(Queue*)NULL;
}
int main()
{
   int choice,element;
   Queue q;
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
//            if(isFull(&q))
//            {
//                cout<<" Queue is full, press any key to continue"<<endl;
//                     c=getch();
//            }
            cout<<"Enter value:";
            cin>>element;
            Enqueue(&q,element);
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
            }else{cout<<"Value is top: "<<Peek(&q)<<endl;
            cout<<"Press any key to continue.."<<endl;
            c=getch();
        }}
    }while(choice!=4);
    return 0;
}
