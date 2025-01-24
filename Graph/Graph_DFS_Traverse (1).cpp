// Graph Traverse Using DFS Technique.
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

struct Stack
{
    int info;
    struct Stack *next;
};

void createGraph( Node1 *adj[], int num)
{   int i;
    for(i=1; i<=num; i++)
        adj[i]=NULL;
}
void createStack(Stack **top)
{
    *top=NULL;
}

void push(Stack **top, int element)
{
    Stack *point;
    point=(Stack*)malloc(sizeof(Stack));
    point->info=element;
    point->next=*top;
    *top=point;
}

int pop(Stack **top)
{
    int temp;
    Stack *point;
    temp=(*top)->info;
    point=*top;
    *top=(*top)->next;
    free(point);
    return temp;
}
int peek(Stack *top)
{
    return top->info;
}
int isEmpty(Stack *top)
{
    if(top==NULL)
        return 1;
    else return 0;
}
void disposeStack(Stack **top)
{
    Stack *point;
    while(*top!=NULL)
    {
        point=*top;
        *top=(*top)->next;
        free(point);
    }
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

void DFS(Node1 *adj[], int n, int s)
{
    Node1 *point;
    Stack *st;
    int i, u, color[MAX];
    for(i=1; i<=n; i++)
        color[i]=WHITE;
    color[s]=GRAY;
    createStack(&st);
    push(&st,s);
    while(!isEmpty(st))
    {   u=peek(st);
        point=adj[u];
        while(point!=NULL)
        {

            if(color[point->vertex]==WHITE) {
                color[point->vertex]=GRAY;
                push(&st,point->vertex);
                u=point->vertex;
                point=adj[u];
            }
            else
                point=point->next;
        }
        u=pop(&st);
        cout<<u<<' ';
        color[u]=BLACK;
    }
}


int main()
{
    Node1 *adj[MAX];
    int n, i, s;
    cout<<"\n Enter number of nodes in graph: ";
    cin>>n;
    createGraph(adj,n);
    inputGraph(adj,n);
    cout<<" Enter source vertex: ";
    cin>>s;
    cout<<"\n\n DFS from vertex "<<s<<" is \n\n"<<endl;
    DFS(adj,n,s);
    deleteGraph(adj,n);
    return 0;
}