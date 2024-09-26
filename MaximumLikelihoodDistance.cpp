#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double calculateLikelihood(string codeword, string receivedWord, double p) {
    double likelihood = 1.0;
    for (int i = 0; i < codeword.size(); i++) {
        if (codeword[i] == receivedWord[i]) {
            likelihood *= (1 - p);
        } else {
            likelihood *= p;
        }
    }
    return likelihood;
}

string maximumLikelihoodDecoding(const vector<string>& codewords, string receivedWord, double p) {
    string mostLikelyCodeword = codewords[0];
    double maxLikelihood = calculateLikelihood(codewords[0], receivedWord, p);

    for (int i = 1; i < codewords.size(); i++) {
        double likelihood = calculateLikelihood(codewords[i], receivedWord, p);
        if (likelihood > maxLikelihood) {
            maxLikelihood = likelihood;
            mostLikelyCodeword = codewords[i];
        }
    }

    return mostLikelyCodeword;
}

int main() {
    vector<string> S = {"000", "111"};
    string c = "110";
    double p = 0.05;

    string result = maximumLikelihoodDecoding(S, c, p);
    cout << "Most likely codeword: " << result << endl;

    p = 0.95;
    result = maximumLikelihoodDecoding(S, c, p);
    cout << "Most likely codeword: " << result << endl;

    return 0;
}
