// Deletion through pointers
#include<iostream>
using namespace std;
int main()
{
    int *arr=new int[5];
    *(arr+0)=10;
    *(arr+1)=20;
    *(arr+2)=30;
    *(arr+3)=40;
    *(arr+4)=50;

    int size=5;
    int position=3;
    for(int i=position;i<size-1;i++)
    {
        *(arr+i)=*(arr+(i+1));
    }
    size--;
    for(int i=0;i<size;i++)
    {
        cout<<*(arr+i)<<" ";
    }
    return 0;

}