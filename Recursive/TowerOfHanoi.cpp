#include<iostream>
using namespace std;
void TowerOfHanoi(char start, char End, char Extra, int n)
{
static int coun;
    if(n==1){coun++;
   cout<<"\t\t"<<coun<<" Move disk "<<start<<" to End "<<End<<endl;}
    else
    {
        TowerOfHanoi(start,Extra,End,n-1);
        TowerOfHanoi(start,End,Extra,1);
        TowerOfHanoi(Extra,End,start,n-1);
    }
}
int main()
{
    int n;
    cout<<"\nEnter number of disks: ";
    cin>>n;temp=n;
    if(n<1)
        cout<<"\n Illegal input..."<<endl;
    else
        TowerOfHanoi('A','C','B',n);
}
