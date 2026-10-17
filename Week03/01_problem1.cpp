#include<iostream>
using namespace std;

class Array
{
    private:
    int items[10];
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
};
int main()
{
    Array a;
    a.add(10);
    a.add(20);
    a.add(30);
    a.add(40);
    a.display();
    cout<<endl;
    cout<<"Length of array is:"<<a.getlength()<<endl;
    return 0;
}
