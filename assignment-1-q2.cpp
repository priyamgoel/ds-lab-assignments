// question 2 : given a sorted array, remove the duplicate elements from array 
#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    cout << "The unique elements in the array are: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int removeDuplicates(int arr[], int size) {
    if (size == 0 || size == 1) {
        return size;
    }

	// temp array
    int temp[size];
    int j = 0; 

    // Loop through original array
    for (int i = 0; i < size - 1; i++) {
        // If the current element is not equal to the next element,
        // it means it's a unique element because array is sorted
        if (arr[i] != arr[i + 1]) {
            temp[j++] = arr[i];
        }
    }
    
    //because the last element is unique
    temp[j++] = arr[size - 1];

    // Copy unique elements from temp array back to the original
    for (int i = 0; i < j; i++) {
        arr[i] = temp[i];
    }
    
    return j; 
}

int main() {
   
    int arr[] = {10, 20, 20, 30, 30, 30, 40, 50, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array size: " << n << endl;

    n = removeDuplicates(arr, n);

    printArray(arr, n);
    
    return 0;
}
