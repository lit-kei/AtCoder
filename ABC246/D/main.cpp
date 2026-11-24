#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
template<class T> using vc = vector<T>;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define nfor(i,s,t) for(ll i = (s); i < (t); i++)
template<class T>
bool chmin(T& a, const T& b) {
    if (a > b) { a = b; return true; }
    return false;
}
constexpr ll INF = 2'000'000'000'000'000'000LL;

void solve() {
    ll N;
    cin >> N;
    auto check = [&N](ll a, ll b) {
        return N <= ((a+b)*(a*a+b*b));
    };
    ll up = cbrt(N);
    if (check(up, 0)) {
        cout << N;
        return;
    }
    ll ans = INF;
    nfor(i, 0, up+1) {
        ll ng = 0, ok = up + 1;
        while (ng + 1 != ok) {
            ll h = (ok+ng)/2;
            if (check(i, h)) {
                ok = h;
            } else {
                ng = h;
            }
        }
        chmin(ans, (i+ok)*(i*i+ok*ok));
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
