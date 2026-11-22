#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
template<class T> using vc = vector<T>;
using ll = long long;
using vl = vc<ll>;
#define nfor(i,s,t) for(ll i = (s); i < (t); i++)

void solve() {
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    ll mx = B + D;
    vc<bool> furui(mx+1, true);
    vl prime;
    nfor(i, 2, mx+1) {
        if (furui[i] == false) continue;
        prime.push_back(i);
        nfor(j, 2, (mx+i)/i) {
            furui[j*i] = false;
        }
    }
    //きれいに書く方法が思いつかないから全探索でいいや
    //すべて10^2以下だから高々10^4。難しい実装より、間に合うなら簡単な実装の方がいい
    bool takahashi = false;
    nfor(i, A, B + 1) {
        bool aoki = false;
        nfor(j, C, D+1) {
            if (furui[i+j]) {
                aoki = true;
                break;
            }
        }
        if (aoki == false) {
            takahashi = true;
            break;
        }
    }
    if (takahashi) {
        cout << "Takahashi";
    } else {
        cout << "Aoki";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
