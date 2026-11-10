#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ABC216 D - Pair of Balls
// 入力順が上からなので queue を使う。
void solve() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> indexes(N, {-1, -1});
    vector<queue<ll>> tubes(M);
    queue<ll> q;

    for (ll i = 0; i < M; i++) {
        ll k;
        cin >> k;
        for (ll j = 0; j < k; j++) {
            ll a;
            cin >> a;
            tubes[i].push(a - 1);
        }
        q.push(i);
    }

    ll cnt = 0;
    while (!q.empty()) {
        ll i = q.front();
        q.pop();
        if (tubes[i].empty()) continue;

        ll c = tubes[i].front();
        tubes[i].pop();

        if (indexes[c].first == -1) {
            // 1個目を仮にpopするが、ペアが揃うまで筒iを再投入しない
            indexes[c].first = i;
        } else {
            cnt++;
            q.push(indexes[c].first);
            q.push(i);
        }
    }

    cout << (cnt == N ? "Yes" : "No") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
