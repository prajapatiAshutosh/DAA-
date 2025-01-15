#include <iostream>
#include <vector>
#include <iomanip> // For formatting output
using namespace std;

// Function for Linear Search
int linearSearch(const vector<int>& arr, int key) {
    int comparisons = 0;
    for (int i = 0; i < arr.size(); i++) {
        comparisons++;
        if (arr[i] == key) {
            return comparisons; // Return number of comparisons for success
        }
    }
    return comparisons; // Return number of comparisons for failure
}

int main() {
    cout << setw(10) << "n" << setw(20) << "Best Case" 
         << setw(20) << "Worst Case" << setw(20) << "Average Case" << endl;

    // Loop through input sizes from 10 to 100 in steps of 5
    for (int n = 10; n <= 100; n += 5) {
        vector<int> arr;
        for (int i = 1; i <= n; i++) {
            arr.push_back(i); // Populate array with 1 to n
        }

        // Perform n+1 searches
        vector<int> keys; // Keys to search
        for (int i = 1; i <= n; i++) {
            keys.push_back(i); // Successful searches
        }
        keys.push_back(n + 1); // Unsuccessful search

        // Calculate comparisons
        int bestCase = linearSearch(arr, keys[0]);            // First key
        int worstCase = linearSearch(arr, keys[keys.size() - 2]); // Last key
        int totalComparisons = 0;
        for (int key : keys) {
            totalComparisons += linearSearch(arr, key);
        }
        double averageCase = static_cast<double>(totalComparisons) / keys.size();

        // Display results
        cout << setw(10) << n
             << setw(20) << bestCase
             << setw(20) << worstCase
             << setw(20) << fixed << setprecision(2) << averageCase << endl;
    }

    return 0;
}
