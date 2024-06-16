#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int findShortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    deque<pair<long long, int>> dq;
    long long currentSum = 0;
    int minLength = n + 1;  // Initialize with a value larger than any possible subarray length

    for (int i = 0; i < n; ++i) {
        currentSum += nums[i];

        if (currentSum >= k) {
            minLength = min(minLength, i + 1);
        }

        while (!dq.empty() && currentSum - dq.front().first >= k) {
            minLength = min(minLength, i - dq.front().second);
            dq.pop_front();
        }

        while (!dq.empty() && currentSum <= dq.back().first) {
            dq.pop_back();
        }

        dq.emplace_back(currentSum, i);
    }

    return (minLength == n + 1) ? -1 : minLength;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = findShortestSubarray(nums, k);
    cout << result << endl;

    return 0;
}
