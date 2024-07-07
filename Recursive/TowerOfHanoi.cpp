#include<iostream>
using namespace std;
void TowerOfHanoi(char start, char End, char Exrra, int n)
{
    if(n==1)
        cout<<"Move disk start "<<start<<" End "<<End<<endl;
    else
    {
        TowerOfHanoi(start,Exrra,End,n-1);
        TowerOfHanoi(start,End,Exrra,1);
        TowerOfHanoi(Exrra,End,start,n-1);
    }
}
int main()
{
    int n;
    cout<<"\nEnter number of disks: ";
    cin>>n;
    if(n<1)
        cout<<"\n Illegal input..."<<endl;
    else
        TowerOfHanoi('A','C','B',n);
}
