#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); i++)

/*
普通に実装したら終わるけど、途中でオーバーフローするかも？
頂点1から右か左かを保持しておけば10^6+60くらいの情報で持てる。
*/

void solve() {
    ll N, X;
    string S;
    cin >> N >> X >> S;
    deque<bool> path; // falseなら左、trueなら右。二進数と一致する。
    while (X > 1) {
        path.push_front(X % 2);
        X /= 2;
    }

    rep(i, N) {
        if (S[i] == 'U') {
            path.pop_back();
        } else if (S[i] == 'L') {
            path.push_back(false);
        } else {
            path.push_back(true);
        }
    }
    //復元
    ll ans = 1;
    while(!path.empty()) {
        ans = (ans << 1) + path.front();
        path.pop_front();
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
