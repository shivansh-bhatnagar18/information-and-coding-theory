#include <bits/stdc++.h>

using namespace std;

void generateCodewords(vector<vector<int>>& G) {
    int k = G.size();
    int n = G[0].size();
    for (int i = 0; i < (1 << k); ++i) {
        vector<int> codeword(n, 0);
        for (int j = 0; j < k; ++j) {
            if (i & (1 << j)) {
                for (int l = 0; l < n; ++l) {
                    codeword[l] ^= G[j][l];
                }
            }
        }
        for (int bit : codeword) {
            cout << bit << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> G = {
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 1}
    };
    generateCodewords(G);
    return 0;
}
