#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll nc2(ll x) { return x * (x - 1) / 2; }

ll N;

ll calc(ll n) {
    return (nc2(N/n + 1) * n);
}

void solve() {
    ll A, B;
    cin >> N >> A >> B;
    ll L = lcm(A, B); // llの範囲を超えない
    cout << nc2(N+1) - (calc(A) + calc(B) - calc(L));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
