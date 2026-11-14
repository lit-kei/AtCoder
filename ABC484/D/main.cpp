#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
//#include <atcoder/modint>

using namespace std;
//using namespace atcoder;

//using mint = modint998244353;

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
C問題と似てる
個数だけでいいのがポイント。
A[i+1] == A[i]みたいな箇所が連続していれば、そこのカウントだけ考えればよい。
ans=1で初期化し、前にしか挿入できないと考えてよい。
nC2+1通りから、いくつかぶりがあるかを前から見ていく。
eを追加するとき、これまでのeの出現回数を引けばよい。

サンプルが通らない。

適当に作った1 2 2 2 2で計算が合わない。
同じ数が連続するとき、それを先頭に入れることを考える必要がある。
同じ数が連続したらans--とか？
今まさに自分自身が連続している区間に入っているときの計算方法に間違いがありそう
1 2 2 3 3でも合わない。
*/

void solve() {
    ll N;
    cin >> N;
    vl A(N);
    cin >> A;
    vl cnt(N, 0); // cnt[i] = i - 1の出現回数
    ll ans = nc2(N) + 1;
    ll row = 1; //連続メーター。これまでに何連続同じ値か
    rep(i, N) {
        ll e = A[i];
        e--;
        ans -= cnt[e];
        cnt[e]++;
        if (i >= 1 && A[i] == A[i-1]) {
            row++;
            ans += cnt[e] - 1;
            ans -= i;
        } else {
            row = 1;
        }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    solve();


    return 0;
}