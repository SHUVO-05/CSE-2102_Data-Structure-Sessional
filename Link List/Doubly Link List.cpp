//Implementation of doubly linked list.
#include<conio.h>
#include<iostream>
using namespace std;
struct Node
{
    struct Node *prev;
    int info;
    struct Node *next;
}*head=NULL,*tail=NULL;

//Node *head=NULL;
//Node *tail=NULL;
Node *getNode(int item)
{
    Node *node=(Node*)malloc(sizeof(Node));
    node->info=item;
    node->next=NULL;
    node->prev=NULL;
    return node;
}
void In_order_Traverse(Node *point)
{
     if(head==NULL)
        cout<<"List is empty"<<endl;
    else{
while(point!=NULL){
    cout<<point->info<<' ';
point=point->next;
}}
cout<<endl;
}
void Reverse_order_Traverse(Node *point)
{
     if(head==NULL)
        cout<<"List is empty"<<endl;
    else{
while(point!=NULL){
    cout<<point->info<<' ';
point=point->prev;
}}
cout<<endl;
}

Node *seachsortedListi(int item)
{
    Node *point=head;
    while(point!=NULL)
    {
        if(point->info==item)
            return point;
        else if(item<point->info)
                return NULL;
        else point=point->next;
    }
    return NULL;
}
Node *seachsortedListd(int item)
{
    Node *point=tail;
    while(point!=NULL)
    {
        if(point->info==item)
            return point;
        else if(item>point->info)
                return NULL;
        else point=point->prev;
    }
    return NULL;
}

Node *searchUnsortedList(int item)
{
    Node *point=tail;
    while((point!=NULL)&&(point->info!=item))
          point=point->prev;
    return point;
}
void insertFirst(int item)
{
    Node *node=getNode(item);
    if(head==NULL)
    {
        node->next=node->prev=NULL;
        head=tail=node;
    }
    else{
        node->prev=NULL;
        node->next=head;
        head->prev=node;
        head=node;
    }
}
void insertEnd(int item)
{
    Node *node=getNode(item);
    if(head==NULL)
        {
            node->next=node->prev=NULL;
            head=node;}
    else{
        node->next=NULL;
        node->prev=tail;
        tail->next=node;
        tail=node;
    }
}
void insertAfter(int item,int after)
{
     Node *location=searchUnsortedList(after);
     if(location==NULL){cout<<" Value not found"<<endl;return;}
    Node *node=getNode(item);
     if(location->next==NULL)
     {
         node->next=NULL;
         node->prev=tail;
         location->next=node;
         tail=node;
     }
     else
     {
         node->prev=location;
         node->next=location->next;
         location->next->prev=node;
         location->next=node;
     }
}
void insertBefore(int item,int after)
{
     Node *location=searchUnsortedList(after);
     if(location==NULL){cout<<" Value not found"<<endl;return;}
    Node *node=getNode(item);
     if(location->prev==NULL)
     {
         node->next=head;
         node->prev=NULL;
         location->prev=node;
         head=node;
     }
     else
     {
         node->prev=location->prev;
         node->next=location;
         location->prev->next=node;
         location->prev=node;
     }
}
void deleteFirst()
{
    if(head==NULL)
        {cout<<"Link List empty"<<endl;return;}
        else if (head==tail)head=tail=NULL;
    else{
    Node *p;
    p=head;
    head->next->prev=NULL;
    head=head->next;
    free(p);
    }
}

void deleteEnd() {
  if (head == NULL) {
    cout << "List is EMPTY." << endl;return;}
    else if (head==tail)head=tail=NULL;
else {
   Node *p;
    p=tail;
    tail->prev->next=NULL;
    tail=tail->prev;
    free(p);
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
       cout<<"No value present "<<point->info<<" after."<<endl;return;
   }
   else if(point->next->next==NULL)
   {
       temp=point->next;
       point->next=NULL;
       tail=point;
       free(temp);
   }
   else{
    temp=point->next;
    point->next=temp->next;
    temp->next->prev=point;
    free(temp);
   }
}
void deleteBefore(int item)
{
    Node *point=tail,*temp;

    while((point!=NULL)&&(point->info!=item))
        point=point->prev;
    if(point==NULL)
    {
        cout<<"item not found"<<endl;
        return;
    }
   else if(point->prev==NULL)
   {
       cout<<"No value present "<<point->info<<" Before."<<endl;return;
   }
   else if(point->prev->prev==NULL)
   {
       temp=point->prev;
       point->prev=NULL;
       head=point;
       free(temp);
   }
   else{
    temp=point->prev;
    point->prev=temp->prev;
    temp->prev->next=point;
    free(temp);
   }
}

void deleteITEM(int item)
{
    if(head==NULL)cout<<"List is empty"<<endl;
    else{Node *point=head,*temp,*loca;
        loca=searchUnsortedList(item);
        if(loca==NULL)cout<<"Not found"<<endl;
    else if(head==loca)deleteFirst();
    else if(tail==loca)deleteEnd();
    else{
        temp=loca;
        loca->prev->next=loca->next;
        loca->next->prev=loca->prev;
        free(temp);
    }
    }
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
    char ch;
    int choice,element,after;
    for(int i=10;i;i--)
    {
       insertFirst(i);
    }
//    cout<<head->info<<endl;
//    cout<<tail->info<<endl;
    while(1)
    {
        cout<<"\n                   Option available     \n"<<endl;
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
        cout<<"    14. Searching if List is sorted increasing order."<<endl;
        cout<<"    15. Searching if List is Unsorted"<<endl;
        cout<<"    16. Searching if List is sorted decreasing order."<<endl<<endl;
        cout<<" Enter your choice (1-16): ";
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
            cout<<"\n Enter which value after your insert: ";
            cin>>after;
            cout<<"Enter your Element: ";
            cin>>element;
            insertAfter(element,after);
            break;
        case 4:
            cout<<"\n Enter which value before your insert: ";
            cin>>after;
            cout<<"Enter your Element: ";
            cin>>element;
            insertBefore(element,after);
            break;
        case 5:
            cout<<endl;
            In_order_Traverse(head);
            cout<<"\n Press any key to continue.....";
            ch=getch();
            break;
        case 6:
            cout<<endl;
            Reverse_order_Traverse(tail);
            cout<<"\n Press any key to continue.....";
            ch=getch();
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
            loc=seachsortedListi(element);
            if(loc!=NULL)cout<<element<<" is found"<<endl;
            else cout<<"Not found"<<endl;
            break;
        case 15:
            cout<<"\n Enter element you want to search: ";
            cin>>element;
            loc=searchUnsortedList(element);
            if(loc!=NULL)cout<<loc->info<<" is found"<<endl;
            else cout<<"Not found"<<endl;
            break;
        case 16:
            cout<<"\n Enter element you want to search: ";
            cin>>element;
            loc=seachsortedListd(element);
            if(loc!=NULL)cout<<element<<" is found"<<endl;
            else cout<<"Not found"<<endl;
            break;
        }
    }
}
