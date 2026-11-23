#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define dame cout<<-1<<"\n"

void solve() {
    ll Q;
    cin >> Q;
    multiset<ll> A;
    ll szA = 0;
    rep(i, Q) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll x;
            cin >> x;
            A.insert(x);
            szA++;
        } else if (type == 2) {
            ll x, k;
            cin >> x >> k;
            auto it = A.upper_bound(x);
            if (it != A.begin()) {
                it = prev(it);
            } else {
                dame;
                continue;
            }
            bool frag = false;
            rep(j, k-1) {
                if (it == A.begin()) {
                    frag = true;
                    break;
                }
                it = prev(it);
            }
            if (frag == false) {
                cout << *it << "\n";
            } else {
                dame;
            }
        } else {
            ll x, k;
            cin >> x >> k;
            auto it = A.lower_bound(x);
            rep(j, k-1) {
                if (it == A.end()) break;
                it = next(it);
            }
            if (it != A.end()) {
                cout << *it << "\n";
            } else {
                dame;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
