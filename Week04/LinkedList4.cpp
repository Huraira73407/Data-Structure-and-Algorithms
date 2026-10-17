#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class LinkedList
{
private:
    Node* head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void display()
    {
        Node* current = head;

        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    void remove(int position)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        if (position <= 0)
        {
            cout << "Invalid position." << endl;
            return;
        }

        if (position == 1)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;

        for (int i = 1; i < position - 1 && current != NULL; i++)
        {
            current = current->next;
        }

        if (current == NULL || current->next == NULL)
        {
            cout << "Position out of range." << endl;
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
    void append(int value)
    {
        Node* newNode=new Node;
        newNode->data=value;
        newNode->next=NULL;
        if(head==NULL)
        {
            head=newNode;
        }
        else
        {
            Node* current=head;
        }
    }
};
