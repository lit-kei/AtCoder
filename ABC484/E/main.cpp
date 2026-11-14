#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

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

#define vc_unique(v) v.erase( unique(v.begin(), v.end()), v.end() ) // ソートしてから
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
A_iは非負でないので、尺取りは無理
工夫しないとO(N^4)とか？累積和をとればO(N^2)だが間に合わない
iからjまでのA[k]の総和はruiseki[j+1]-ruiseki[i]で、これがL以上R以下になるには、L+ruiseki[i]<=ruiseki[j+1]<=R+ruiseki[i]
次のような問題に置き換えれる？
前から順番に見ていく。このクエリを考える。
クエリ j (jは0からN-1まで連番)
e = ruiseki[j]とする。
1. {L+ruiseki[j], 1}, {R+ruiseki[j], -1}をデータに追加
2. L+ruiseki[i]<=ruiseki[j+1]<=R+ruiseki[i] であるようなj以下の整数iの個数を数える。
二分探索とざっひょう圧縮で実装。配列の最大の大きさは約2N
pos[k]<=x<pos[k+1]ならval[k]を参照
遅延セグメント木の方がいい？
L+min(ruiseki[i]) ~ R+max(ruiseki[i])で、最悪2*10^18程度
座標圧縮セグ木に載せればいい
実装力がない
*/

vl ruiseki;
ll mn = 0, mx = 0;

ll op(ll a, ll b) {
    return a + b;
}

ll e() {
    return 0;
}

void solve() {
    ll N, L, R;
    cin >> N >> L >> R;
    vl A(N);
    cin >> A;
    ruiseki.assign(N+1, 0);
    
    
    rep(i, N) {
        ruiseki[i+1] = ruiseki[i] + A[i];
        chmin(mn, ruiseki[i+1]);
        chmax(mx, ruiseki[i+1]);
    }
    // \sum_l^r{A_i}=ruiseki[r+1]-ruiseki[l]
    ll ans = 0;
    
    vl q = ruiseki;
    sort(nall(q));
    vc_unique(q);

    segtree<ll, op, e> seg(sz(q));

    rep(j, N) {
        ll p = lower_bound(nall(q), ruiseki[j]) - q.begin();
        seg.set(p, seg.get(p) + 1);

        ll left = lower_bound(nall(q), ruiseki[j+1] - R) - q.begin();
        ll right = upper_bound(nall(q), ruiseki[j+1] - L) - q.begin();
        
        ans += seg.prod(left, right);
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