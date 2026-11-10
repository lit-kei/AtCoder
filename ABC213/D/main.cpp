#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> using vc = vector<T>;
#define rep(i,n) for(ll i = 0; i < (n); i++)

ll N;
vc<set<ll>> tree;

void dfs(ll p, ll v) {
    cout << v + 1 << " ";
    for (auto x : tree[v]) {
        if (x == p) continue;
        dfs(v, x);
        cout << v + 1 << " ";
    }
}

void solve() {
    cin >> N;
    tree.resize(N);
    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        tree[a].insert(b);
        tree[b].insert(a);
    }
    dfs(-1, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
