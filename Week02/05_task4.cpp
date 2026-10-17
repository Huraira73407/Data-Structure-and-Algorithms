#include<iostream>
using namespace std;
int main()
{
    int arr[5]={20,50,60,70,80};
    int *p=arr;
    int n;
    cout<<"Enter the value you want to search:"<<endl;
    cin>>n;
    for(int i=0;i<5;i++)
    {
        if(n==*(p+i))
        {
            cout<<&arr;
        }

    }
    return 0;
}