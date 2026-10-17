#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter size:"<<endl;
    cin>>n;

    int*arr=new int[n];
    for(int i=0;i<n; i++)
    {
        cout<<"Enter value:";
        cin>>arr[i];

    }
    cout<<"Array:";
    
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";

    }
    delete[] arr;
    return 0;

}

