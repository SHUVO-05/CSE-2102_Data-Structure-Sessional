//Reverse Order Traverse.
#include<iostream>
using namespace std;
void reverse_order_traverse(int ar[], int m)
{
    int i;
    cout<<"\n Reverse_Order_Traverse: ";
    for(i=m-1; i>=0; i--)
        cout<<ar[i]<<' ';
    cout<<endl;
}
int main()
{
    int Array[7]={56,0,5,0,3,9,1};
    reverse_order_traverse(Array,7);
}

