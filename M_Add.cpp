#include <iostream>
#include <vector>

using namespace std;

// Function to add two matrices
vector<vector<int>> addMatrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    // Check if matrices have the same dimensions
    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) {
        throw invalid_argument("Matrices must have the same dimensions for addition.");
    }

    // Initialize the result matrix with zeros
    vector<vector<int>> result(matrix1.size(), vector<int>(matrix1[0].size(), 0));

    // Perform element-wise addition
    for (size_t i = 0; i < matrix1.size(); ++i) {
        for (size_t j = 0; j < matrix1[0].size(); ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    // Sample matrices
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<int>> matrix2 = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    try {
        // Add the matrices
        vector<vector<int>> result = addMatrices(matrix1, matrix2);

        // Print the result
        cout << "Resultant Matrix:" << endl;
        printMatrix(result);
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
