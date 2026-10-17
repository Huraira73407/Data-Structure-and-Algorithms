#include<iostream>
using namespace std;

class Array
{
    private:
    int items[100];
    int size;

    public:
    Array()
    {
        size=0;
    }
    int getlength(){
        return size;
    }
    void add(int value){
        if(size<10){
            items[size]=value;
            size++;
            
        }
    }
    void display()
    {
        for(int i=0;i<size;i++)
        {
            cout<<items[i]<<" ";
        }
    }
    void deleteElement(int position)
    {
        if (position>=1 && position<=size)
        {
            for(int i =position;i<size-1;i++)
            {
                items[i]=items[i+1];
            }
            size--;
        }
    }
};
int main()
{
    Array a;
    int n;
    cout<<"Enter the number of elements in an array:"<<endl;
    cin>>n;
    int value;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the value:"<<endl;
        cin>>value;
        a.add(value);
    }

    a.display();
    cout<<endl;
    cout<<"Length of array is:"<<a.getlength()<<endl;
    a.deleteElement(2);
    cout<<"Values and size after deletion:"<<endl;
    a.display();
    cout<<endl;
    cout<<"Length of array is:"<<a.getlength()<<endl;
    return 0;
}
