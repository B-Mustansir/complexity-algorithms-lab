#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

void removeDuplicates(std::vector<int> &vec) {
    std::unordered_set<int> uniqueSet;
    vec.erase(std::remove_if(vec.begin(), vec.end(), [&](int num) {
        return !uniqueSet.insert(num).second;
    }), vec.end());
}

void sumUpperRightTriangular(const std::vector<std::vector<int>> &matrix) {
    int n = matrix.size();
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            sum += matrix[i][j];
        }
    }

    std::cout << "Sum of upper right triangular matrix: " << sum << std::endl;
}

void printEvenNumbers(const std::vector<std::vector<int>> &matrix) {
    std::cout << "Even numbers in the matrix: ";
    for (const auto &row : matrix) {
        for (int num : row) {
            if (num % 2 == 0) {
                std::cout << num << " ";
            }
        }
    }
    std::cout << std::endl;
}

int largestElementLowerTriangle(const std::vector<std::vector<int>> &matrix) {
    int n = matrix.size();
    int maxElement = matrix[n - 1][0];

    for (int i = n - 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > j && matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
            }
        }
    }

    return maxElement;
}

void printLowerTriangles(const std::vector<std::vector<int>> &matrix) {
    std::cout << "Left lower triangle of matrix:" << std::endl;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Right lower triangle of matrix:" << std::endl;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = matrix.size() - i - 1; j < matrix.size(); ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int choice;
    std::vector<int> vec;
    std::vector<std::vector<int>> matrix;
    int n;

    std::cout << "Enter the size of array or matrix (<=10): ";
    std::cin >> n;

    std::cout << "Choose input type:\n1. Matrix\n2. Array\nEnter your choice: ";
    std::cin >> choice;

    if (choice == 1) {
        matrix.resize(n, std::vector<int>(n));
        std::cout << "Enter matrix elements:" << std::endl;
        for (int i = 0; i < n; ++i) {
            std::cout << "Row " << i + 1 << ": ";
            for (int j = 0; j < n; ++j) {
                std::cin >> matrix[i][j];
            }
        }
    } else if (choice == 2) {
        vec.resize(n);
        std::cout << "Enter array elements: ";
        for (int i = 0; i < n; ++i) {
            std::cin >> vec[i];
        }
    } else {
        std::cout << "Invalid choice. Exiting the program. Bye!" << std::endl;
        return 0;
    }

    do {
        std::cout << "\nMenu:\n1. Identify and remove duplicates\n2. Sum of upper right triangular matrix\n3. Print even numbers\n4. Largest element in lower triangle\n5. Print lower triangles\n0. Exit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                if (vec.empty()) {
                    std::cout << "Duplicates removed from matrix." << std::endl;
                    removeDuplicates(matrix[0]);
                } else {
                    std::cout << "Duplicates removed from array." << std::endl;
                    removeDuplicates(vec);

                    // Print the array after removing duplicates
                    std::cout << "Array after removing duplicates: ";
                    for (int num : vec) {
                        std::cout << num << " ";
                    }
                    std::cout << std::endl;
                }
                break;

            case 2:
                if (matrix.empty()) {
                    std::cout << "Sum of upper right triangular matrix:" << std::endl;
                    sumUpperRightTriangular(matrix);
                } else {
                    std::cout << "Sum of upper right triangular matrix:" << std::endl;
                    sumUpperRightTriangular(matrix);
                }
                break;

            case 3:
                printEvenNumbers(matrix);
                break;

            case 4: {
                int result = largestElementLowerTriangle(matrix);
                std::cout << "Largest element in lower triangle: " << result << std::endl;
                break;
            }

            case 5:
                printLowerTriangles(matrix);
                break;

            case 0:
                std::cout << "Exiting the program. Bye!" << std::endl;
                break;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != 0);

    return 0;
}
