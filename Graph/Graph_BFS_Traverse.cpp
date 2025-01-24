// Graph Traverse Using BFS  Technique.
/* Adjacency- list of graph

1-> 4-> 2.
2-> 1-> 5-> 4-> 3.
3-> 2-> 5-> 6.
4-> 1-> 2-> 5.
5-> 4-> 2-> 6-> 3.
6-> 5-> 3.

*/


#include<iostream>
#define MAX 20
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;

struct Node1
{
    int vertex;
    struct Node1 *next;
};

struct Node
{
    int info;
    struct Node *next;
};

struct queue
{
    struct Node *front;
    struct Node *rear;
};

void createGraph( Node1 *adj[], int num)
{   int i;
    for(i=1; i<=num; i++)
        adj[i]=NULL;
}
void createQueue(queue *q)
{
    q->front=q->rear=NULL;
}

void enqueue( queue *q, int element)
{
    Node *point;
    point=(Node*)malloc(sizeof(Node));
    point->info=element;
    point->next=NULL;
    if(q->front==NULL)
        q->front=q->rear=point;
    else {
        (q->rear)->next=point;
        q->rear=point;
    }
}

int dequeue(queue *q)
{
    int temp;
    Node *point;
    temp=q->front->info;
    point=q->front;
    if(q->front==q->rear)q->front=q->rear=NULL;
    else q->front=q->front->next;
    free(point);
    return temp;
}
int peek(queue *q)
{
    return q->front->info;
}
int isEmpty(queue *q)
{
    if(q->front==NULL)
        return 1;
    else return 0;
}

void inputGraph( Node1 *adj[], int num)
{
    Node1 *point, *last;
    int i, j, m, val;
    for(i=1; i<=num; i++)
    {
        last=NULL;
        cout<<" \n  Number of nodes in the adjacency list of node "<<i<<" :";
        cin>>m;
        for(j=1; j<=m; j++)
        {
            cout<<" Enter node "<<j<<": ";
            cin>>val;
            point=(Node1*)malloc(sizeof(Node1));
            point->vertex=val;
            point->next=NULL;

            if(adj[i]==NULL)
                adj[i]=last=point;
            else {
                last->next=point;
                last=point;

            }
        }
    }
}
void deleteGraph(Node1 *adj[],int num)
{
    int i;
    Node1 *temp, *point;
    for(i=1; i<=num; i++)
    {
        point=adj[i];
        while(point!=NULL)
        {
            temp=point;
            point=point->next;
            free(temp);
        }
        adj[i]=NULL;
    }
}

void BFS(Node1 *adj[], int n, int s)
{
    Node1 *point;
    queue q;
    int i, u,v,color[MAX];
    createQueue(&q);
    for(i=1; i<=n; i++)
        color[i]=WHITE;
    color[s]=GRAY;
    enqueue(&q,s);
    while(!isEmpty(&q))
    {   u=peek(&q);
        point=adj[u];
        while(point!=NULL)
        {
            v=point->vertex;
            if(color[v]==WHITE) {
                color[v]=GRAY;
                enqueue(&q,v);
            }
            point=point->next;
        }
        u=dequeue(&q);
        cout<<u<<' ';
        color[u]=BLACK;
    }
}




int main()
{
    Node1 *adj[MAX];
    int n,s;
    cout<<"\n Enter number of nodes in graph: ";
    cin>>n;
    createGraph(adj,n);
    inputGraph(adj,n);
    cout<<" Enter source vertex: ";
    cin>>s;
    cout<<"\n\n BFS from vertex "<<s<<" is \n\n"<<endl;
    BFS(adj,n,s);
    deleteGraph(adj,n);
    return 0;
}