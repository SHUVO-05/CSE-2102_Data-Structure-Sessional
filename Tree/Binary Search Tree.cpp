// Implementation of Binary Search Tree.
#include<iostream>
#include<conio.h>
using namespace std;
struct Node{
struct Node *left;
int item;
struct Node *right;
};
char c;
void createTree(Node **tree)
{
    *tree=NULL;
}
Node *getNode(int element)
{
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->item=element;
    new_node->left=new_node->right=NULL;
    return new_node;
}
void insertElementIterative(Node **tree, int element)
{
    Node *nodePoint, *parentPoint;
    Node *point=getNode(element);
    if(*tree==NULL)
        *tree=point;
    else{
        parentPoint=NULL;
        nodePoint=*tree;
        while(nodePoint!=NULL)
            parentPoint=nodePoint;
        if(element<nodePoint->item)
            nodePoint=nodePoint->left;
        else nodePoint=nodePoint->right;
        if(element<parentPoint->item)
            parentPoint->left=point;
        else parentPoint->right=point;
    }
}
void insertElementRecursive(Node **tree, int element)
{
    if(*tree==NULL)
    {
        *tree=getNode(element);
    }
    else
    {
        if(element<(*tree)->item) insertElementRecursive(&((*tree)->left),element);
        else insertElementRecursive(&((*tree)->right),element);

    }
}
void preorderTraversalRecursive(Node *h)
{
    if(h!=NULL)
    {
        cout<<h->item<<' ';
        preorderTraversalRecursive(h->left);
        preorderTraversalRecursive(h->right);
    }
}
void inorderTraversalRecursive(Node *h)
{
    if(h!=NULL)
    {
        inorderTraversalRecursive(h->left);
        cout<<h->item<<' ';
        inorderTraversalRecursive(h->right);
    }
}
void postorderTraversalRecursive(Node *h)
{
    if(h!=NULL)
    {
        postorderTraversalRecursive(h->left);
        postorderTraversalRecursive(h->right);
        cout<<h->item<<' ';
    }
}
Node *searchElementRecursive(Node *tree, int value)
{
    if((tree->item==value)||(tree==NULL))
        return tree;
    else if(value < tree->item) return searchElementRecursive(tree->left,value);
    else return searchElementRecursive(tree->right, value);
}
Node *findSmallestElement(Node *tree)
{
    if((tree==(Node*)NULL)||(tree->left==(Node*)NULL))return tree;
    else return findSmallestElement(tree->left);
}
Node *findLargestElement(Node *tree)
{
    if((tree==(Node*)NULL)||(tree->right==(Node*)NULL))return tree;
    else return findSmallestElement(tree->right);
}
void deleteNode(Node **tree, int element)
{
    Node *temp;
    if(*tree==(Node*)NULL)
        {cout<<"\n Element "<<element<<" not found in Node"<<endl;
    cout<<"Press any key to continue..."<<endl;
    c=getch();
        }
        else if(element<(*tree)->item)
            deleteNode(&((*tree)->left),element);
        else if(element>(*tree)->item)
            deleteNode(&((*tree)->right),element);
        else if ((*tree)->left&&(*tree)->right)
        {
            temp=findLargestElement((*tree)->left);
            (*tree)->item=temp->item;
            deleteNode(&((*tree)->left),temp->item);
        }
        else{
            temp=*tree;
            if(((*tree)->left==NULL)&&((*tree)->right==NULL))
                *tree=(Node*)NULL;
            else if((*tree)->left!=NULL)*tree=(*tree)->left;
            else *tree=(*tree)->right;
            free(temp);
        }
}
int totalNodes(Node *tree)
{
    if(tree==NULL)
        return 0;
    return (totalNodes(tree->left)+totalNodes(tree->right)+1);
}
int internalNodes(Node *tree)
{
    if((tree==(Node*)NULL)||((tree->left==(Node*)NULL)&&(tree->right==(Node*)NULL)))return 0;
    return (internalNodes(tree->left)+internalNodes(tree->right)+1);
}
int externalNodes(Node *tree)
{
    if(tree==NULL)
        return 0;
    else if((tree->left==(Node*)NULL)&&(tree->right==(Node*)NULL))return 1;
    return (externalNodes(tree->left)+externalNodes(tree->right));
}
int determineHeight(Node *tree)
{
    int leftHeight, rightHeight;
    if(tree==NULL)
        return 0;
        else{
    leftHeight=determineHeight(tree->left);
    rightHeight=determineHeight(tree->right);
    if(leftHeight>rightHeight)
        return ++leftHeight;
    else
        return ++rightHeight;}
}
void findMirrorImage(Node *tree)
{
    Node *temp;
    if(tree!=NULL)
    {
        findMirrorImage(tree->left);
        findMirrorImage(tree->right);
        temp=tree->left;
        tree->left=tree->right;
        tree->right=temp;
    }
}
void removeTreeFromMemory(Node **tree)
{
    if(*tree!=NULL)
    {
        removeTreeFromMemory(&((*tree)->left));
        removeTreeFromMemory(&((*tree)->right));
        free(*tree);
    }
}
int main()
{
   int choice, element,height;
   Node *root,*loc;
   createTree(&root);
   while(1)
   {
       cout<<"\n   Options available  "<<endl;
       cout<<"_________________________"<<endl;
       cout<<" 1. Insert node."<<endl;
       cout<<" 2. Pre-order Traversal."<<endl;
       cout<<" 3. In-order Traversal."<<endl;
       cout<<" 4. Post-order Traversal."<<endl;
       cout<<" 5. Delete node."<<endl;
       cout<<" 6. Total nodes."<<endl;
       cout<<" 7. Total external nodes."<<endl;
       cout<<" 8. Total internal nodes."<<endl;
       cout<<" 9. Find Height."<<endl;
       cout<<"10. Smallest node."<<endl;
       cout<<"11. Largest node."<<endl;
       cout<<"12. Mirror Image."<<endl;
       cout<<"13. Exit."<<endl<<endl;

       cout<<"Enter your choice(1-13): ";
       cin>>choice;
       switch(choice)
       {
     case 1:
        cout<<"\n Element to be inserted into tree :";
        cin>>element;
        insertElementRecursive(&root,element);
        break;
     case 2:
        cout<<"\n Pre-order Traversal of Tree"<<endl;
        preorderTraversalRecursive(root);
        cout<<"\npress any key to continue...";c=getch();break;
     case 3:
        cout<<"\n In-order Traversal of Tree"<<endl;
        inorderTraversalRecursive(root);
        cout<<"\npress any key to continue...";c=getch();break;
     case 4:
        cout<<"\n Post-order Traversal of Tree"<<endl;
        postorderTraversalRecursive(root);
        cout<<"\npress any key to continue...";c=getch();break;
     case 5:
        cout<<"\n Element to delete from tree : ";
        cin>>element;
        deleteNode(&root, element);
        break;
     case 6:
        cout<<"\n Number of Node in Tree = "<<totalNodes(root)<<endl;
        cout<<"press any key to continue...";c=getch();break;
     case 7:
        cout<<"\n Number of leaf nodes in Tree = "<<externalNodes(root)<<endl;
        cout<<"press any key to continue...";c=getch();break;
     case 8:
        cout<<"\n Number of non-leaf nodes in Tree = "<<internalNodes(root)<<endl;
        cout<<"press any key to continue...";c=getch();break;
     case 9:
        cout<<"\n Height of Tree = "<<determineHeight(root)<<endl;
        cout<<"press any key to continue...";c=getch();break;
     case 10:
        loc=findSmallestElement(root);
        cout<<"\n Smallest node in Tree = "<<loc->item<<endl;
        cout<<"press any key to continue...";c=getch();break;
     case 11:
        loc=findLargestElement(root);
        cout<<"\n Largest node in Tree = "<<loc->item<<endl;
        cout<<"press any key to continue...";c=getch();break;
     case 12:
        findMirrorImage(root);
        break;
     case 13:
        removeTreeFromMemory(&root);
        exit(1);
       }

   }
}
