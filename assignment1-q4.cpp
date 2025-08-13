/* question 4 :
Implement the logic to
a. Reverse the elements of an array
b. Find the matrix multiplication
c. Find the Transpose of a Matrix
*/ 

#include <iostream>
using namespace std;

// print 1d array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// print 2d matrix
void printMatrix(int matrix[3][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// 
// a. Reverse the elements of an array
// 
void reverseArray(int arr[], int size) {
    // We use two pointers: 'start' at the beginning and 'end' at the end.
    int start = 0;
    int end = size - 1;

    // Loop until the pointers meet in the middle.
    while (start < end) {
        // Swap the elements at the start and end positions.
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move the pointers towards each other.
        start++;
        end--;
    }
}

//
// b. Find the matrix multiplication
//
void multiplyMatrices(int matA[3][3], int matB[3][3], int result[3][3], int rowsA, int colsA, int rowsB, int colsB) {
    // The number of columns in the first matrix (colsA) must be equal to
    // the number of rows in the second matrix (rowsB) for multiplication to be possible.
    if (colsA != rowsB) {
        cout << "Matrix multiplication is not possible. Columns of first matrix must equal rows of second." << endl;
        return;
    }

    // Initialize all elements of the result matrix to 0.
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
        }
    }

    // Perform the matrix multiplication using three nested loops.
    // i: iterates through rows of matrix A
    // j: iterates through columns of matrix B
    // k: iterates through columns of A and rows of B
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

//
// c. Find the Transpose of a Matrix
//
void transposeMatrix(int matrix[3][3], int transpose[3][3], int rows, int cols) {
    // The transpose of a matrix is found by swapping its rows with columns.
    // The element at matrix[i][j] becomes the element at transpose[j][i].
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

int main() {
    // --- PART A: Reverse the elements of an array ---
    cout << "--- PART A: REVERSE ARRAY ---" << endl;
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArray(arr, n);

    reverseArray(arr, n);
    cout << "Reversed array: ";
    printArray(arr, n);
    cout << endl;

    // --- PART B: Matrix Multiplication ---
    cout << "--- PART B: MATRIX MULTIPLICATION ---" << endl;
    int matA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matB[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[3][3];

    cout << "Matrix A:" << endl;
    printMatrix(matA, 3, 3);
    cout << "Matrix B:" << endl;
    printMatrix(matB, 3, 3);
    
    multiplyMatrices(matA, matB, result, 3, 3, 3, 3);

    cout << "Result of Matrix Multiplication:" << endl;
    printMatrix(result, 3, 3);
    cout << endl;

    // --- PART C: Transpose of a Matrix ---
    cout << "--- PART C: TRANSPOSE OF A MATRIX ---" << endl;
    int original[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int transposed[3][3];

    cout << "Original Matrix:" << endl;
    printMatrix(original, 3, 3);

    transposeMatrix(original, transposed, 3, 3);
    
    cout << "Transposed Matrix:" << endl;
    printMatrix(transposed, 3, 3);
    cout << endl;

    return 0;
}

