#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nfor(i,s,t) for(ll i = (s); i < (t); i++)

void solve() {
    cout << "300\n";
    for (ll d: {1LL, 100LL, 10000LL}) {
        nfor(i, 1, 101) {
            cout << d * i << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
