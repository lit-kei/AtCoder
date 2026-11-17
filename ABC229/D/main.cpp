#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
template<class T> using vc = vector<T>;
template<class T>
ll sz(const T& a) {
    return (ll)a.size();
}
template<class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
#define rep(i,n) for(ll i = 0; i < (n); i++)

void solve() {
    string S;
    ll K;
    cin >> S >> K;
    ll N = sz(S);

    ll ans = 0;
    ll r = 0;
    ll cnt = 0;

    rep(l, N) {
        while (r < N) {
            if (S[r] == '.' && cnt == K) break;

            if (S[r] == '.') cnt++;
            r++;
        }

        chmax(ans, r - l);

        if (l < r && S[l] == '.') cnt--;
        if (l == r) r++;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
