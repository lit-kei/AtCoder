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
#define nall(a) (a).begin(),(a).end()

void solve() {
    ll N;
    cin >> N;
    vl A(N);
    cin >> A;
    ll Q;
    cin >> Q;
    vc<vl> S(N);
    rep(i, N) {
        S[A[i]-1].push_back(i);
    }
    rep(i, N) {
        sort(nall(S[i]));
    }
    rep(i, Q) {
        ll L, R, X;
        cin >> L >> R >> X;
        L--; R--; X--;
        cout << upper_bound(nall(S[X]), R) - lower_bound(nall(S[X]), L) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
