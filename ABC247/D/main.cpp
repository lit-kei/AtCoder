#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i,n) for(ll i = 0; i < (n); i++)

void solve() {
    ll Q;
    cin >> Q;
    queue<pll> q;
    rep(i, Q) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll x, c;
            cin >> x >> c;
            q.push({c, x});
        } else {
            ll c;
            cin >> c;
            ll sum = 0;
            while (c > 0) {
                if (c >= q.front().first) {
                    sum += q.front().first * q.front().second;
                    c -= q.front().first;
                    q.pop();
                } else {
                    sum += c * q.front().second;
                    q.front().first -= c;
                    c = 0;
                }
            }
            cout << sum << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
