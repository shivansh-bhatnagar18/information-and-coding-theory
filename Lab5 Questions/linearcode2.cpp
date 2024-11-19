#include <bits/stdc++.h>
using namespace std;

// Function to compute the parity-check matrix H from the generator matrix G
vector<vector<int>> getParityCheckMatrix(const vector<vector<int>> &G, int n, int k) {
    int r = n - k; // Number of parity-check rows
    vector<vector<int>> H(r, vector<int>(n, 0));

    // Extract the parity bits (last n-k columns of G)
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < k; ++j) {
            H[i][j] = G[j][k + i];
        }
    }

    // Append an identity matrix of size r x r to complete H
    for (int i = 0; i < r; ++i) {
        H[i][k + i] = 1;
    }

    return H;
}

// Print a matrix
void printMatrix(const vector<vector<int>> &matrix) {
    for (const auto &row : matrix) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
}

int main() {
    int k, n;

    // Input the dimensions of the generator matrix G (k x n)
    cin >> k >> n;
    vector<vector<int>> G(k, vector<int>(n));

    // Input the generator matrix G
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> G[i][j];
        }
    }

    // Compute the parity-check matrix H
    vector<vector<int>> H = getParityCheckMatrix(G, n, k);

    // Output the parity-check matrix H
    cout << "Parity-check matrix H:" << endl;
    printMatrix(H);

    return 0;
}
