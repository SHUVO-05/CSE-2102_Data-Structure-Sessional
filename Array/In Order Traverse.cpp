// In Order Traverse.
#include<iostream>
using namespace std;
void in_order_traverse(int ar[], int m)
{
    int i;
    cout<<"\n Array In_Order_Traverse: ";
    for(i=0; i<m; i++)
        cout<<ar[i]<<' ';
    cout<<endl;
}
int main()
{
    int Array[7]={56,0,5,0,3,9,1};
    in_order_traverse(Array,7);
}
