#include <iostream>
#include <cmath>
using namespace std;.10

const int MAX = 10; // Maximum size for chessboard

// Function to print the board configuration
void printBoard(int board[MAX][MAX], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if placing a queen at board[row][col] is safe
bool isSafe(int board[MAX][MAX], int row, int col, int N) {
    // Check if there is a queen in the current column
    for (int i = 0; i < row; i++) {
        if (board[i][col])
            return false;
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // Check upper diagonal on right side
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j])
            return false;
    }

    return true;
}

// Function to solve N-Queens problem using backtracking
bool solveNQueens(int board[MAX][MAX], int row, int N) {
    // Base case: If all queens are placed, return true
    if (row == N)
        return true;

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            // Place the queen
            board[row][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueens(board, row + 1, N))
                return true;

            // Backtrack: If placing queen at board[row][col] doesn't lead to a solution, remove it
            board[row][col] = 0;
        }
    }

    // If no column is safe in this row, return false
    return false;
}

// Function to solve the N-Queens problem and print all solutions
void solveNQueensWrapper(int N) {
    int board[MAX][MAX] = {0}; // Initialize board with zeros

    if (solveNQueens(board, 0, N)) {
        cout << "Solution found:\n";
        printBoard(board, N);
    } else {
        cout << "No solution exists for N = " << N << endl;
    }
}

int main() {
    int N = 4; // Size of the chessboard and number of queens
    solveNQueensWrapper(N);

    return 0;
}
