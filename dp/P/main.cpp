#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;

using ll = long long;
using mint = modint1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> tree(N);
    for (int i = 0; i < N - 1; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    // DFSで親を子より先に記録し、逆順にDPを計算する。
    stack<pair<int, int>> st;
    vector<vector<int>> child(N);
    vector<int> order;
    st.push({-1, 0});

    while (!st.empty()) {
        auto [p, v] = st.top();
        st.pop();
        order.push_back(v);
        for (int x : tree[v]) {
            if (x == p) continue;
            child[v].push_back(x);
            st.push({v, x});
        }
    }

    vector<mint> dpB(N, 1), dpW(N, 1);
    for (int i = N - 1; i >= 0; --i) {
        int v = order[i];
        for (int x : child[v]) {
            dpB[v] *= dpW[x];
            dpW[v] *= dpW[x] + dpB[x];
        }
    }

    cout << (dpB[0] + dpW[0]).val() << '\n';
}
