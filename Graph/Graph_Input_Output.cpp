//Implementation Graph Input & Output.
/*
For Undirected and Directed Graph.
this Undirect graph like as:

1-> 2-> 5.
2-> 1-> 5-> 3.
3-> 2.
4-> 5.
6-> 2-> 1-> 4.


*/
#include<iostream>

using namespace std;
#define Max 20
struct Node {
    int vertex;
    struct Node *next;
};

void createGraph (Node *adj[], int num)
{
    int i;
    for(i=1; i<=num; i++)
        adj[i]=NULL;
}

void inputGraph(Node *adj[], int num)
{
    Node *point, *last;
    int i,j,m,val,wt;
    for(i=1; i<=num; i++)
    {   last= NULL;
        cout<<"\n Number of nodes in the adjacency list of node "<<i<<"  ";
        cin>>m;
        for(j=1; j<=m; j++)
        {   cout<<" Enter node "<<j<<" :";
            cin>>val;
            point=(Node*)malloc(sizeof(Node));
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
void printGraph(Node *adj[], int num)
{
    Node *point;
    int i;
    for(i=1; i<=num; i++)
    {
        point=adj[i];
        cout<<i;
        while(point!=NULL)
        {
            cout<<"-> "<<point->vertex;
            point=point->next;
        }
        cout<<endl;
    }
}
void deleteGraph(Node *adj[], int num)
{
    int i;
    Node *temp, *point;
    for(i=1; i<=num; i++)
    {   point=adj[i];
        while(point!=NULL)
        {   temp=point;
            point=point->next;
            free(temp);
        }
        adj[i]=NULL;
    }
}

int main()
{

    Node *adj[Max];
    int n;
    cout<<"\n Enter number of nodes in the graph : ";
    cin>>n;
    createGraph(adj,n);
    inputGraph(adj,n);
    cout<<"\n INPUT GRAPH \n\n"<<endl;
    printGraph(adj,n);

    deleteGraph(adj,n);

}