#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
template<class T> using vc = vector<T>;
using ll = long long;
#define nfor(i,s,t) for(ll i = (s); i < (t); i++)

/*
平方因子をのぞく！
*/

void solve() {
    ll N;
    cin >> N;
    vc<bool> visited(N+1, false);
    ll ans = 0;
    nfor(i, 1, N + 1) {
        if (visited[i]) continue;
        ll j = 2;
        while (i * j * j <= N) {
            visited[i*j*j] = true;
            j++;
        }
        // j-1 = cnt
        ans += (j-1)*(j-1);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
