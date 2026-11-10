#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/modint>

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
#define drep(i,n) for(ll i = (n)-1; i >= 0; i--)
#define rrep(i,n) for(ll i = 1; i <= (n); i++)
#define nfor(i,s,t) for(ll i = (s); i < (t); i++)
#define dfor(i,s,t) for(ll i = (s)-1; i >= (t); i--)
#define nall(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define YES cout<<"Yes\n"
#define NO cout<<"No\n"
#define YN { cout << "Yes\n"; } else { cout << "No\n"; }
#define dame cout<<-1<<"\n"
#define vc_cout(v){ll n = sz(v);rep(i,n)cout<<v[i]<<"\n";}
#define vv_cout(v) { rep(i, sz(v)) { rep(j, sz(v[i])) { cout << v[i][j] << ' '; } cout << '\n'; } }
#define prime 998244353
constexpr ll INF = 2'000'000'000'000'000'000LL;
constexpr ll dx[] = { 1,1,0,-1,-1,-1,0,1 };
constexpr ll dy[] = { 0,1,1,1,0,-1,-1,-1 };
bool out_grid(ll i, ll j, ll h, ll w) {
    return (!(0 <= i && i < h && 0 <= j && j < w));
}
ll nc2(ll x) { return x * (x - 1) / 2; }

using namespace atcoder;
using mint = modint998244353;

void solve() {
    ll N;
    cin >> N;
    vl DAG(N, 0);
    nfor(i, 1, N) {
        ll v;
        cin >> v;
        v--;
        DAG[i] = v+1;
    }

    vc<mint> frac(N+1, 1);
    nfor(i, 1, N+1) {
        frac[i] = frac[i-1] * i;
    }

    vc<mint> renketsu;
    vl indexes;

    nfor(i, 1, N) {
        ll e = DAG[i];
        if (i == e) {
            renketsu.push_back(1);
            indexes.push_back(i);
        } else {
            ll index = upper_bound(nall(indexes), e) - 1 - indexes.begin();
            mint tmp = 1;
            ll s = sz(indexes);
            nfor(j, index, s) {
                tmp *= renketsu[j];
                tmp /= ((j == s - 1) ? frac[i - indexes[j]] : frac[indexes[j+1] - indexes[j]]);
            }
            tmp *= frac[i-indexes[index]];
            indexes.erase(indexes.begin()+index+1, indexes.end());
            renketsu.erase(renketsu.begin()+index, renketsu.end());
            renketsu.push_back(tmp);
        }
    }
    mint ans = 1;
    ll s = sz(indexes);
    rep(i, s) {
        ans *= renketsu[i];
        ans /= (i == s - 1 ? frac[N - indexes[i]] : frac[indexes[i+1] - indexes[i]]);
    }
    nfor(i, 1, N) {
        ans *= i;
    }
    cout << ans.val() << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T;
    cin >> T;
    rep(i, T) {
        solve();
    }
    return 0;
}
