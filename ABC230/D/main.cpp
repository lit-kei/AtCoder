#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

template<class T> using vc = vector<T>;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define nall(a) (a).begin(),(a).end()

/*
DPでこんな問題を見た覚えがある。
xはR_iでいい
貪欲法で解ける
*/

void solve() {
    ll N, D;
    cin >> N >> D;
    vc<pll> R(N);
    set<pll> L;
    rep(i, N) {
        ll l, r;
        cin >> l >> r;
        R[i] = {r, i};
        L.insert({l, i});
    }
    sort(nall(R));
    vc<bool> destroyed(N, false);
    ll ans = 0;
    rep(i, N) {
        auto [r, index] = R[i];
        if (destroyed[index]) continue;
        ll punch = r + D - 1;
        // l <= punchなる壁を破壊
        auto it = L.begin();
        while (L.size() != 0) {
            auto [l, j] = *it;
            if (l <= punch) {
                destroyed[j] = true;
                it = L.erase(it);
            } else {
                break;
            }
        }
        ans++;
        destroyed[index] = true;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
