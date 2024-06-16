#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store packet information
struct Packet {
    int cost;
    int numOreos;
    int index; // To store the original index of the packet
};

// Comparator function to sort packets by cost
bool comparePackets(const Packet& p1, const Packet& p2) {
    return p1.cost < p2.cost;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<Packet> packets(n);
        for (int i = 0; i < n; ++i) {
            cin >> packets[i].cost >> packets[i].numOreos;
            packets[i].index = i + 1; // Store original index (1-based)
        }

        // Sort packets by cost (ascending)
        sort(packets.begin(), packets.end(), comparePackets);

        int totalOreos = 0;
        int spentMoney = 0;

        // Iterate through sorted packets and buy as many Oreos as possible
        for (int i = 0; i < n; ++i) {
            if (spentMoney + packets[i].cost <= k) {
                spentMoney += packets[i].cost;
                totalOreos += packets[i].numOreos;
            } else {
                break; // Stop if we can't afford the next packet
            }
        }

        // Output the maximum possible Oreos
        cout << totalOreos << endl;
    }

    return 0;
}
