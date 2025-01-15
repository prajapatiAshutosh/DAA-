#include <iostream>
#include <vector>
using namespace std;

int linearSearch(const vector<int>& arr, int key) {
    int comparisons = 0;
    for (int i = 0; i < arr.size(); i++) {
        comparisons++;
        if (arr[i] == key) {
            return comparisons;
        }
    }
    return comparisons;
}

int main() {
    cout << "n    BestCase    WorstCase    AverageCase\n";

    for (int n = 10; n <= 100; n += 5) {
        vector<int> arr;
        for (int i = 1; i <= n; i++) {
            arr.push_back(i);
        }

        vector<int> keys;
        for (int i = 1; i <= n; i++) {
            keys.push_back(i);
        }
        keys.push_back(n + 1);

        int bestCase = linearSearch(arr, keys[0]);
        int worstCase = linearSearch(arr, keys[keys.size() - 2]);
        int totalComparisons = 0;
        for (int key : keys) {
            totalComparisons += linearSearch(arr, key);
        }
        double averageCase = static_cast<double>(totalComparisons) / keys.size();

        cout << n << "    " << bestCase << "    " << worstCase << "    " << averageCase << "\n";
    }

    return 0;
}
