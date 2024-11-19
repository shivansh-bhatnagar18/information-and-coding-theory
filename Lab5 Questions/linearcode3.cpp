#include <bits/stdc++.h>
using namespace std;

// Function to compute the generator matrix G from the parity-check matrix H
vector<vector<int>> getGeneratorMatrix(const vector<vector<int>> &H, int n, int r) {
    int k = n - r; // Number of rows in G
    vector<vector<int>> G(k, vector<int>(n, 0));

    // Construct the identity matrix for the first k columns
    for (int i = 0; i < k; ++i) {
        G[i][i] = 1;
    }

    // Extract the parity section from H and transpose it
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < k; ++j) {
            G[j][k + i] = H[i][j];
        }
    }

    return G;
}

// Print a matrix
void printMatrix(const vector<vector<int>> &matrix) {
    for (const auto &row : matrix) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
}

int main() {
    int r, n;

    // Input the dimensions of the parity-check matrix H (r x n)
    cin >> r >> n;
    vector<vector<int>> H(r, vector<int>(n));

    // Input the parity-check matrix H
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> H[i][j];
        }
    }

    // Compute the generator matrix G
    vector<vector<int>> G = getGeneratorMatrix(H, n, r);

    // Output the generator matrix G
    cout << "Generator matrix G:" << endl;
    printMatrix(G);

    return 0;
}
