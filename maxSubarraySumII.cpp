#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b;
  cin >> n >> a >> b;

    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        long long x;
        cin >> x;
        prefix[i] = prefix[i - 1] + x;
    }

    deque<int> dq;
    long long max_sum = -4e18;

    for (int i = a; i <= n; ++i) {
        while (!dq.empty() && prefix[dq.back()] >= prefix[i - a]) {
            dq.pop_back();
        }
        dq.push_back(i - a);

        while (!dq.empty() && dq.front() < i - b) {
            dq.pop_front();
        }

        max_sum = max(max_sum, prefix[i] - prefix[dq.front()]);
    }

    cout << max_sum << "\n";

    return 0;
}
