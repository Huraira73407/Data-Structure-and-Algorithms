#include <iostream>
#include <string>
using namespace std;

// ==================== SINGLY LINKED LIST ====================

struct Patient
{
    int id;
    string name;
    int age;
    string disease;
    Patient *next;
};

Patient *patientHead = NULL;

void addPatient()
{
    Patient *newPatient = new Patient;

    cout << "\nEnter Patient ID: ";
    cin >> newPatient->id;

    cout << "Enter Patient Name: ";
    cin >> newPatient->name;

    cout << "Enter Age: ";
    cin >> newPatient->age;

    cout << "Enter Disease: ";
    cin >> newPatient->disease;

    newPatient->next = NULL;

    if (patientHead == NULL)
    {
        patientHead = newPatient;
    }
    else
    {
        Patient *temp = patientHead;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newPatient;
    }

    cout << "Patient registered successfully.\n";
}

void searchPatient()
{
    if (patientHead == NULL)
    {
        cout << "\nNo patients registered.\n";
        return;
    }

    int id;
    cout << "\nEnter Patient ID to search: ";
    cin >> id;

    Patient *temp = patientHead;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "\nPatient Found\n";
            cout << "ID: " << temp->id << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Age: " << temp->age << endl;
            cout << "Disease: " << temp->disease << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Patient not found.\n";
}

void removePatient()
{
    if (patientHead == NULL)
    {
        cout << "\nNo patients registered.\n";
        return;
    }

    int id;
    cout << "\nEnter Patient ID to remove: ";
    cin >> id;

    Patient *temp = patientHead;
    Patient *previous = NULL;

    if (temp->id == id)
    {
        patientHead = temp->next;
        delete temp;

        cout << "Patient removed successfully.\n";
        return;
    }

    while (temp != NULL && temp->id != id)
    {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Patient not found.\n";
        return;
    }

    previous->next = temp->next;
    delete temp;

    cout << "Patient removed successfully.\n";
}

void displayPatients()
{
    if (patientHead == NULL)
    {
        cout << "\nNo patients registered.\n";
        return;
    }

    Patient *temp = patientHead;

    cout << "\n===== REGISTERED PATIENTS =====\n";

    while (temp != NULL)
    {
        cout << "ID: " << temp->id
             << " | Name: " << temp->name
             << " | Age: " << temp->age
             << " | Disease: " << temp->disease << endl;

        temp = temp->next;
    }
}

// ==================== DOUBLY LINKED LIST ====================

struct History
{
    int id;
    string name;
    History *previous;
    History *next;
};

History *historyHead = NULL;
History *historyTail = NULL;

void addHistory()
{
    History *newHistory = new History;

    cout << "\nEnter Treated Patient ID: ";
    cin >> newHistory->id;

    cout << "Enter Patient Name: ";
    cin >> newHistory->name;

    newHistory->previous = NULL;
    newHistory->next = NULL;

    if (historyHead == NULL)
    {
        historyHead = newHistory;
        historyTail = newHistory;
    }
    else
    {
        historyTail->next = newHistory;
        newHistory->previous = historyTail;
        historyTail = newHistory;
    }

    cout << "Patient added to treatment history.\n";
}

void displayHistoryForward()
{
    if (historyHead == NULL)
    {
        cout << "\nNo treatment history available.\n";
        return;
    }

    History *temp = historyHead;

    cout << "\n===== HISTORY FORWARD =====\n";

    while (temp != NULL)
    {
        cout << "ID: " << temp->id
             << " | Name: " << temp->name << endl;

        temp = temp->next;
    }
}

void displayHistoryReverse()
{
    if (historyTail == NULL)
    {
        cout << "\nNo treatment history available.\n";
        return;
    }

    History *temp = historyTail;

    cout << "\n===== HISTORY REVERSE =====\n";

    while (temp != NULL)
    {
        cout << "ID: " << temp->id
             << " | Name: " << temp->name << endl;

        temp = temp->previous;
    }
}

// ==================== CIRCULAR LINKED LIST ====================

struct Appointment
{
    int id;
    string name;
    Appointment *next;
};

Appointment *appointmentHead = NULL;
Appointment *appointmentCurrent = NULL;

void addAppointment()
{
    Appointment *newAppointment = new Appointment;

    cout << "\nEnter Patient ID: ";
    cin >> newAppointment->id;

    cout << "Enter Patient Name: ";
    cin >> newAppointment->name;

    if (appointmentHead == NULL)
    {
        appointmentHead = newAppointment;
        newAppointment->next = appointmentHead;
        appointmentCurrent = appointmentHead;
    }
    else
    {
        Appointment *temp = appointmentHead;

        while (temp->next != appointmentHead)
        {
            temp = temp->next;
        }

        temp->next = newAppointment;
        newAppointment->next = appointmentHead;
    }

    cout << "Appointment added successfully.\n";
}

void displayAppointments()
{
    if (appointmentHead == NULL)
    {
        cout << "\nNo appointments available.\n";
        return;
    }

    Appointment *temp = appointmentHead;

    cout << "\n===== APPOINTMENTS =====\n";

    do
    {
        cout << "ID: " << temp->id
             << " | Name: " << temp->name << endl;

        temp = temp->next;

    } while (temp != appointmentHead);
}

void nextAppointment()
{
    if (appointmentCurrent == NULL)
    {
        cout << "\nNo appointments available.\n";
        return;
    }

    appointmentCurrent = appointmentCurrent->next;

    cout << "\nNext Appointment:\n";
    cout << "ID: " << appointmentCurrent->id << endl;
    cout << "Name: " << appointmentCurrent->name << endl;
}

// ==================== STACK ADT ====================

struct Emergency
{
    int id;
    string name;
    Emergency *next;
};

Emergency *top = NULL;

void pushEmergency()
{
    Emergency *newEmergency = new Emergency;

    cout << "\nEnter Emergency Patient ID: ";
    cin >> newEmergency->id;

    cout << "Enter Patient Name: ";
    cin >> newEmergency->name;

    newEmergency->next = top;
    top = newEmergency;

    cout << "Emergency patient added to stack.\n";
}

void popEmergency()
{
    if (top == NULL)
    {
        cout << "\nStack is empty.\n";
        return;
    }

    Emergency *temp = top;

    cout << "\nRemoved Emergency Patient:\n";
    cout << "ID: " << temp->id << endl;
    cout << "Name: " << temp->name << endl;

    top = top->next;

    delete temp;
}

void peekEmergency()
{
    if (top == NULL)
    {
        cout << "\nStack is empty.\n";
        return;
    }

    cout << "\nTop Emergency Patient:\n";
    cout << "ID: " << top->id << endl;
    cout << "Name: " << top->name << endl;
}

void displayEmergency()
{
    if (top == NULL)
    {
        cout << "\nNo emergency patients.\n";
        return;
    }

    Emergency *temp = top;

    cout << "\n===== EMERGENCY PATIENTS =====\n";

    while (temp != NULL)
    {
        cout << "ID: " << temp->id
             << " | Name: " << temp->name << endl;

        temp = temp->next;
    }
}

// ==================== MENUS ====================

void patientMenu()
{
    int choice;

    do
    {
        cout << "\n===== PATIENT REGISTRATION =====\n";
        cout << "1. Add Patient\n";
        cout << "2. Search Patient\n";
        cout << "3. Remove Patient\n";
        cout << "4. Display Patients\n";
        cout << "5. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
            addPatient();
        else if (choice == 2)
            searchPatient();
        else if (choice == 3)
            removePatient();
        else if (choice == 4)
            displayPatients();
        else if (choice == 5)
            cout << "Returning to main menu...\n";
        else
            cout << "Invalid choice.\n";

    } while (choice != 5);
}

void historyMenu()
{
    int choice;

    do
    {
        cout << "\n===== PATIENT HISTORY =====\n";
        cout << "1. Add Treated Patient\n";
        cout << "2. Display History Forward\n";
        cout << "3. Display History Reverse\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
            addHistory();
        else if (choice == 2)
            displayHistoryForward();
        else if (choice == 3)
            displayHistoryReverse();
        else if (choice == 4)
            cout << "Returning to main menu...\n";
        else
            cout << "Invalid choice.\n";

    } while (choice != 4);
}

void appointmentMenu()
{
    int choice;

    do
    {
        cout << "\n===== APPOINTMENT MANAGEMENT =====\n";
        cout << "1. Add Appointment\n";
        cout << "2. Display Appointments\n";
        cout << "3. Move to Next Appointment\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
            addAppointment();
        else if (choice == 2)
            displayAppointments();
        else if (choice == 3)
            nextAppointment();
        else if (choice == 4)
            cout << "Returning to main menu...\n";
        else
            cout << "Invalid choice.\n";

    } while (choice != 4);
}

void emergencyMenu()
{
    int choice;

    do
    {
        cout << "\n===== EMERGENCY MANAGEMENT =====\n";
        cout << "1. Push Emergency Patient\n";
        cout << "2. Pop Emergency Patient\n";
        cout << "3. Peek Emergency Patient\n";
        cout << "4. Display Emergency Patients\n";
        cout << "5. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
            pushEmergency();
        else if (choice == 2)
            popEmergency();
        else if (choice == 3)
            peekEmergency();
        else if (choice == 4)
            displayEmergency();
        else if (choice == 5)
            cout << "Returning to main menu...\n";
        else
            cout << "Invalid choice.\n";

    } while (choice != 5);
}

// ==================== MAIN FUNCTION ====================

int main()
{

    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "   HOSPITAL PATIENT MANAGEMENT\n";
        cout << "====================================\n";
        cout << "1. Patient Registration\n";
        cout << "2. Patient History\n";
        cout << "3. Appointment Management\n";
        cout << "4. Emergency Management\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
            patientMenu();

        else if (choice == 2)
            historyMenu();

        else if (choice == 3)
            appointmentMenu();

        else if (choice == 4)
            emergencyMenu();

        else if (choice == 5)
            cout << "\nThank you for using Hospital Management System.\n";

        else
            cout << "\nInvalid choice. Try again.\n";

    } while (choice != 5);

    return 0;
}