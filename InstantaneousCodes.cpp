#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

bool isPrefix(const string &a, const string &b) {
    return a.size() <= b.size() && b.substr(0, a.size()) == a;
}

bool areCodesInstantaneous(unordered_map<char, string> &codes) {
    vector<string> codeList;
    for (const auto &entry : codes) {
        codeList.push_back(entry.second);
    }

    for (int i = 0; i < codeList.size(); ++i) {
        for (int j = 0; j < codeList.size(); ++j) {
            if (i != j && isPrefix(codeList[i], codeList[j])) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    unordered_map<char, string> codes1 = { {'A', "1"}, {'B', "0"} };
    if (areCodesInstantaneous(codes1)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    unordered_map<char, string> codes2 = { {'A', "1"}, {'B', "11"} };
    if (areCodesInstantaneous(codes2)) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}
