//Take number in an array and count Count Even ,ODD,Positive and Negative
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    int arr[n];
    int even=0, odd=0, positive=0,negative=0,zero=0;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the values in array"<<endl;
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2==0)
        {
            even++;
        }
        else{
            odd++;
        }

        if(arr[i]>0)
        {
            positive++;
        }
        else{
            negative++;
        }
        if(arr[i]==0){
            zero++;
        }
    }
    cout<<"Total even number in an array:"<<even<<endl;
    cout<<"Total odd number in an array:"<<odd<<endl;
    cout<<"Total positive number in an array:"<<positive<<endl;
    cout<<"Total negative number in an array:"<<negative<<endl;
    cout<<"Total zero number in an array:"<<zero<<endl;

}
