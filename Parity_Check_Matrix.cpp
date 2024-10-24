#include <bits/stdc++.h>

using namespace std;

bool isParityCheckMatrix(const vector<vector<int>>& H, const vector<vector<int>>& C) {
    int rows = H.size();
    int cols = H[0].size();
    
    for (const auto& codeword : C) {
        vector<int> syndrome(rows, 0);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                syndrome[i] ^= (codeword[j] * H[i][j]);
            }
        }
        for (int i = 0; i < rows; ++i) {
            if (syndrome[i] != 0) return false;
        }
    }
    return true;
}

int main() {
    vector<vector<int>> C = {
        {0, 0, 0, 0}, 
        {1, 1, 1, 0}, 
        {1, 0, 1, 1}, 
        {0, 1, 0, 1}
    };

    vector<vector<int>> H = {
        {1, 1, 0, 1}, 
        {0, 1, 1, 1}
    };

    if (isParityCheckMatrix(H, C)) {
        cout << "H is a valid parity check matrix for C." << endl;
    } else {
        cout << "H is not a valid parity check matrix for C." << endl;
    }

    return 0;
}
