#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
template<class T> using vc = vector<T>;
#define YES cout<<"Yes\n"
#define NO cout<<"No\n"
#define YN { cout << "Yes\n"; } else { cout << "No\n"; }

void solve() {
    vc<char> S(3), T(3);
    for (auto &c : S) cin >> c;
    for (auto &c : T) cin >> c;
    if (S[0] == T[0]) {
        if (S[1] == T[1]) YN;
    } else if (S[0] == T[1]) {
        if (S[1] != T[0]) YN;
    } else {
        if (S[2] != T[0]) YN;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
