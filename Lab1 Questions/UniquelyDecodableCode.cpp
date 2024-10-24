#include <bits/stdc++.h>

using namespace std;

int numInterpretations(const string &s, unordered_map<char, string> &dictionary) {
    int n = s.length();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (const auto &entry : dictionary) {
            char charKey = entry.first;
            string code = entry.second;
            int length = code.length();
            if (i >= length && s.substr(i - length, length) == code) {
                dp[i] += dp[i - length];
            }
        }
    }

    return dp[n];
}

int main() {
    string s1 = "01";
    unordered_map<char, string> dictionary1 = { {'A', "1"}, {'B', "0"} };
    cout << numInterpretations(s1, dictionary1) << endl;

    string s2 = "11";
    unordered_map<char, string> dictionary2 = { {'A', "1"}, {'B', "11"} };
    cout << numInterpretations(s2, dictionary2) << endl;

    return 0;
}
