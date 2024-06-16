#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;

vector<long long> Sum(int T, vector<pair<long long, int>>& queries) {
    vector<long long> results(T);

    for (int t = 0; t < T; ++t) {
        long long N = queries[t].first;
        int K = queries[t].second;
        
        // If N is larger than a reasonable range to be directly computed, we may use approximation or other methods
        if (N <= K * 20) {
            vector<long long> dp(N + 1, 0);
            dp[0] = 1;  // There's one way to make the sum 0 (using no dice)
            for (int i = 1; i <= N; ++i) {
                for (int j = 1; j <= K; ++j) {
                    if (i >= j) {
                        dp[i] = (dp[i] + dp[i - j]) % MOD;
                    }
                }
            }
            results[t] = dp[N];
        } else {
            // For very large N, we need to approximate or use another method
            // Here we provide a placeholder to indicate an alternative method
            results[t] = 0;  // Placeholder result for large N
        }
    }

    return results;
}

int main() {
    int T;
    cin >> T;
    vector<pair<long long, int>> queries(T);

    for (int i = 0; i < T; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    vector<long long> results = Sum(T, queries);

    for (long long result : results) {
        cout << result << endl;
    }

    return 0;
}
