#include <bits/stdc++.h>

using namespace std;

// Function to process queries and compute the sum of elements after K operations
vector<long long> Que(int p, int q, vector<int>& arr, vector<int>& queries) {
    // Vector to store the results of each query
    vector<long long> results(q);

    // Iterate over each query
    for (int idx = 0; idx < q; ++idx) {
        int k = queries[idx];  // Get the value of K for the current query
        multiset<int> ms(arr.begin(), arr.end());  // Initialize multiset with array elements

        // Perform K operations as specified in the problem
        for (int i = 0; i < k; ++i) {
            if (ms.size() < 2) break;  // If there are fewer than 2 elements, break the loop

            auto it_min = ms.begin();  // Iterator to the smallest element
            auto it_max = prev(ms.end());  // Iterator to the largest element

            int min_val = *it_min;  // Get the smallest element
            int max_val = *it_max;  // Get the largest element

            ms.erase(it_min);  // Remove the smallest element
            ms.erase(it_max);  // Remove the largest element

            ms.insert(max_val - min_val);  // Insert the difference back into the multiset
        }

        // Calculate the sum of all elements in the multiset after K operations
        long long sum = 0;
        for (int val : ms) {
            sum += val;
        }

        // Store the result for the current query
        results[idx] = sum;
    }
    return results;
}

int main() {
    int p, q;
    cin >> p >> q;  // Read the number of elements and the number of queries

    vector<int> arr(p);  // Vector to store the elements of the array
    for (int i = 0; i < p; ++i) {
        cin >> arr[i];  // Read the elements of the array
    }

    vector<int> queries(q);  // Vector to store the queries
    for (int m = 0; m < q; ++m) {
        cin >> queries[m];  // Read the queries
    }

    // Get the results of the queries by calling the function
    vector<long long> results = Que(p, q, arr, queries);

    // Output the results for each query
    for (long long result : results) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}
