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
一次元DPでダメな理由
・dp[i]を町iにたどり着くために必要な価格とすると、最小価格ではたどり着けない町が出てきたとき、あとから復元できない。
普通の二次元DPじゃダメな理由
・ガソリンタンクの容量が大きすぎて（10^9）、管理しきれない。

貪欲法で解決！
単調スタックを用いた実装
スタックにはインデックスを入れる。
*/



void solve() {
    ll N, T;
    cin >> N >> T;
    vl C(N), D(N-1), rui(N, 0);
    cin >> C >> D;
    rep(i, N-1) {
        if (D[i] > T) {
            cout << -1 << "\n";
            return;
        }
    }
    rep(i, N-1) {
        rui[i+1] = rui[i] + D[i];
    }
    vector<ll> st;
    vl tyukei(N);
    drep(i, N) {
        while (!st.empty() && C[st.back()] >= C[i]) {
            st.pop_back();
        }
        if (st.empty()) {
            tyukei[i] = -1;
        } else if (rui[st.back()] - rui[i] > T) {
            tyukei[i] = -1;
        } else {
            tyukei[i] = st.back();
        }
        st.push_back(i);
    }
    ll ans = 0;
    ll tank = 0;

    rep(i, N-1) {
        ll target;

        if (tyukei[i] == -1) {
            target = min(T, rui[N-1] - rui[i]);
        } else {
            target = rui[tyukei[i]] - rui[i];
        }

        ll need = max(0LL, target - tank);

        ans += need * C[i];
        tank += need;

        // 次の町に移動
        tank -= D[i];
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    solve();


    return 0;
}
