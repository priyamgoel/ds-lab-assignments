//Question 5 : Write a program to find sum of every row and every column in a two-dimensional array.

#include <iostream>
using namespace std;

int main() {
    // We'll use a 3x3 matrix as an example.
    const int ROWS = 3;
    const int COLS = 3;
    int matrix[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    cout << "Given 2D Matrix:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // --- Calculate the sum of each row ---
    cout << "Sum of each row:" << endl;
    for (int i = 0; i < ROWS; i++) {
        int rowSum = 0; // Initialize row sum for each new row
        for (int j = 0; j < COLS; j++) {
            rowSum += matrix[i][j];
        }
        cout << "Sum of row " << i + 1 << ": " << rowSum << endl;
    }
    cout << endl;

    // --- Calculate the sum of each column ---
    cout << "Sum of each column:" << endl;
    for (int j = 0; j < COLS; j++) {
        int colSum = 0; // Initialize column sum for each new column
        for (int i = 0; i < ROWS; i++) {
            colSum += matrix[i][j];
        }
        cout << "Sum of column " << j + 1 << ": " << colSum << endl;
    }
    cout << endl;
    
    return 0;
}
