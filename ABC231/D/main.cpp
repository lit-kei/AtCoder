#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
template<class T> using vc = vector<T>;
using ll = long long;
using vl = vector<ll>;
template<class T> ll sz(const T& a) { return (ll)a.size(); }
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define NO cout << "No\n"
#define YES cout << "Yes\n"

/*
つながりをグラフとしてみたとき、次数が3以上の頂点があればNO
サイクルがあってもNO。ただし、自己辺や多重辺が存在しないことが保証されている
それ以外ではYES
*/
ll N;
vc<vl> graph;
vc<bool> visited;

bool dfs(ll v, ll p) {
    visited[v] = true;
    rep(i, sz(graph[v])) {
        if (graph[v][i] == p) continue;
        if (visited[graph[v][i]]) {
            return true;
        }
        if (dfs(graph[v][i], v)) {
            return true;
        }
    }
    return false;
}

void solve() {
    ll M;
    cin >> N >> M;
    graph.resize(N);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    rep(i, N) {
        if (sz(graph[i]) > 2) {
            NO;
            return;
        }
    }
    visited.assign(N, false);
    rep(i, N) {
        if (visited[i]) continue;
        if (dfs(i, -1)) {
            NO;
            return;
        }
    }
    YES;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
