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
２次元DPだと計算量はO(N^2)で間に合う。メモリはlong long を3000^2もつと72MBでたりるが、mintだと、、？
*/
void solve() {
    ll N;
    cin >> N;
    vl A(N), B(N);
    cin >> A >> B;
    vector<mint> dp(B[N-1] + 1, 0); // dp[k]: 最後に追加した値がkであるようなものの個数
    vector<mint> next(B[N-1] + 1, 0);

    nfor(i, A[0], B[0]+1) {
        dp[i] = 1;
    }

    nfor(i, 1, N) {
        ll a = A[i], b = B[i];
        mint ruiseki = 0;
        rep(j, b+1) {
            ruiseki += dp[j];
            if (a <= j) {
                next[j] = ruiseki;
            }
        }
        rep(j, b+1) {
            if (a <= j) {
                dp[j] = next[j];
            } else {
                dp[j] = 0;
            }
            next[j] = 0;
        }
    }

    mint ans = 0;
    rep(i, B[N-1]+1) {
        ans += dp[i];
    }
    cout << ans.val();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
