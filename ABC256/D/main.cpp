#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
template<class T> using vc = vector<T>;
using ll = long long;
using pll = pair<ll, ll>;
template<class T, class U>
istream& operator>>(istream& is, pair<T, U>& p) {
    is >> p.first >> p.second;
    return is;
}
template<class T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) is >> x;
    return is;
}
template<class T>
bool chmax(T& a, const T& b) {
    if (a < b) { a = b; return true; }
    return false;
}
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define nall(a) (a).begin(),(a).end()

void solve() {
    ll N;
    cin >> N;
    vc<pll> range(N);
    cin >> range;
    sort(nall(range));
    ll lastStart = -1, end = -1;
    rep(i, N) {
        auto [L, R] = range[i];
        if (lastStart == -1) {
            lastStart = L;
            end = R;
        } else {
            if (L <= end) {
                chmax(end, R);
            } else {
                cout << lastStart << " " << end << "\n";
                lastStart = L;
                end = R;
            }
        }
    }
    cout << lastStart << " " << end << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
