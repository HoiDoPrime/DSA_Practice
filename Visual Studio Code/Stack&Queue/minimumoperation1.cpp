#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem of transforming s into e using -1 and *2 operations
int solve(int s, int e) {
    if (s >= e) return s - e; // If s >= e, only -1 operations are needed

    queue<pair<int, int>> q; // Queue to perform BFS
    q.push({s, 0}); // Push the starting point with step count 0
    set<int> se; // Set to keep track of visited nodes
    se.insert(s); // Insert the starting point into the set

    while (!q.empty()) {
        pair<int, int> x = q.front(); q.pop(); // Get the front element of the queue

        if (x.first == e) {
            return x.second; // Return the number of steps if target is reached
        }

        // Perform -1 operation
        if (x.first > 1 && se.count(x.first - 1) == 0) {
            q.push({x.first - 1, x.second + 1});
            se.insert(x.first - 1);
        }

        // Perform *2 operation
        if (x.first < e && se.count(x.first * 2) == 0) {
            q.push({x.first * 2, x.second + 1});
            se.insert(x.first * 2);
        }
    }

    return -1; // If no solution is found
}

int main() {
    int t; cin >> t; // Number of test cases
    while (t--) {
        int x, y; cin >> x >> y; // Read input values
        cout << solve(x, y) << endl; // Print the result for each test case
    }
    return 0;
}
