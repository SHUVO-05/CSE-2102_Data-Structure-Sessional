// Linear Linked List Implementation.
#include<iostream>
using namespace std;
struct Node
{
    int info;
    struct Node *next;
};
//typedef struct Node;
//typedef struct Node Node;
Node *head=NULL;

Node *getNode(int item)
{
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->info=item;
    new_node->next=NULL;
    return new_node;
}
void insertFirst(int item)
{
    Node *new_node = getNode(item);
    new_node->next=head;
    head=new_node;

}
void traverse()
{
    if(head==NULL)
        cout<<"List is empty"<<endl;
    else{
    Node*point =head;
    while(point!=NULL)
    {
        cout<<point->info<<' ';
       point=point->next;
    }
cout<<endl;}
}
void reversetraverse(Node *spoint)
{

    Node *point=spoint;
    if(spoint==NULL)
        cout<<"List empty"<<endl;
    else{
    if(point->next!=NULL)
        reversetraverse(point->next);
    cout<<point->info<<' ';
    }
}
Node *seachsortedList(int item)
{
    while(head!=NULL)
    {
        if(head->info==item)
            return head;
            else if(head->info>item)
                return NULL;
            else head=head->next;
    }
    return NULL;
}
Node *searchUnsortedList(int item)
{
    Node *point=head;
    while((point!=NULL)&&(point->info!=item))
          point=point->next;
    return point;
}
//sort list follow increasing or decreasing order. which order i follow.
void insertEnd(int item)
{
    Node *new_node=getNode(item);
    Node *point;
    if(head==NULL)
        head=new_node;
    else{
        point=head;
    while(point->next!=NULL)
    {point=point->next;}
    point->next=new_node;
    }
}
void insertAfter(int item,int after)
{
    Node *node=getNode(item);
     Node *point=head;
     while((point!=NULL)&&(point->info!=after))
          point=point->next;
     if(point==NULL)
        {cout<<"Not fount element"<<endl; return;}
     node->next=point->next;
     point->next=node;
}
void insertBefore(int item,int after)
{
     Node *point=head;
    if(point->info==after)insertFirst(item);
    // point=searchUnsortedList(after);
    else{
    Node *node=getNode(item);
     while((point->next!=NULL)&&(point->next->info!=after))
          point=point->next;
     if(point->next==NULL)
        {cout<<"NNot fount element"<<endl; return;}
     node->next=point->next;
     point->next=node;
    }
}
void deleteFirst()
{
    if(head==NULL)
        {cout<<"Link List empty"<<endl;return;}
    else{
    Node *p;
    p=head;
        head=head->next;
    free(p);

    }
}

void deleteEnd() {
  if (head == NULL) {
    cout << "List is EMPTY." << endl;
    return;
  }
  if (head->next == NULL) {
       free(head);
    head = NULL;
  } else {
  Node* temp = head;
    while (temp->next->next != NULL) {
      temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
  }
}
void deleteAfter(int item)
{
    Node *point=head,*temp;

    while((point!=NULL)&&(point->info!=item))
        point=point->next;
    if(point==NULL)
    {
        cout<<"item not found"<<endl;
        return;
    }
   else if(point->next==NULL)
   {
       cout<<"Impossible to delete"<<endl;return;
   }
    temp=point->next;
    point->next=point->next->next;
    free(temp);

}
void deleteBefore(int item)
{
    Node *point=head,*temp;
    if(point->info==item){cout<<"DELETE is not possible"<<endl;return;}
    if(point->next->info==item)
    {
        temp=head;
        head=head->next;
        free(temp);return;
    }

    while(((point->next->next)!=NULL)&&(point->next->next->info!=item))
        point=point->next;
    if(point->next->next==NULL)
    {
        cout<<"item not found"<<endl;
        return;
    }
    temp=point->next;
    point->next=point->next->next;
    free(temp);

}
void deleteITEM(int item)
{
    Node *point=head,*temp;
    if(point->info==item)
    {
        temp=head;
        head=head->next;
        free(temp);
        return;
    }
    while(point->next!=NULL&&point->next->info!=item)
        point=point->next;
    if(point->next==NULL)
    {
        cout<<"item not found"<<endl;
        return;
    }
    temp=point->next;
    point->next=point->next->next;
    free(temp);
}
void deleteList()
{
    Node *temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}
int main()
{
    Node *loc;
    int choice,element,after;
    for(int i=10;i;i--)
    {
       insertFirst(i+10);
    }
    while(1)
    {
        cout<<"                 Option available     \n"<<endl;
        cout<<"      __________________________________________"<<endl<<endl;
        cout<<"     1. Insert at beginning."<<endl;
        cout<<"     2. Insert at end."<<endl;
        cout<<"     3. Insert after a given element."<<endl;
        cout<<"     4. Insert before a given element."<<endl;
        cout<<"     5. Traverse in order."<<endl;
        cout<<"     6. Traverse Reverse order."<<endl;
        cout<<"     7. Delete from beginning."<<endl;
        cout<<"     8. Delete from end."<<endl;
        cout<<"     9. Delete before a given element."<<endl;
        cout<<"    10. Delete a after a given element."<<endl;
        cout<<"    11. Delete a Link List."<<endl;
        cout<<"    12. Delete Item."<<endl;
        cout<<"    13. exit."<<endl;
        cout<<"    14. Searching if List is sorted."<<endl;
        cout<<"    15. Searching if List is Unsorted"<<endl<<endl;
        cout<<" Enter your choice (1-15): ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter your Element:";
            cin>>element;
            insertFirst(element);
            break;
        case 2:
            cout<<"Enter your Element: ";
            cin>>element;
            insertEnd(element);
            break;
        case 3:
            cout<<"Enter your Element: ";
            cin>>element;
            cout<<"\n Enter which value after your insert: ";
            cin>>after;
            insertAfter(element,after);
            break;
        case 4:
            cout<<"Enter your Element: ";
            cin>>element;
            cout<<"\n Enter which value before your insert: ";
            cin>>after;
            insertBefore(element,after);
            break;
        case 5:
            traverse();
            break;
        case 6:
            reversetraverse(head);
            break;
        case 7:
            deleteFirst();
            break;
        case 8:
            deleteEnd();
            break;
        case 9:
            cout<<"Enter your Element: ";
            cin>>element;
            deleteBefore(element);
            break;
        case 10:
            cout<<"Enter your Element: ";
            cin>>element;
            deleteAfter(element);
            break;
        case 11:
            deleteList();
            break;
        case 12:
            cout<<"Enter your Element: ";
            cin>>element;
            deleteITEM(element);
            break;
        case 13:
            exit(1);
        case 14:
            cout<<"\n Enter element you want to search: ";
            cin>>element;
            Node *loc;
            loc=seachsortedList(element);
            if(loc!=NULL)cout<<element<<" is found"<<endl;
            else cout<<"Not found"<<endl;
            break;
        case 15:
            cout<<"\n Enter element you want to search: ";
            cin>>element;
            Node *locn;
            locn=searchUnsortedList(element);
            if(loc!=NULL)cout<<element<<" is found"<<endl;
            else cout<<"Not found"<<endl;
            break;
        }
    }
}
