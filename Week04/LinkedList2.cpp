#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
int main()
{
    Node *head=new Node;
    Node *second=new Node;
    head->data=10;
    head->next=second;
    second->data=20;
    second->next=NULL;
   
    cout<<"THE FIRST NODE = "<<head->data<<endl;
     cout<<"THE SECOND NODE = "<<second->data;
    return 0;
}