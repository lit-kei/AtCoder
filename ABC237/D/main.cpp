#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define nfor(i,s,t) for(ll i = (s); i < (t); i++)

void solve() {
    ll N;
    string S;
    cin >> N >> S;
    vl left(N+1, -1), right(N+1, -1);
    nfor(i, 1, N+1) {
        if (S[i-1] == 'L') {
            left[i] = left[i-1];
            right[i] = i - 1;
            left[i-1] = i;
            if (left[i] != -1) right[left[i]] = i;
        } else {
            right[i] = right[i-1];
            left[i] = i - 1;
            right[i-1] = i;
            if (right[i] != -1) left[right[i]] = i;
        }
    }
    rep(i, N + 1) {
        if (left[i] == -1) {
            ll p = i;
            cout << p << " ";
            while (right[p] != -1) {
                p = right[p];
                cout << p << " ";
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
