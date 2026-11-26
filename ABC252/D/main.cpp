#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
template<class T> using vc = vector<T>;
using ll = long long;
using vl = vc<ll>;
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define nfor(i,s,t) for(ll i = (s); i < (t); i++)

#define MAX 200000

void solve() {
    ll N;
    cin >> N;
    vl freq(MAX, 0);
    rep(i, N) {
        ll e;
        cin >> e;
        e--;
        freq[e]++;
    }
    ll sum = freq[0]+freq[1], pattern = freq[0] * freq[1]; // patternは第i項までで2種類選ぶ組合せ
    ll ans = 0;
    nfor(i, 2, MAX) {
        ll e = freq[i];
        ans += pattern * e;
        pattern += sum * e;
        sum += e;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
