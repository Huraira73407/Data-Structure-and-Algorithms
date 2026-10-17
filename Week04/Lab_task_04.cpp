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
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;

        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

   
    void append(int value)
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node* current = head;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = newNode;
    }

  
    void add(int value, int position)
    {
        if (position <= 0)
        {
            cout << "Invalid position." << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

     
        if (position == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;

        for (int i = 1; i < position - 1 && current != NULL; i++)
        {
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "Position out of range." << endl;
            delete newNode;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
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

  
    void dlt(int value)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        
        if (head->data == value)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;

        while (current->next != NULL && current->next->data != value)
        {
            current = current->next;
        }

        if (current->next == NULL)
        {
            cout << "Value not found." << endl;
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
};

int main()
{
    LinkedList list;

    int choice;
    int value;
    int position;

    do
    {
        cout << "\n===== Linked List Menu =====" << endl;
        cout << "1. Append" << endl;
        cout << "2. Add at Position" << endl;
        cout << "3. Remove from Position" << endl;
        cout << "4. Delete by Value" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;

            list.append(value);

            cout << "Value appended successfully." << endl;
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> position;

            list.add(value, position);

            break;

        case 3:
            cout << "Enter position to remove: ";
            cin >> position;

            list.remove(position);

            break;

        case 4:
            cout << "Enter value to delete: ";
            cin >> value;

            list.dlt(value);

            break;

        case 5:
            cout << "Linked List: ";
            list.display();

            break;

        case 6:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 6);

    return 0;
}
