#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>

//#include <atcoder/modint>
//using namespace atcoder;

//using mint = modint998244353;
//using mint = modint1000000007;

using namespace std;
template<class T> using vc = vector<T>;
template<class T> using pq = priority_queue<T, vc<T>>;
template<class T> using pq_g = priority_queue<T, vc<T>, greater<T>>;
using ll = long long;
using pll = pair<ll, ll>;
using vl = vc<ll>; using vs = vc<string>;
template<class T>
ll sz(const T& a) {
    return (ll)a.size();
}
// 入力
template<class T, class U>
istream& operator>>(istream& is, pair<T, U>& p) {
    is >> p.first >> p.second;
    return is;
}
template<class T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) is >> x;
    return is;
}

template<class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

#define rep(i,n) for(ll i = 0; i < (n); i++)
#define drep(i,n) for(ll i = (n)-1; i >= 0; i--) // decrease
#define rrep(i,n) for(ll i = 1; i <= (n); i++)

#define nfor(i,s,t) for(ll i = s; i < (t); i++)
#define dfor(i,s,t) for(ll i = (s)-1; i >= (t); i--)

#define nall(a) (a).begin(),(a).end() // normal all
#define rall(a) (a).rbegin(),(a).rend() // reverse all

#define YES cout<<"Yes\n"
#define NO cout<<"No\n"
#define YN { cout << "Yes\n"; } else { cout << "No\n"; }
#define dame cout<<-1<<"\n"

//#define vc_unique(v) v.erase( unique(v.begin(), v.end()), v.end() ) // ソートしてから
//#define vc_rotate(v) rotate(v.begin(), v.begin()+1, v.end()) // 空じゃないとき

#define vc_cout(v){ll n = sz(v);rep(i,n)cout<<v[i]<<"\n";} // 一次元配列
#define vv_cout(v) { rep(i, sz(v)) { rep(j, sz(v[i])) { cout << v[i][j] << ' '; } cout << '\n'; } } // 二次元配列

constexpr ll INF = 2'000'000'000'000'000'000LL;
//constexpr ll dx[] = { 1,0,-1,0 };
constexpr ll dx[] = { 1,1,0,-1,-1,-1,0,1 };
//constexpr ll dy[] = { 0,1,0,-1 };
constexpr ll dy[] = { 0,1,1,1,0,-1,-1,-1 };

bool out_grid(ll i, ll j, ll h, ll w) { // true なら continue
    return (!(0 <= i && i < h && 0 <= j && j < w));
}

ll nc2(ll x) { return x * (x - 1) / 2; }

/*
重みが大きい辺から見ていけば、順に確定していける！！？
辺を主人公に
9AC 9WA
なんで？？？？
絶対あってるし、
*/

void solve() {
    ll N, M;
    cin >> N >> M;
    vc<pll> edgeToV(M); //辺iがつなぐ頂点番号（first < second）
    vc<pll> edges(M); //(辺iの重み、辺iのインデックス)ソート用
    rep(i, M) {
        ll u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        edgeToV[i] = {u, v};
        edges[i] = {c, i};

    }
    sort(rall(edges));
    vl dp(N, 0); // 各頂点を出発したときの最大値（随時更新）
    set<pll> diff; // dp の差分 (インデックス、重さ)
    ll last = -1; // 最後の重み

    rep(i, M) {
        auto [c, index] = edges[i];
        if (last != c) {
            for (auto [I, C]: diff) {
                chmax(dp[I], C);
            }
            diff.clear();
        }
        auto [u, v] = edgeToV[index];
        diff.insert({u, dp[v] + c});
        diff.insert({v, dp[u] + c});
        last = c;
    }

    for (auto [I, C]: diff) {
        chmax(dp[I], C);
    }
    ll ans = 0;
    rep(i, N) {
        chmax(ans, dp[i]);
        //cout << mx[i] << "\n";
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T;
    cin >> T;
    rep(i,T) { 
        //cout << i << "\n";
        solve(); 
    }

    return 0;
}