#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;
    int id;
    int age;

public:
    Person(string n, int i, int a)
    {
        name = n;
        id = i;
        age = a;
    }

    string getName()
    {
        return name;
    }

    int getId()
    {
        return id;
    }

    int getAge()
    {
        return age;
    }
};

class Patient : public Person
{
private:
    string disease;
    int room;

public:
    Patient(string n, int i, int a, string d, int r)
        : Person(n, i, a)
    {
        disease = d;
        room = r;
    }

    void display()
    {
        cout << "Name: " << getName()
             << " | ID: " << getId()
             << " | Age: " << getAge()
             << " | Disease: " << disease
             << " | Room: " << room << endl;
    }
};

class Doctor : public Person
{
private:
    string specialization;

public:
    Doctor(string n, int i, int a, string s)
        : Person(n, i, a)
    {
        specialization = s;
    }

    void display()
    {
        cout << "Name: " << getName()
             << " | ID: " << getId()
             << " | Age: " << getAge()
             << " | Specialization: " << specialization << endl;
    }
};

class PatientList
{
private:
    Patient** patients;
    int size;
    int capacity;

    void increaseCapacity()
    {
        capacity = capacity * 2;

        Patient** newPatients = new Patient*[capacity];

        for (int i = 0; i < size; i++)
        {
            newPatients[i] = patients[i];
        }

        delete[] patients;
        patients = newPatients;
    }

public:
    PatientList()
    {
        size = 0;
        capacity = 2;
        patients = new Patient*[capacity];
    }

    ~PatientList()
    {
        for (int i = 0; i < size; i++)
        {
            delete patients[i];
        }

        delete[] patients;
    }

    void addPatient()
    {
        string name;
        string disease;
        int id;
        int age;
        int room;

        cout << "\n===== Add Patient =====\n";

        cout << "Enter patient name: ";
        cin >> name;

        cout << "Enter patient ID: ";
        cin >> id;

        cout << "Enter patient age: ";
        cin >> age;

        cout << "Enter disease: ";
        cin >> disease;

        cout << "Enter room number: ";
        cin >> room;

        if (size == capacity)
        {
            increaseCapacity();
        }

        patients[size] = new Patient(name, id, age, disease, room);
        size++;

        cout << "\nPatient added successfully!\n";
    }

    void removePatient()
    {
        int id;

        cout << "\n===== Remove Patient =====\n";
        cout << "Enter patient ID: ";
        cin >> id;

        for (int i = 0; i < size; i++)
        {
            if (patients[i]->getId() == id)
            {
                delete patients[i];

                for (int j = i; j < size - 1; j++)
                {
                    patients[j] = patients[j + 1];
                }

                size--;

                cout << "\nPatient removed successfully!\n";
                return;
            }
        }

        cout << "\nPatient not found!\n";
    }

    void searchPatient()
    {
        int id;

        cout << "\n===== Search Patient =====\n";
        cout << "Enter patient ID: ";
        cin >> id;

        for (int i = 0; i < size; i++)
        {
            if (patients[i]->getId() == id)
            {
                cout << "\nPatient Found\n";
                patients[i]->display();
                return;
            }
        }

        cout << "\nPatient not found!\n";
    }

    void displayPatients()
    {
        cout << "\n===== Display All Patients =====\n";

        if (size == 0)
        {
            cout << "No patients available.\n";
            return;
        }

        for (int i = 0; i < size; i++)
        {
            patients[i]->display();
        }
    }
};

int main()
{
    cout<<"AbuHuraira Shamraiz,73407"<<endl;
    PatientList hospital;
    int choice;

    do
    {
        cout << "\n===== Hospital Management System =====\n";
        cout << "1. Add Patient\n";
        cout << "2. Remove Patient\n";
        cout << "3. Search Patient\n";
        cout << "4. Display All Patients\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            hospital.addPatient();
        }
        else if (choice == 2)
        {
            hospital.removePatient();
        }
        else if (choice == 3)
        {
            hospital.searchPatient();
        }
        else if (choice == 4)
        {
            hospital.displayPatients();
        }
        else if (choice == 5)
        {
            cout << "\nThank you for using Hospital Management System.\n";
        }
        else
        {
            cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}