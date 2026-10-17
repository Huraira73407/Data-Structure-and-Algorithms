#include<iostream>
using namespace std;
int main()
{
    int a[10]={10,20,30,40,50};
    int size=5;
    int position=3;
    for(int i=position;i<size-1;i++)
    {
        a[i]=a[i+1];
    }
    size--;
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}