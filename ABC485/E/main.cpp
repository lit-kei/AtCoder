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

#define prime 998244353



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
ゴールから逆算する
直前の道として許されない色を持つ

BFSでいけない？
まだ探索していない辺を持っておく。
3 5
1 2 1
1 2 1
1 2 2
1 2 2
1 2 3

*/


void solve() {
    ll N, M;
    cin >> N >> M;
    vc<vc<pll>> edge(N); // 行先、色
    vc<set<pll>> unsearched(N);
    rep(i, M) {
        ll u, v, c;
        cin >> u >> v >> c;
        u--; v--; c--;
        edge[u].push_back({v, c});
    }
    rep(i, N) {
        set<pll> s(nall(edge[i]));
        unsearched[i] = s;
    }
    queue<tuple<ll,ll,ll>> q; // 深さ、探索する頂点、直前の色
    q.push({0,0,-1});
    while(!q.empty()) {
        auto [d, v, c] = q.front();
        //cout << d << " " << v << " " << c << "\n";
        q.pop();
        if (v == N - 1) {
            cout << d;
            return;
        }
        auto it = unsearched[v].begin();
        while(it != unsearched[v].end()) {
            auto [x, nextC] = *it;
            if (nextC == c) {
                //cout << "a " << x << " " << nextC << "\n";
                it++;
                continue;
            } else {
                //cout << "b " << x << " " << nextC << "\n";
                it = unsearched[v].erase(it);
                q.push({d+1, x, nextC});
            }
        }
    } 
    cout << -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    solve();


    return 0;
}
