#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

template<class T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define drep(i,n) for(ll i = (n)-1; i >= 0; i--)
#define nall(a) (a).begin(),(a).end()

void solve() {
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<pll> lunchBox(N);
    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        lunchBox[i] = {a, b};
    }
    sort(nall(lunchBox));
    vector<vector<ll>> dp(X+1, vector<ll>(Y+1, -1));
    dp[0][0] = 0;
    rep(k, N) {
        auto [a, b] = lunchBox[k];
        drep(i, X+1) {
            drep(j, Y+1) {
                if (dp[i][j] == -1) continue;
                if (dp[min(i + a, X)][min(j + b, Y)] == -1) {
                    dp[min(i + a, X)][min(j + b, Y)] = dp[i][j] + 1;
                } else {
                    chmin(dp[min(i + a, X)][min(j + b, Y)], dp[i][j] + 1);
                }
            }
        }
    }
    cout << dp[X][Y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
