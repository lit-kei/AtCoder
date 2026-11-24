#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
template<class T> using vc = vector<T>;
using ll = long long;
using vl = vc<ll>;
template<class T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) is >> x;
    return is;
}
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define drep(i,n) for(ll i = (n)-1; i >= 0; i--)

void solve() {
    ll N, M;
    cin >> N >> M;
    vl A(N+1), C(N+M+1);
    cin >> A >> C;
    vl B(M+1);
    drep(i, M+1) {
        ll q = C[i+N] / A[N];
        B[i] = q;
        rep(j, N+1) {
            C[i+j] -= q * A[j];
        }
    }
    rep(i, M+1) {
        cout << B[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
