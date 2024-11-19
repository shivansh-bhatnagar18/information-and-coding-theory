#include <bits/stdc++.h>
using namespace std;

// Convert a binary string to a vector of integers
vector<int> stringToVector(const string &s) {
    vector<int> v;
    for (char c : s) v.push_back(c - '0');
    return v;
}

// Gaussian elimination to find the row echelon form
void gaussianElimination(vector<vector<int>> &matrix, int n, int m) {
    int row = 0;
    for (int col = 0; col < m && row < n; ++col) {
        int sel = row;
        for (int i = row; i < n; ++i) {
            if (matrix[i][col]) {
                sel = i;
                break;
            }
        }
        if (!matrix[sel][col]) continue;
        swap(matrix[sel], matrix[row]);
        for (int i = 0; i < n; ++i) {
            if (i != row && matrix[i][col]) {
                for (int j = col; j < m; ++j) {
                    matrix[i][j] ^= matrix[row][j];
                }
            }
        }
        ++row;
    }
}

// Compute the generator matrix
vector<vector<int>> getGeneratorMatrix(vector<string> &S, int n) {
    vector<vector<int>> G;
    for (const auto &s : S) {
        G.push_back(stringToVector(s));
    }
    gaussianElimination(G, G.size(), n);
    return G;
}

// Compute the parity-check matrix from the generator matrix
vector<vector<int>> getParityCheckMatrix(vector<vector<int>> &G, int n) {
    int k = G.size();
    int r = n - k;
    vector<vector<int>> H(r, vector<int>(n, 0));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < k; ++j) {
            H[i][j] = G[j][k + i];
        }
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
    vector<string> S = {"11101", "10110", "01011", "11010"};
    int n = S[0].size();

    vector<vector<int>> G = getGeneratorMatrix(S, n);
    vector<vector<int>> H = getParityCheckMatrix(G, n);

    cout << "G =" << endl;
    printMatrix(G);
    cout << "H =" << endl;
    printMatrix(H);

    return 0;
}
