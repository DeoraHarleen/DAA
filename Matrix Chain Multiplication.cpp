#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;

// Function to print the optimal parenthesization
void printOptimalParens(int s[MAX][MAX], int i, int j) {
    if (i == j)
        cout << "A" << i;
    else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

// Function to compute the matrix chain order using dynamic programming
void matrixChainOrder(int p[], int n) {
    int m[MAX][MAX]; // Matrix to store the number of multiplications
    int s[MAX][MAX]; // Matrix to store the split points

    // Initialize the main diagonal to zero
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // Compute the number of multiplications needed for each chain length
    for (int L = 2; L < n; L++) { // L is the chain length
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    // Print the optimal parenthesization
    cout << "Optimal Parenthesization: ";
    printOptimalParens(s, 1, n - 1);
    cout << endl;

    // Print the minimum number of multiplications needed
    cout << "Minimum number of multiplications: " << m[1][n - 1] << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    matrixChainOrder(arr, size);

    return 0;
}
