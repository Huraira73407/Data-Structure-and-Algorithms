#include <iostream>

using namespace std;

// Class for Printer Queue Management System
class PrinterQueue {
private:
    // Node structure inside the class as required
    struct Node {
        int jobId;
        Node* next;
    };

    Node* frontNode;
    Node* rearNode;
    int totalJobsCount;

public:
    // Constructor initializing pointers to NULL and count to 0
    PrinterQueue() {
        frontNode = NULL;
        rearNode = NULL;
        totalJobsCount = 0;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return frontNode == NULL;
    }

    // Return total number of pending jobs
    int size() {
        return totalJobsCount;
    }

    // Add a print job at the rear of the queue (Enqueue)
    void addJob(int id) {
        Node* newJobNode = new Node();
        newJobNode->jobId = id;
        newJobNode->next = NULL;

        if (isEmpty()) {
            frontNode = newJobNode;
            rearNode = newJobNode;
        } else {
            rearNode->next = newJobNode;
            rearNode = newJobNode;
        }

        totalJobsCount++;
        cout << "Added Job ID : " << id << "\n";
    }

    // Process a print job from the front of the queue (Dequeue)
    void processJob() {
        if (isEmpty()) {
            cout << "Queue is empty! No jobs to process.\n";
            return;
        }

        Node* temporaryNode = frontNode;
        int currentJobId = temporaryNode->jobId;

        frontNode = frontNode->next;

        if (frontNode == NULL) {
            rearNode = NULL;
        }

        delete temporaryNode;
        totalJobsCount--;

        cout << "Processing Job ID : " << currentJobId << "\n";
    }

    // Return the front job ID without removing it
    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return frontNode->jobId;
    }

    // Display all pending jobs from front to rear
    void display() {
        if (isEmpty()) {
            cout << "Queue is now empty .\n";
            return;
        }

        cout << "--- Pending Jobs ( Front to Rear ) ---\n";
        Node* currentPointer = frontNode;
        while (currentPointer != NULL) {
            cout << currentPointer->jobId << " ";
            currentPointer = currentPointer->next;
        }
        cout << "\n";
    }

    // Destructor to release dynamically allocated memory
    ~PrinterQueue() {
        while (frontNode != NULL) {
            Node* temporaryNode = frontNode;
            frontNode = frontNode->next;
            delete temporaryNode;
        }
        rearNode = NULL;
        totalJobsCount = 0;

        cout << "==========================================================\n";
        cout << "All memory released successfully .\n";
        cout << "==========================================================\n";
    }
};

int main() {
    cout << "========== PRINTER QUEUE MANAGEMENT ==========\n";

    PrinterQueue printerQueueSystem;

    // 1. Add 4 jobs
    printerQueueSystem.addJob(101);
    printerQueueSystem.addJob(102);
    printerQueueSystem.addJob(103);
    printerQueueSystem.addJob(104);

    // 2. Display queue
    printerQueueSystem.display();

    // 3. Process 2 jobs
    printerQueueSystem.processJob();
    printerQueueSystem.processJob();


    // 4. Display queue again
    printerQueueSystem.display();

    // 5. Show front job and current queue size
    cout << "Front Job : " << printerQueueSystem.peek() << "\n";
    cout << "Queue Size : " << printerQueueSystem.size() << "\n";

    // 6. Process remaining jobs
    printerQueueSystem.processJob();
    printerQueueSystem.processJob();

    // 7. Verify queue is empty
    printerQueueSystem.display();

    return 0;
}