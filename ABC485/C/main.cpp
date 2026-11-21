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
右から走るのと左から走るのをやればいい
二種類の色を持っておけば十分
*/



void solve() {
    ll N;
    cin >> N;
    vl C(N);
    cin >> C;
    vl ans(N, INF);
    pll c1 = {-1, -1}, c2 = {-1, -1}; // 色、インデックス

    rep(i, N) {
        ll e = C[i];
        if (c1.first == -1) {
            c1 = {e,i};
            continue;
        }
        if (c1.first == e) {
            c1.second = i;
            if (c2.first == -1) continue;
            ans[i] = i - c2.second;
            continue;
        }
        if (c2.first == -1) {
            c2 = {e, i};
            ans[i] = i - c1.second;
            continue;
        }
        if (c2.first == e) {
          c2.second = i;
          ans[i] = i - c1.second;
          continue;
        }
        ans[i] = i - max(c1.second, c2.second);
        if (c1.second > c2.second) {
            c2 = {e, i};
        } else {
            c1 = {e, i};
        }
    }
    c1 = {-1, -1}; c2 = {-1, -1};
    drep(i, N) {
        ll e = C[i];
        if (c1.first == -1) {
            c1 = {e,i};
            continue;
        }
        if (c1.first == e) {
            c1.second = i;
            if (c2.first == -1) continue;
            chmin(ans[i],c2.second - i);
            continue;
        }
        if (c2.first == -1) {
            c2 = {e, i};
            chmin(ans[i],c1.second - i);
            continue;
        }
        if (c2.first == e) {
          c2.second = i;
          chmin(ans[i], c1.second - i);
          continue;
        }
        chmin(ans[i],min(c1.second, c2.second) - i);
        if (c1.second < c2.second) {
            c2 = {e, i};
        } else {
            c1 = {e, i};
        }
    }



    rep(i, N) {
        cout << ans[i] << " ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    solve();


    return 0;
}
