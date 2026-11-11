#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define nall(a) (a).begin(), (a).end()

/*
imos法と座標圧縮を組み合わせる
イベントソート？正式名称がわからない
O(N log N)になるはず
*/
void solve() {
    ll N;
    cin >> N;
    vector<pll> event;
    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        event.push_back({a, 1});
        event.push_back({a + b, -1}); //退出が入場よりも先
    }
    sort(nall(event));
    vl ans(N, 0);
    ll last = 1;
    ll cnt = 0;
    rep(i, 2*N) {
        auto [t, type] = event[i];
        if (t != last) {
            if (cnt != 0) {
                ans[cnt - 1] += t - last;
            }
        }
        cnt += type;
        last = t;
    }
    rep(i, N) cout << ans[i] << " ";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
