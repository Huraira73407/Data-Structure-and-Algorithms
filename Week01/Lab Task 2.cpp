#include<iostream>
using namespace std;
int main()
{
	int marks[5];
	int* p = marks;

	for (int i = 0; i < 5; i++)
	{
		cout << "Enter Marks: ";
		cin >> *(p + i);

	}
	cout << "\nStudent Marks: ";
	for (int i = 0; i < 5; i++)
	{
		cout << *(p + i) << " ";
	}
	return 0;
}