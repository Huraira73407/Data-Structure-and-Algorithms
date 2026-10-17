#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int arr[SIZE];
    int target;

    // 1. Input 5 elements
    cout << "Enter 5 integers:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Element " << (i + 1) << ": ";
        cin >> arr[i];
    }

    // 2. Sort array in ascending order (Selection Sort)
    for (int i = 0; i < SIZE - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the smallest found element with element at index i
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // Display sorted array
    cout << "\nSorted array in ascending order: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // 3. Input number to search
    cout << "\nEnter a number to search for: ";
    cin >> target;

    // 4. Binary Search (taking advantage of the sorted array)
    int low = 0;
    int high = SIZE - 1;
    int foundIndex = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            foundIndex = mid;
            break;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Output search result
    if (foundIndex != -1) {
        cout << "Result: " << target << " was found at index " << foundIndex << " in the sorted array.\n";
    } else {
        cout << "Result: " << target << " was NOT found in the array.\n";
    }

    return 0;
}