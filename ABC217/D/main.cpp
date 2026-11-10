// ABC217 D - Cutting Woods
// AC reported by the author. Unused personal template declarations omitted.
// NOTE: The final subtraction expression below has undefined behavior
// due to unsequenced modification and access of 'it'.
// A safe rewrite is shown in review.md.
#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll L, Q;
    cin >> L >> Q;
    set<ll> cut = {0, L};
    for (ll i = 0; i < Q; i++) {
        ll c, x;
        cin >> c >> x;
        if (c == 1) {
            cut.insert(x);
        } else {
            auto it = cut.upper_bound(x);
            cout << *it - *(--it) << "\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
