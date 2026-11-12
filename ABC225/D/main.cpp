#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define nall(a) (a).begin(),(a).end()

void solve() {
    ll N, Q;
    cin >> N >> Q;
    vl top(N), back(N); // 存在しないなら自分自身
    iota(nall(top), 0);
    iota(nall(back), 0);
    rep(i, Q) {
        ll q;
        cin >> q;
        if (q == 1) {
            ll x, y;
            cin >> x >> y;
            x--; y--;
            back[x] = y;
            top[y] = x;
        } else if (q == 2) {
            ll x, y;
            cin >> x >> y;
            x--; y--;
            back[x] = x;
            top[y] = y;
        } else {
            ll x;
            cin >> x;
            x--;
            ll p = x;
            while (back[p] != p) {
                p = back[p];
            }
            ll cnt = 1;
            while (top[p] != p) {
                p = top[p];
                cnt++;
            }
            cout << cnt;
            while (back[p] != p) {
                cout << " " << p + 1;
                p = back[p];
            }
            cout << " " << p + 1;
            cout << "\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
