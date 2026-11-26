#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
template<class T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) is >> x;
    return is;
}
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define nall(a) (a).begin(),(a).end()

void solve() {
    ll N, Q;
    cin >> N >> Q;
    vl A(N);
    cin >> A;
    sort(nall(A));
    vl rui(N+1, 0);
    rep(i, N) {
        rui[i+1] = rui[i] + A[i];
    }
    rep(i, Q) {
        ll e;
        cin >> e;
        ll n = lower_bound(nall(A), e) - A.begin(); //upper_boundにしても変わらない？ 尺取りの方が早い.. (でもまにあう)
        ll ans = rui[N] - rui[n] - (N-n)*e;
        ans += n*e - rui[n];
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
