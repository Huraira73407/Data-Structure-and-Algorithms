// INsertion and deletion through pointers
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
    int value=35;
    for(int i=size;i>position;i--)
    {
        *(arr+i)=*(arr+(i-1));
    }
    arr[position]=value;
    size++;
    for(int i=0;i<size;i++)
    {
        cout<<*(arr+i)<<" ";
    }
    return 0;

}