#include<iostream>
using namespace std;

int main()
{
    int marks[5];
    
    int*p=marks;
    for(int i=0;i<5;i++)
    {
        cout<<"Enter marks: ";
        cin>>*(p+i);

    }
    
    for(int i=0;i<5;i++)
    {
        
        cout<<*(p+i)<<" ";
        
    }

}