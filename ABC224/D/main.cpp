#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using pll = pair<ll, ll>;
template<class T> using vc = vector<T>;
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define drep(i,n) for(ll i = (n)-1; i >= 0; i--)
#define nfor(i,s,t) for(ll i = (s); i < (t); i++)
#define nall(a) (a).begin(),(a).end()

/*
コマが置かれている状態は9!通りしかないので全探索が通じる。BFSで良さげ。
同じ盤面に遭遇したら、あとから同じ盤面になるのは遅いので探索をやめていい。
階乗進法で全ての盤面を9!通りで区別できる。
*/

vl fact(10, 1);

ll calcIndex(vl& board) {
    ll index = 0;
    vl diff(9);
    iota(nall(diff), 0);
    rep(i, 9) {
        ll e = board[i];
        index += fact[8-i] * diff[e];
        nfor(j, e+1, 9) {
            diff[j]--;
        }
    }
    return index;
}

ll getBoard(vl& board, ll index) {
    ll c = -1;
    vl remaining(9);
    iota(nall(remaining), 0);
    drep(i, 9) {
        ll e = index / fact[i];
        ll v = remaining[e];
        board[8-i] = v;
        if (v == 8) c = 8-i;
        index %= fact[i];
        remaining.erase(remaining.begin() + e);
    }
    return c;
}

void solve() {
    nfor(i, 1, 10) fact[i] = i * fact[i-1];
    ll M;
    vc<vl> edge(9);
    cin >> M;
    rep(i, M) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    vl board(9, 8);
    rep(i, 8) {
        ll p;
        cin >> p;
        p--;
        board[p] = i;
    }
    queue<pll> q;
    vc<bool> visited(fact[9], false);
    ll index = calcIndex(board);
    if (index == 0) {
        cout << 0;
        return;
    }
    q.push({index, 0});
    visited[index] = true;
    while(!q.empty()) {
        auto [e, x] = q.front();
        q.pop();
        vl b(9);
        ll c = getBoard(b, e);
        for(auto i : edge[c]) {
            swap(b[i], b[c]);
            ll t = calcIndex(b);
            if (!visited[t]) {
                visited[t] = true;
                if (t == 0) {
                    cout << x + 1;
                    return;
                }
                q.push({t, x + 1});
            }
            swap(b[i], b[c]);
        }
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
