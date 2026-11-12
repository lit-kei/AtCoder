#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> using vc = vector<T>;
template<class T> using pq_g = priority_queue<T, vc<T>, greater<T>>;
using vl = vc<ll>;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

// AC confirmed by the author.
void solve() {
    ll N, M;
    cin >> N >> M;
    vc<set<ll>> edge(N); // edge[v]: prerequisite vertices for v
    vc<vl> E(N);         // E[u]: vertices reached by u
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        edge[b].insert(a);
        E[a].push_back(b);
    }

    pq_g<ll> S;
    rep(i, N) {
        if (edge[i].empty()) S.push(i);
    }

    vl output;
    while (!S.empty()) {
        ll e = S.top();
        S.pop();
        output.push_back(e + 1);

        for (auto i : E[e]) {
            // push only when a prerequisite was actually removed
            // and the prerequisite set has just become empty
            if (edge[i].erase(e) && edge[i].empty()) {
                S.push(i);
            }
        }
    }

    if ((ll)output.size() != N) {
        cout << -1 << "\n";
        return;
    }
    rep(i, N) cout << output[i] << (i + 1 == N ? '\n' : ' ');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
