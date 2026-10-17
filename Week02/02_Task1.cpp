#include<iostream>
using namespace std;
int main()
{
    int a;
    int arr1[25]={};
    int arr2[25]={};

    cout<<"Before swapping:"<<endl;
    for(int i=0;i<25;i++)
    {
        arr1[i] =i+1;
    
    }

    for(int i=0;i<25;i++)
    {
       arr2[i]=(i+1)*10;
    }
    cout<<"Array 1:";
     for(int i=0;i<25;i++)
    {
        cout<<arr1[i]<<" ";

    }
    cout<<endl;
    cout<<"Array 2:";
     for(int i=0;i<25;i++)
    {
        cout<<arr2[i]<<" ";

    }
    cout<<endl;
    cout<<"After swpaing:"<<endl;
    for(int i=0;i<25;i++)
    {
        a=arr1[i];
        arr1[i]=arr2[i];
        arr2[i]=a;

    }
    cout<<"Array 1:";
     for(int i=0;i<25;i++)
    {
        cout<<arr1[i]<<" ";

    }
    cout<<endl;
    cout<<"Array 2:";
     for(int i=0;i<25;i++)
    {
        cout<<arr2[i]<<" ";

    }
    return 0;
}