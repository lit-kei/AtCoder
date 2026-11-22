#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
template<class T> using vc = vector<T>;
using ll = long long;
using vl = vc<ll>;
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define nfor(i,s,t) for(ll i = s; i < (t); i++)
template<class T>
bool chmax(T& a, const T& b) {
    if (a < b) { a = b; return true; }
    return false;
}

/*
N<=8より2N<=16。ペアを組ませる方法は15!!=2,027,025以下
全探索でいいがどうやって？
前から順に確定させる
再帰で実装
*/

ll N;
vc<vl> A;
ll ans = 0;

void saiki(ll d, vl& p) {
    if (d == N) {
        ll b = 0;
        rep(i, 2 * N) {
            if (i > p[i]) {
                b ^= A[p[i]][i - p[i] - 1];
            }
        }
        chmax(ans, b);
        return;
    }
    vl unused; // |unused| = 2*(N-d)
    rep(i, 2*N) {
        if (p[i] == -1) unused.push_back(i);
    }
    nfor(i, 1, 2*(N - d)) {
        p[unused[0]] = unused[i];
        p[unused[i]] = unused[0];
        saiki(d + 1, p);
        p[unused[0]] = -1;
        p[unused[i]] = -1;
    }
}

void solve() {
    cin >> N;
    A.resize(2*N-1);
    rep(i, 2*N-1) {
        A[i].resize(2*N-1-i);
        cin >> A[i];
    }
    vl p(2*N, -1);
    saiki(0, p);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
