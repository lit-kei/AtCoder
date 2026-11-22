#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
template<class T> using vc = vector<T>;
using ll = long long;
using pll = pair<ll,ll>;
using vl = vc<ll>;
template<class T> ll sz(const T& a) { return (ll)a.size(); }
template<class T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) is >> x;
    return is;
}
#define rep(i,n) for(ll i = 0; i < (n); i++)

void solve() {
    ll N;
    cin >> N;
    vl a(N);
    vc<pll> renketu; // AGC079_Aでもこんなのつくった。ただ、vlだとlastを復元できなかったので、pllにした。
    cin >> a;
    ll sum = 0;
    ll last = -1;
    rep(i, N) {
        if (sz(renketu) == 0 || last == -1 || last != a[i]) {
            renketu.push_back({1,a[i]});
            sum++;
            last = a[i];
        } else {
            renketu[sz(renketu)-1].first++;
            sum++;
            if (renketu[sz(renketu)-1].first == a[i]) { // a[i]>=2だからこっち側の分岐だけでいい
                sum -= a[i];
                renketu.pop_back();
                if (sum == 0) last = -1;
                else last = renketu[sz(renketu)-1].second;
            }
        }
        cout << sum << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
