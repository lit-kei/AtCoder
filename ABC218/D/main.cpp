#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

void solve() {
    ll N;
    cin >> N;
    set<pll> S;
    vector<pll> P(N);
    for (ll i = 0; i < N; ++i) {
        ll x, y;
        cin >> x >> y;
        P[i] = {x, y};
        S.insert({x, y});
    }

    ll cnt = 0;
    for (ll i = 0; i < N - 1; ++i) {
        auto [x1, y1] = P[i];
        for (ll j = i + 1; j < N; ++j) {
            auto [x2, y2] = P[j];
            if (x1 == x2 || y1 == y2) continue;
            if (S.contains({x1, y2}) && S.contains({x2, y1})) {
                cnt++;
            }
        }
    }
    cout << cnt / 2; // Each rectangle has two diagonals.
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
