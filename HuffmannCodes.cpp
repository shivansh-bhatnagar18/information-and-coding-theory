#include <bits/stdc++.h>

using namespace std;

struct HuffmanNode {
    char data;
    float freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, float freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

struct Compare {
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return left->freq > right->freq;
    }
};

void printHuffmanCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;
    if (!root->left && !root->right) {
        huffmanCodes[root->data] = code;
    }
    printHuffmanCodes(root->left, code + "0", huffmanCodes);
    printHuffmanCodes(root->right, code + "1", huffmanCodes);
}

void generateHuffmanCodes(unordered_map<char, float>& freqMap) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;

    for (auto& entry : freqMap) {
        minHeap.push(new HuffmanNode(entry.first, entry.second));
    }

    while (minHeap.size() != 1) {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();
        HuffmanNode* right = minHeap.top();
        minHeap.pop();
        HuffmanNode* sum = new HuffmanNode('$', left->freq + right->freq);
        sum->left = left;
        sum->right = right;
        minHeap.push(sum);
    }

    HuffmanNode* root = minHeap.top();
    unordered_map<char, string> huffmanCodes;
    printHuffmanCodes(root, "", huffmanCodes);

    for (auto& entry : huffmanCodes) {
        cout << entry.first << ": " << entry.second << endl;
    }
}

int main() {
    unordered_map<char, float> freqMap1 = { {'A', 12}, {'B', 5} };
    generateHuffmanCodes(freqMap1);

    cout << endl;

    unordered_map<char, float> freqMap2 = { {'S1', 0.3}, {'S2', 0.2}, {'S3', 0.2}, {'S4', 0.2}, {'S5', 0.1} };
    generateHuffmanCodes(freqMap2);

    return 0;
}
