#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

template<class T> using vc = vector<T>;
using ll = long long;
using pll = pair<ll,ll>;
#define rep(i,n) for(ll i = 0; i < (n); i++)
template<class T> bool chmax(T& a, const T& b) {
    if (a < b) { a = b; return true; }
    return false;
}

/*
H,Wが小さすぎるのでBFSでOK
*/

void solve() {
    ll H, W;
    cin >> H >> W;
    vc<string> board(H);
    rep(i, H) cin >> board[i];

    queue<pll> q;
    q.push({0, 0});
    vc<vc<bool>> visited(H, vc<bool>(W, false));
    visited[0][0] = true;
    ll ans = 1;
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        if (i != H - 1) {
            if (board[i+1][j] == '.' && visited[i+1][j] == false) {
                visited[i+1][j] = true;
                q.push({i+1, j});
                chmax(ans, i + 1 + j + 1);
            }
        }
        if (j != W - 1) {
            if (board[i][j+1] == '.' && visited[i][j+1] == false) {
                visited[i][j+1] = true;
                q.push({i, j+1});
                chmax(ans, i + j + 1 + 1);
            }
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
