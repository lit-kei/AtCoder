#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
using namespace std;
using ll = long long;
using vl = vector<ll>;

template<class T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) is >> x;
    return is;
}
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define nfor(i,s,t) for(ll i = (s); i < (t); i++)

/*
%10は最後にやってもいい。
2^10000はどう考えても間に合わないので、いい方法がありそう。
1の位と、次の値がわかってさえいれば計算できる→DPでおけ
*/
void solve() {
    ll N;
    cin >> N;
    vl A(N);
    cin >> A;
    vector<mint> dp(10, 0);
    dp[A[0]]++; //初期条件
    vector<mint> add(10, 0);
    nfor(i, 1, N) {
        ll e = A[i];
        rep(j, 10) {
            add[(j + e) % 10] += dp[j];
            add[(j * e) % 10] += dp[j];
        }
        rep(j, 10) {
            dp[j] = add[j];
            add[j] = 0;
        }
    }
    rep(i, 10) {
        cout << dp[i].val() << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
