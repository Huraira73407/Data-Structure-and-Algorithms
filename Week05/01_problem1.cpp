#include<iostream>
using namespace std;


struct Node
{
    int data;
    Node *prev;
    Node *next;

};

class DoubleyLinkedList
{
    private:
    Node*head;
    public:
    DoubleyLinkedList()
    {
        head= NULL;

    }
    void append(int value)
    {
        Node *newNode=new Node;
        newNode->data=value;
        newNode->next=NULL;
        newNode->prev=NULL;

        if(head==NULL)
        {
            head=newNode;
        }
        else{
            Node *current=head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next=newNode;
            newNode->prev=current;
        }
    }
    void display()
    {
        Node* current=head;
        while(current != NULL)
        {
            cout<<current->data<<" ";
            current=current->next;
        }
    }
};
int main()
{
    DoubleyLinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);
    cout<<"DoubleyLinked List: ";
    list.display();
    return 0;
}