#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> using vc = vector<T>;
template<class T> using pq_g = priority_queue<T, vc<T>, greater<T>>;
#define rep(i,n) for(ll i = 0; i < (n); i++)

void solve() {
    ll Q;
    cin >> Q;
    pq_g<ll> bag;
    ll add = 0; // 全要素への加算を遅延する
    rep(i, Q) {
        ll X;
        cin >> X;
        if (X == 1) {
            ll e;
            cin >> e;
            e -= add;
            bag.push(e);
        } else if (X == 2) {
            ll e;
            cin >> e;
            add += e;
        } else {
            ll e = bag.top();
            bag.pop();
            cout << e + add << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
