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
Sの[0,k]にABCが含まれるようなkであって最小のものをk_0、
Sの[k,N)にABCが含まれるようなkであって最大のものをk_1とする。
k_0<=i(<j), k_1>jが必須。
iを固定してjの場所を二分探索

12
AABCCABCCBCA

*/
ll N;
string S;
ll A = 0, B = 0, C = 0;
vl ruiA,ruiB,ruiC;
ll k0 = -1, k1 = -1;
bool check(ll i, ll n) {
    return (ruiA[n+1] - ruiA[i+1] > 0 && A - ruiA[n+1] &&
            ruiB[n+1] - ruiB[i+1] > 0 && B - ruiB[n+1] &&
            ruiC[n+1] - ruiC[i+1] > 0 && C - ruiC[n+1]);
}
ll small(ll i) {
    ll ok = k1;
    ll ng = i;
    while (ng + 1 != ok) {
        ll h = (ok + ng)/2;
        if (check(i, h)) {
            ok = h;
        } else {
            ng = h;
        }
    }
    return ok;
}

void solve() {
    cin >> N >> S;
    ruiA.assign(N+1, 0);ruiB.assign(N+1, 0);ruiC.assign(N+1, 0);
    
    rep(i, N) {
        A += (S[i] == 'A');
        B += (S[i] == 'B');
        C += (S[i] == 'C');
        ruiA[i+1] = A;
        ruiB[i+1] = B;
        ruiC[i+1] = C;
        if (k0 == -1 && A > 0 && B > 0 && C > 0) k0 = i; 
    }
    if (k0 == -1) {
        cout << 0;
        return;
    }
    drep(i, N) {
        if (k1 == -1 && A - ruiA[i] > 0 && B - ruiB[i] > 0 && C - ruiC[i] > 0) {
            k1 = i - 1;
        }
    }
    if (k1 - k0 <= 2) {
        cout << 0;
        return;
    }
    //cout << k0 << " " << k1 << "\n";
    ll cnt = 0;
    nfor(i, k0, k1) {
        if (ruiA[k1+1] - ruiA[i+1] < 1 || ruiB[k1+1] - ruiB[i+1] < 1 || ruiC[k1+1] - ruiC[i+1] < 1) {
            break;
        }
        // i < j < N-1, ruiX[j] - ruiX[i+1] > 0, X - ruiX[j] 最大=k1　最小を求める。
        ll sj = small(i);
        //cout << i << " " << sj << "\n";
        cnt += (k1 - sj + 1); 
    }
    cout << cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    solve();


    return 0;
}
