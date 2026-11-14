
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int N, M;
vector<pair<ll, ll>> intervals;
bool canPlace(ll d) {
    ll cows = 0;
    ll last = -1;
    for (auto [l, r] : intervals) {
        ll pos = max(l, last + d);

        while (pos <= r) {
            cows++;
            last = pos;

            if (cows >= N)
                return true;

            pos += d;
        }
    }
    return false;
}
int main() {

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        intervals.push_back({a, b});
    }
    sort(intervals.begin(), intervals.end());

    ll low = 1;
    ll high = 1e18;
    ll ans = 1;

    while (low <= high) {
        ll mid = low + (high - low) / 2;

        if (canPlace(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
