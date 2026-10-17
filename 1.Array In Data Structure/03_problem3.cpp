// Array insertion
#include<iostream>
using namespace std;
int main()
{
    int a[10]={10,20,30,40,50};
    int size=5;
    int value=35;
    int position=3;
    for(int i=size;i>position;i--)
    {
        a[i]=a[i-1];
    }
    a[position]=value;
    size++;
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}