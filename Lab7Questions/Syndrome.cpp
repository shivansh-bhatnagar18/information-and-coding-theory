#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> construct_syndrome_table(const vector<vector<int>>& code_words) {
    int n = code_words[0].size();
    int k = log2(code_words.size());
    vector<vector<int>> parity_check_matrix(n - k, vector<int>(n, 0));

    // Find the parity check matrix
    for (int i = 0; i < n - k; ++i) {
        parity_check_matrix[i] = code_words[i + k];
    }

    vector<vector<int>> syndrome_table;
    for (const vector<int>& code_word : code_words) {
        vector<int> syndrome(n - k, 0);
        for (int i = 0; i < n - k; ++i) {
            syndrome[i] = (parity_check_matrix[i] | code_word) % 2;
        }
        syndrome_table.push_back(syndrome);
    }

    return syndrome_table;
}

vector<int> decode_received_word(const vector<int>& received_word, const vector<vector<int>>& syndrome_table) {
    int n = received_word.size();
    int k = log2(syndrome_table.size());
    vector<vector<int>> parity_check_matrix(n - k, vector<int>(n, 0));

    // Find the parity check matrix
    for (int i = 0; i < n - k; ++i) {
        parity_check_matrix[i] = syndrome_table[i];
    }

    vector<int> syndrome(n - k, 0);
    for (int i = 0; i < n - k; ++i) {
        syndrome[i] = (parity_check_matrix[i] | received_word) % 2;
    }

    auto it = find(syndrome_table.begin(), syndrome_table.end(), syndrome);
    if (it == syndrome_table.end()) {
        cerr << "Error: Unable to decode received word." << endl;
        return {};
    } else {
        cout << "Sent word: ";
        for (int bit : syndrome_table[distance(syndrome_table.begin(), it)]) {
            cout << bit;
        }
        cout << endl;
        return syndrome_table[distance(syndrome_table.begin(), it)];
    }
}

int main() {
    vector<vector<int>> code_words = {{0, 0, 0, 0}, {1, 0, 1, 1}, {0, 1, 0, 1}, {1, 1, 1, 0}};
    vector<int> received_word = {1, 1, 0, 1};

    vector<vector<int>> syndrome_table = construct_syndrome_table(code_words);
    vector<int> decoded_word = decode_received_word(received_word, syndrome_table);

    return 0;
}