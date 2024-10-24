#include <iostream>
#include <vector>

using namespace std;

int totalHammingDistance(const vector<int>& arr) {
    int totalDistance = 0;
    int n = arr.size();

    for (int bit = 0; bit < 32; bit++) {
        int countOnes = 0;

        for (int num : arr) {
            if (num & (1 << bit)) {
                countOnes++;
            }
        }

        int countZeros = n - countOnes;
        totalDistance += countOnes * countZeros;
    }

    return totalDistance;
}

int main() {
    vector<int> arr = {1, 3, 5};
    cout << "Total Hamming Distance: " << totalHammingDistance(arr) << endl;
    return 0;
}
