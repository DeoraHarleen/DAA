#include <iostream>
#include <cstring>
using namespace std;

// Function to find the LCS length and store the DP table
void lcsLength(char X[], char Y[], int m, int n, int dp[][101]) {
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}

// Function to print the LCS using the DP table
void printLCS(char X[], char Y[], int m, int n, int dp[][101]) {
    int index = dp[m][n];
    char lcs[index + 1];
    lcs[index] = '\0'; // Set the terminating character

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    cout << "LCS: " << lcs << endl;
}

int main() {
    char X[] = "ABCBDAB";
    char Y[] = "BDCAB";

    int m = strlen(X);
    int n = strlen(Y);

    // DP table
    int dp[101][101];

    // Compute the length of LCS and fill the DP table
    lcsLength(X, Y, m, n, dp);

    // Print the LCS
    printLCS(X, Y, m, n, dp);

    return 0;
}
