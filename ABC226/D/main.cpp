#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
template<class T> using vc = vector<T>;
#define rep(i,n) for(ll i = 0; i < (n); i++)

/*
魔法は互いの素な自然数m,nで(m,n)とすれば完全に識別できる。
※ 正確には、負数や0も含む整数の組で gcd(|m|,|n|)=1。
*/

void solve() {
    ll N;
    cin >> N;
    set<pll> S;
    vc<pll> city(N);
    rep(i, N) {
        ll x, y;
        cin >> x >> y;
        city[i] = {x, y};
    }
    rep(i, N) {
        auto [x1, y1] = city[i];
        rep(j, N) {
            if (i == j) continue;
            auto [x2, y2] = city[j];
            ll dx = x2 - x1, dy = y2 - y1;
            ll g = gcd(dx, dy);
            dx /= g;
            dy /= g;
            S.insert({dx, dy});
        }
    }
    cout << S.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
