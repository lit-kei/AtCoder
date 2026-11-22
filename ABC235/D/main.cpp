#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define dame cout << -1 << "\n"

ll help(ll n) {
    ll cnt = 0;
    while (n > 0) {
        n /= 10;
        cnt++;
    }
    return cnt;
}

void solve() {
    ll a, N;
    cin >> a >> N;
    ll d = help(N);
    ll mx = pow(10, d) - 1;
    vl dest(mx + 1, -1);
    dest[1] = 0;
    queue<ll> q;
    q.push(1);

    auto push = [&](ll e, ll n) mutable {
        if (dest[n] == -1) {
            dest[n] = dest[e] + 1;
            q.push(n);
        }
    };

    while (!q.empty()) {
        ll e = q.front();
        q.pop();
        if (e == N) {
            cout << dest[N];
            return;
        }
        if (e >= 10 && e % 10 != 0) {
            ll r = e % 10;
            ll n = help(e);
            ll newE = e / 10;
            newE += r * pow(10, n-1);
            push(e, newE);
        }
        if (mx >= e * a) push(e, e * a);
    }
    dame;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
