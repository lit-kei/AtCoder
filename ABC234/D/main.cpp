#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
template<class T> using vc = vector<T>;
template<class T> using pq_g = priority_queue<T, vc<T>, greater<T>>;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); i++)

void solve() {
    ll N, K;
    cin >> N >> K;
    ll mx = 0;
    pq_g<ll> q;

    rep(i, N) {
        ll e;
        cin >> e;
        q.push(e);
        if (q.size() > K) {
            q.pop();
        }
        if (i >= K - 1) cout << q.top() << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
