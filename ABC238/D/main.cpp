#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
using namespace std;
using ll = long long;
template<class T> using vc = vector<T>;
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define YES cout<<"Yes\n"
#define NO cout<<"No\n"
#define YN { cout << "Yes\n"; } else { cout << "No\n"; }

ll help(ll n) {
    ll d = 0;
    while (n > 0) {
        n /= 2;
        d++;
    }
    return d;
}

void solve() {
    ll T;
    cin >> T;
    rep(i, T) {
        ll a, s;
        cin >> a >> s;
        ll d = help(a);
        vc<bool> bit(d); // bit[d-1] = trueのはず
        rep(j, d) {
            bit[j] = ((a >> j) & 1);
        }
        ll rest = s - a - a; // and の非増加性により
        if (rest < 0) {
            NO;
            continue;
        }
        // restを二進数表記したときに立っているビットすべてで、bit配列がfalseならYES
        ll restD = help(rest);
        bool ok = true;
        rep(j, restD) {
            if (j >= d) break;
            if ((rest >> j) & 1 && bit[j]) {
                ok = false;
                break;
            }
        }
        if (ok) YN;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
