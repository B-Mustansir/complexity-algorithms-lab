#include <bits/stdc++.h>
using namespace std;

void findLargest(int arr[], int size) {
    int maxNum = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxNum) {
            maxNum = arr[i];
        }
    }
    cout << "Largest number: " << maxNum << endl;
}

void findSecondMin(int arr[], int size) {
    int minNum = INT_MAX;
    int secondMin = INT_MAX;

    for (int i = 0; i < size; ++i) {
        if (arr[i] < minNum) {
            secondMin = minNum;
            minNum = arr[i];
        } else if (arr[i] < secondMin && arr[i] != minNum) {
            secondMin = arr[i];
        }
    }
    cout << "Second minimum number: " << secondMin << endl;
}

void matrixMultiplication() {
    int n, m;
    cout << "Enter the number of rows (n): ";
    cin >> n;
    cout << "Enter the number of columns (m): ";
    cin >> m;

    int matrix1[n][m], matrix2[n][m], result[n][m];

    cout << "Enter elements of first matrix:" << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matrix1[i][j];

    cout << "Enter elements of second matrix:" << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matrix2[i][j];

    // Multiplication logic
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < m; ++k)
                result[i][j] += matrix1[i][k] * matrix2[k][j];
        }

    cout << "Multiplication Result:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << result[i][j] << " ";
        cout << endl;
    }
}

void sumOfDiagonal() {
    int n;
    cout << "Enter the size of the square matrix (n): ";
    cin >> n;

    int matrix[n][n];

    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];

    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += matrix[i][i];

    cout << "Sum of diagonal elements: " << sum << endl;
}

void lowerTriangle() {
    int n, m;
    cout << "Enter the number of rows (n): ";
    cin >> n;
    cout << "Enter the number of columns (m): ";
    cin >> m;

    int matrix[n][m];

    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matrix[i][j];

    cout << "Lower Triangle Matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i >= j)
                cout << matrix[i][j] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main() {
    int choice;
    int arr[10];

    cout << "Menu:\n";
    cout << "1. Find largest number in an array\n";
    cout << "2. Find second minimum number in an array\n";
    cout << "3. Matrix Multiplication\n";
    cout << "4. Sum of Diagonal Elements in a Matrix\n";
    cout << "5. Lower Triangle of a Matrix\n";
    cout << "Enter your choice (1-5): ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter 10 integers in the array:" << endl;
            for (int i = 0; i < 10; ++i)
                cin >> arr[i];
            findLargest(arr, 10);
            break;
        case 2:
            cout << "Enter 10 integers in the array:" << endl;
            for (int i = 0; i < 10; ++i)
                cin >> arr[i];
            findSecondMin(arr, 10);
            break;
        case 3:
            matrixMultiplication();
            break;
        case 4:
            sumOfDiagonal();
            break;
        case 5:
            lowerTriangle();
            break;
        default:
            cout << "Invalid choice!\n";
    }

    return 0;
}
