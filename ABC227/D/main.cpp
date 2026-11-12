#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
#define rep(i,n) for(ll i = 0; i < (n); i++)

/*
min_i{A_i}以上(\sum_i{A_i}/K)以下
貪欲法が最適かどうかすらわからない。
→異なる部署からとらないといけないので、単純な貪欲じゃ無理
類題は知らない
N == Kは簡単。
そもそもA[i]<=10^12とかだし、シミュレーションではなさそう
A[i]がある程度大きいうちはどうやって選んでもよさそう
S=\sum_i{A_i}とする。どの部署も使った人間がx人以下で、S-(残っている人間の総和)=Kxであるとき、プロジェクト数がxであるような割り当て方が存在する。
*/
ll N, K;
vl A;

bool check(ll n) {
    ll s = 0;
    rep(i, N) {
        s += min(n, A[i]);
    }
    return s >= (K * n);
}

void solve() {
    cin >> N >> K;
    A.resize(N);
    ll s = 0;
    rep(i, N) {
        cin >> A[i];
        s += A[i];
    }
    ll ok = 0;
    ll ng = s / K + 1; // 必ず不可能な上界
    while(ok + 1 != ng) {
        ll h = (ok + ng) / 2;
        if (check(h)) {
            ok = h;
        } else {
            ng = h;
        }
    }
    cout << ok;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
