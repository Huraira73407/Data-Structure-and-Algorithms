//Take n numbers in an array and find SUM,AVERAGE,MAXIMUM,MINIMUM
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    int sum=0;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter array element"<<endl;
        cin>>arr[i];
    }
    int maximum=arr[0];
    int minimum=arr[0];
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
    
        if(arr[i]>maximum)
        {
            maximum=arr[i];
        }
        if(arr[i]<minimum)
        {
            minimum=arr[i];
        }
    }
    float average=float(sum)/n;
    cout<<"Sum ="<<sum<<endl;
    cout<<"Average="<<average<<endl;
    cout<<"Maximum="<<maximum<<endl;
    cout<<"Minimum="<<minimum<<endl;
    return 0;
}