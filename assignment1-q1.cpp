/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;


const int MAX_SIZE = 100;


// in insert, delete and create, we pass by reference to make sure that the size gets updated after the function executes

void create(int arr[], int &size);
void display(int arr[], int size);
void insertElement(int arr[], int &size);
void deleteElement(int arr[], int &size);
void linearSearch(const int arr[], int size);

int main()
{   int arr[MAX_SIZE];
    int currentSize = 0;
    
    int choice;
    do {
    cout << "----Enter function to use: \n";
    cout << "1) CREATE \n";
    cout << "2) DISPLAY \n";
    cout << "3) INSERT \n";
    cout << "4) DELETE \n";
    cout << "5) LINEAR SEARCH \n";
    cout << "6) EXIT \n";
    cout << "--------------\n";
    cout << "Enter your choice \n";
    cin >> choice;
    
    switch (choice) {
        case 1: 
        create(arr, currentSize);
        break;
        case 2:
        display(arr, currentSize);
        break;
        case 3:
        insertElement(arr, currentSize);
        break;
        case 4:
        deleteElement(arr, currentSize);
        break;
        case 5:
        linearSearch(arr, currentSize);
        break;
        case 6:
        cout << "The program is exiting! \n";
        break;
        default:
        cout << "Invalid Choice. Please try again \n";
    }   
    }while (choice != 6);
    return 0;
}
    void create(int arr[], int &size) {
    cout << "Enter the number of elements faor the array (max " << MAX_SIZE << "): ";
    cin >> size;

// check if size is valid or not
    if (size > MAX_SIZE || size < 0) {
        cout << "Error: Invalid size. Size must be between 0 and " << MAX_SIZE << ".\n";
        size = 0; // reset the size if not valid
        return;
    }   
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << "Array created successfully.\n";
}
    
    
    void display(int arr[], int size) {
    if(size ==0) {
        cout << "Array is empty";
        return;
    }
    
    cout << " Array elements are: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

    void insertElement(int arr[], int &size) {
    if (size >= MAX_SIZE) {
        cout << "Error: Array is full. Cannot insert new element.\n";
        return;
    }
    
    
    // taking input from user to tell the position and value of the element to insert 
    int pos, value;
    cout << "Enter the position to insert (1 to " << size + 1 << "): ";
    cin >> pos;

    if (pos < 1 || pos > size + 1) {
        cout << "Error: Invalid position.\n";
        return;
    }

    cout << "Enter the value to insert: ";
    cin >> value;
    
    
    // Shift elements to the right to make space.
    for (int i = size; i >= pos; --i) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element and increase the array's size.
    arr[pos - 1] = value;
    size++;

    cout << "Element inserted successfully.\n";
}

// Deletes an element from a specific position in the array.
void deleteElement(int arr[], int &size) {
    if (size == 0) {
        cout << "Error: Array is empty. Cannot delete.\n";
        return;
    }

    int pos;
    cout << "Enter the position of the element to delete (1 to " << size << "): ";
    cin >> pos;

    if (pos < 1 || pos > size) {
        cout << "Error: Invalid position.\n";
        return;
    }

    // Shift elements to the left to fill the gap.
    for (int i = pos - 1; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    // Decrease the array's size.
    size--;

    cout << "Element deleted successfully.\n";
}


// Searches for an element in the array and reports its position.
void linearSearch(const int arr[], int size) {
    if (size == 0) {
        cout << "Array is empty. Cannot perform search.\n";
        return;
    }

    int value;
    cout << "Enter the element to search for: ";
    cin >> value;

    // Loop through the array to find the element.
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            cout << "Element " << value << " found at position " << i + 1 << ".\n";
            return; // Exit function once found
        }
    }

    // If the loop finishes, the element was not in the array.
    cout << "Element " << value << " not found in the array.\n";
}



