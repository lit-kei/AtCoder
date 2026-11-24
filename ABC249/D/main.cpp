#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
#define rep(i,n) for(ll i = 0; i < (n); i++)

/*
*/
void solve() {
    ll N;
    cin >> N;

    const ll M = 200000;
    vl cnt(M + 1, 0);

    rep(i, N) {
        ll a;
        cin >> a;
        cnt[a]++;
    }

    ll ans = 0;

    for (ll x = 1; x <= M; x++) {
        for (ll y = 1; x * y <= M; y++) {
            ans += cnt[x] * cnt[y] * cnt[x * y];
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
