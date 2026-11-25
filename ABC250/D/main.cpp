#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
template<class T> using vc = vector<T>;
using ll = long long;
using vl = vc<ll>;
#define nfor(i,s,t) for(ll i = s; i < (t); i++)

void solve() {
    ll N;
    cin >> N;
    ll mx = cbrt(N);
    vl prime(mx+1, 0);
    vc<bool> furui(mx+1, true);
    ll ans = 0;
    nfor(i, 2, mx + 1) {
        prime[i] = prime[i-1];
        if (furui[i] == false) continue;
        prime[i]++;
        for(ll j = i*2; j <= mx; j += i) {
            furui[j] = false;
        }
        ll p = min(i - 1, N / (i * i * i));
        ans += prime[p];
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
