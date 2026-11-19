#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
#define rep(i,n) for(ll i = 0; i < (n); i++)
template<class T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) is >> x;
    return is;
}

/*
尺取！
って思ったけどAは非負とは書かれていない。
じゃあ累積和を取る手法で、例えばrui[i]=sum_{k=0}^{i-1} A[k]とすれば、
rui[l]について、K+rui[l]=rui[r]があればよい。
*/

void solve() {
    ll N, K;
    cin >> N >> K;
    vl A(N);
    cin >> A;
    vl rui(N+1, 0);
    rep(i, N) {
        rui[i+1] = rui[i] + A[i];
    }
    map<ll, ll> x;
    ll ans = 0;
    rep(i, N+1) {
        if (x[rui[i]] != 0) {
            ans += x[rui[i]];
        }
        x[K + rui[i]]++;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
