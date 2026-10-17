#include<iostream>
using namespace std;
int main()
{
    int arr[7]={10,70,60,40,80,90,30};
    int *p=arr;
    int maximum=arr[0];
    int minimum=arr[0];
    for(int i=0;i<7;i++)
    {
    if(*(p+i)>maximum){
        maximum=*(p+i);
    }
    if(*(p+i)<minimum){
        maximum=*(p+i);
    }
    }
    cout<<"Maximum is:"<<maximum<<endl;
    cout<<"Minimum is:"<<minimum<<endl;
    return 0;
}