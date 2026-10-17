#include <iostream>

using namespace std;

// Struct to store product details
struct ProductNode {
    int id;
    char name[50];
    double price;
    int quantity;
    ProductNode* next;
};

// Class for Singly Linked List managing Inventory
class Inventory {
private:
    ProductNode* head;

public:
    Inventory() {
        head = NULL;
    }

    // 1. Add Product
    void addProduct(int id, char name[], double price, int quantity) {
        ProductNode* newNode = new ProductNode();
        newNode->id = id;
        
        // Copy char array manually using a simple loop inside function
        int i = 0;
        while (name[i] != '\0') {
            newNode->name[i] = name[i];
            i++;
        }
        newNode->name[i] = '\0';

        newNode->price = price;
        newNode->quantity = quantity;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            ProductNode* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Product added successfully!\n";
    }

    // 2. Display Products
    void displayProducts() {
        if (head == NULL) {
            cout << "Inventory is empty!\n";
            return;
        }
        cout << "\n--- Product Inventory ---\n";
        ProductNode* temp = head;
        while (temp != NULL) {
            cout << "ID: " << temp->id 
                 << " | Name: " << temp->name 
                 << " | Price: $" << temp->price 
                 << " | Quantity: " << temp->quantity << "\n";
            temp = temp->next;
        }
    }

    // 3. Search Product
    void searchProduct(int id) {
        ProductNode* temp = head;
        while (temp != NULL) {
            if (temp->id == id) {
                cout << "\nProduct Found!\n";
                cout << "ID: " << temp->id 
                     << " | Name: " << temp->name 
                     << " | Price: $" << temp->price 
                     << " | Quantity: " << temp->quantity << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Product with ID " << id << " not found!\n";
    }

    // 4. Update Stock
    void updateStock(int id, int newQuantity) {
        ProductNode* temp = head;
        while (temp != NULL) {
            if (temp->id == id) {
                temp->quantity = newQuantity;
                cout << "Stock updated successfully!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Product with ID " << id << " not found!\n";
    }

    // 5. Delete Product
    void deleteProduct(int id) {
        if (head == NULL) {
            cout << "Inventory is empty!\n";
            return;
        }

        // If head node is to be deleted
        if (head->id == id) {
            ProductNode* temp = head;
            head = head->next;
            delete temp;
            cout << "Product deleted successfully!\n";
            return;
        }

        ProductNode* current = head;
        ProductNode* previous = NULL;

        while (current != NULL && current->id != id) {
            previous = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Product with ID " << id << " not found!\n";
            return;
        }

        previous->next = current->next;
        delete current;
        cout << "Product deleted successfully!\n";
    }

    // 6. Display Low-Stock Products (< 10)
    void displayLowStock() {
        if (head == NULL) {
            cout << "Inventory is empty!\n";
            return;
        }
        cout << "\n--- Low Stock Products (Quantity < 10) ---\n";
        ProductNode* temp = head;
        bool found = false;
        while (temp != NULL) {
            if (temp->quantity < 10) {
                cout << "ID: " << temp->id 
                     << " | Name: " << temp->name 
                     << " | Quantity: " << temp->quantity << "\n";
                found = true;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "No low-stock products found.\n";
        }
    }

    // Destructor to free dynamically allocated nodes
    ~Inventory() {
        ProductNode* current = head;
        while (current != NULL) {
            ProductNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

// Node structure for Stack
struct StackNode {
    int productId;
    StackNode* next;
};

// Class for Stack (LIFO)
class OperationStack {
private:
    StackNode* top;

public:
    OperationStack() {
        top = NULL;
    }

    // 7. Add Stock Operation to Stack
    void push(int productId) {
        StackNode* newNode = new StackNode();
        newNode->productId = productId;
        newNode->next = top;
        top = newNode;
        cout << "Stock operation for Product ID " << productId << " added to stack.\n";
    }

    // 8. Remove Last Stack Operation
    void pop() {
        if (top == NULL) {
            cout << "Stack is empty! No operation to remove.\n";
            return;
        }
        StackNode* temp = top;
        int poppedId = temp->productId;
        top = top->next;
        delete temp;
        cout << "Removed recent operation for Product ID: " << poppedId << "\n";
    }

    // 9. Display Stack
    void displayStack() {
        if (top == NULL) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "\n--- Recent Operations Stack (Top to Bottom) ---\n";
        StackNode* temp = top;
        while (temp != NULL) {
            cout << "Product ID: " << temp->productId << "\n";
            temp = temp->next;
        }
    }

    ~OperationStack() {
        while (top != NULL) {
            StackNode* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

// Node structure for Queue
struct QueueNode {
    int orderId;
    QueueNode* next;
};

// Class for Queue (FIFO)
class OrderQueue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    OrderQueue() {
        front = NULL;
        rear = NULL;
    }

    // 10. Add Order to Queue
    void enqueue(int orderId) {
        QueueNode* newNode = new QueueNode();
        newNode->orderId = orderId;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Order ID " << orderId << " added to queue.\n";
    }

    // 11. Process Order
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty! No order to process.\n";
            return;
        }
        QueueNode* temp = front;
        int processedId = temp->orderId;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
        cout << "Processed Order ID: " << processedId << "\n";
    }

    // 12. Display Queue
    void displayQueue() {
        if (front == NULL) {
            cout << "Order Queue is empty!\n";
            return;
        }
        cout << "\n--- Pending Orders Queue (Front to Rear) ---\n";
        QueueNode* temp = front;
        while (temp != NULL) {
            cout << "Order ID: " << temp->orderId << "\n";
            temp = temp->next;
        }
    }

    ~OrderQueue() {
        while (front != NULL) {
            QueueNode* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

// 13. Demonstrate Array (5 products)
void demonstrateArray() {
    struct SimpleProduct {
        int id;
        char name[20];
        double price;
    };

    SimpleProduct staticArray[5] = {
        {101, "Keyboard", 25.50},
        {102, "Mouse", 15.00},
        {103, "Monitor", 180.00},
        {104, "Headphones", 45.00},
        {105, "USB Drive", 10.00}
    };

    cout << "\n--- Static Array of 5 Products ---\n";
    for (int i = 0; i < 5; i++) {
        cout << "Index [" << i << "] -> ID: " << staticArray[i].id
             << " | Name: " << staticArray[i].name
             << " | Price: $" << staticArray[i].price << "\n";
    }
}

// Main function with menu interface
int main() {
    Inventory storeInventory;
    OperationStack operationStack;
    OrderQueue orderQueue;

    int userChoice = 0;

    // Direct check for choice 14
    while (userChoice != 14) {
        cout << "\n=============================================\n";
        cout << "INVENTORY MANAGEMENT SYSTEM\n";
        cout << "=============================================\n";
        cout << "1. Add Product\n";
        cout << "2. Display Products\n";
        cout << "3. Search Product\n";
        cout << "4. Update Stock\n";
        cout << "5. Delete Product\n";
        cout << "6. Display Low - Stock Products\n";
        cout << "7. Add Stock Operation to Stack\n";
        cout << "8. Remove Last Stack Operation\n";
        cout << "9. Display Stack\n";
        cout << "10. Add Order to Queue\n";
        cout << "11. Process Order\n";
        cout << "12. Display Queue\n";
        cout << "13. Demonstrate Array\n";
        cout << "14. Exit\n";
        cout << "Enter your choice : ";
        cin >> userChoice;

        switch (userChoice) {
            case 1: {
                int productId, quantity;
                char name[50];
                double price;

                cout << "Enter Product ID: ";
                cin >> productId;
                cout << "Enter Product Name: ";
                cin >> name;
                cout << "Enter Product Price: ";
                cin >> price;
                cout << "Enter Product Quantity: ";
                cin >> quantity;

                storeInventory.addProduct(productId, name, price, quantity);
                break;
            }
            case 2:
                storeInventory.displayProducts();
                break;

            case 3: {
                int searchId;
                cout << "Enter Product ID to Search: ";
                cin >> searchId;
                storeInventory.searchProduct(searchId);
                break;
            }
            case 4: {
                int updateId, newQuantity;
                cout << "Enter Product ID to Update Stock: ";
                cin >> updateId;
                cout << "Enter New Quantity: ";
                cin >> newQuantity;
                storeInventory.updateStock(updateId, newQuantity);
                break;
            }
            case 5: {
                int deleteId;
                cout << "Enter Product ID to Delete: ";
                cin >> deleteId;
                storeInventory.deleteProduct(deleteId);
                break;
            }
            case 6:
                storeInventory.displayLowStock();
                break;

            case 7: {
                int operationId;
                cout << "Enter Product ID for Stock Operation: ";
                cin >> operationId;
                operationStack.push(operationId);
                break;
            }
            case 8:
                operationStack.pop();
                break;

            case 9:
                operationStack.displayStack();
                break;

            case 10: {
                int orderId;
                cout << "Enter Order ID to Enqueue: ";
                cin >> orderId;
                orderQueue.enqueue(orderId);
                break;
            }
            case 11:
                orderQueue.dequeue();
                break;

            case 12:
                orderQueue.displayQueue();
                break;

            case 13:
                demonstrateArray();
                break;

            case 14:
                cout << "\nExiting Inventory Management System. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please select a valid option from 1 to 14.\n";
                break;
        }
    }

    return 0;
}