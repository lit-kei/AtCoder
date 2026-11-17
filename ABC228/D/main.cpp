#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); i++)

void solve() {
    ll N = (1 << 20);
    ll Q;
    cin >> Q;
    set<ll> unused;
    vector<ll> array(N, -1);
    rep(i, N) {
        unused.insert(i);
    }
    rep(i, Q) {
        ll type, x;
        cin >> type >> x;
        if (type == 1) {
            ll h = x % N;
            auto it = unused.lower_bound(h);
            ll t;
            if (it == unused.end()) {
                t = *unused.begin();
                unused.erase(unused.begin());
            } else {
                t = *it;
                unused.erase(it);
            }
            array[t] = x;
        } else {
            cout << array[x % N] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
