#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> ll sz(const T& a) { return (ll)a.size(); }
#define rep(i,n) for(ll i = 0; i < (n); i++)

/*
|S^i|=2|S^{i-1}|
2^{t_i}で割ればもともと何番目だったかわかる？
2進数が大事？
*/

char help(ll n) {
    return (((n % 3) + 3) % 3) + 'A';
}

void solve() {
    string S;
    cin >> S;
    ll N = sz(S);
    ll Q;
    cin >> Q;
    rep(i, Q) {
        ll t, k;
        cin >> t >> k;
        k--;
        ll index;
        ll d = 0, n = 1;
        rep(i, t) { // 実際は高々i=60程度で止まる
            d++;
            n *= 2;
            if (k < n) {
                break;
            }
        }
        if (k < n) {
            index = 0;
        } else {
            index = k / n;
        }

        ll cnt = 0;
        ll tmp = t;
        while (tmp > 0 && k > 0) {
            cnt += (k % 2);
            k /= 2;
            tmp--;
        }

        cout << help((S[index] - 'A') + cnt + t) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
