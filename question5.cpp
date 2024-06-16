#include <bits/stdc++.h>
using namespace std;

// Function to calculate the sum of digits in a string
int digitSum(const string& s) {
    int sum = 0;
    for (char c : s) {
        sum += c - '0';
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<string> strings(n);
    for (int i = 0; i < n; ++i) {
        cin >> strings[i];
    }

    // Hash map to store counts of strings by length and digit sum
    unordered_map<int, unordered_map<int, int>> hashMap;

    // Populate the hash map with the counts of digit sums for each length
    for (const string& s : strings) {
        int len = s.size();
        int sum = digitSum(s);
        hashMap[len][sum]++;
    }

    int result = 0;

    // Iterate through each string and find valid pairs
    for (const string& s : strings) {
        int len1 = s.size();
        int sum1 = digitSum(s);
        hashMap[len1][sum1]--;  // Temporarily remove current string to avoid pairing with itself

        // Find the required complementary length and digit sum
        int len2 = 12 - len1;
        int sum2 = 50 - sum1;

        // Check if the complementary length and digit sum exists in the hash map
        if (hashMap.count(len2) && hashMap[len2].count(sum2)) {
            result += hashMap[len2][sum2];
        }

        hashMap[len1][sum1]++;  // Reinsert the current string
    }

    cout << result << endl;

    return 0;
}
