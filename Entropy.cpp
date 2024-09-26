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

unordered_map<char, string> generateHuffmanCodes(unordered_map<char, float>& freqMap) {
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

    return huffmanCodes;
}

float calculateHuffmanEntropy(unordered_map<char, float>& freqMap, unordered_map<char, string>& huffmanCodes) {
    float entropy = 0;
    float totalFreq = 0;
    for (auto& entry : freqMap) {
        totalFreq += entry.second;
    }

    for (auto& entry : freqMap) {
        float probability = entry.second / totalFreq;
        entropy += probability * huffmanCodes[entry.first].length();
    }

    return entropy;
}

float calculateOptimalEntropy(unordered_map<char, float>& freqMap) {
    float entropy = 0;
    float totalFreq = 0;
    for (auto& entry : freqMap) {
        totalFreq += entry.second;
    }

    for (auto& entry : freqMap) {
        float probability = entry.second / totalFreq;
        if (probability > 0) {
            entropy -= probability * log2(probability);
        }
    }

    return entropy;
}

int main() {
    unordered_map<char, float> freqMap1 = { {'A', 12}, {'B', 5} };
    unordered_map<char, string> huffmanCodes1 = generateHuffmanCodes(freqMap1);

    float huffmanEntropy1 = calculateHuffmanEntropy(freqMap1, huffmanCodes1);
    float optimalEntropy1 = calculateOptimalEntropy(freqMap1);

    cout << "Entropy of Huffman code: " << huffmanEntropy1 << endl;
    cout << "Entropy of optimal structure: " << optimalEntropy1 << endl;

    cout << endl;

    unordered_map<char, float> freqMap2 = { {'S1', 0.3}, {'S2', 0.2}, {'S3', 0.2}, {'S4', 0.2}, {'S5', 0.1} };
    unordered_map<char, string> huffmanCodes2 = generateHuffmanCodes(freqMap2);

    float huffmanEntropy2 = calculateHuffmanEntropy(freqMap2, huffmanCodes2);
    float optimalEntropy2 = calculateOptimalEntropy(freqMap2);

    cout << "Entropy of Huffman code: " << huffmanEntropy2 << endl;
    cout << "Entropy of optimal structure: " << optimalEntropy2 << endl;

    return 0;
}
