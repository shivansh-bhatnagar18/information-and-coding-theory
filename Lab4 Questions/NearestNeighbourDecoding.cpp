#include <iostream>
#include <vector>
#include <string>

using namespace std;

int hammingDistance(const string& a, const string& b) {
    int distance = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            distance++;
        }
    }
    return distance;
}

string nearestNeighborDecoding(const vector<string>& codewords, const string& receivedWord) {
    string mostLikelyCodeword = codewords[0];
    int minDistance = hammingDistance(receivedWord, codewords[0]);

    for (int i = 1; i < codewords.size(); i++) {
        int distance = hammingDistance(receivedWord, codewords[i]);
        if (distance < minDistance) {
            minDistance = distance;
            mostLikelyCodeword = codewords[i];
        }
    }

    return mostLikelyCodeword;
}

int main() {
    vector<string> S = {"000", "111"};
    string c = "110";

    string result = nearestNeighborDecoding(S, c);
    cout << "Most likely codeword: " << result << endl;

    return 0;
}

