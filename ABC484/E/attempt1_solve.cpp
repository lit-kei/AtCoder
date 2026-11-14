// 未完成の第1案。提出コードから solve() と関連するグローバル変数を抜粋。
// 共通テンプレートは ABC484/D/main.cpp に記録済み。
vl pos = {-INF, INF}, val = {0};

void solve() {
    ll N, L, R;
    cin >> N >> L >> R;
    vl A(N);
    cin >> A;
    vl ruiseki(N+1, 0);
    rep(i, N) {
        ruiseki[i+1] = ruiseki[i] + A[i];
    }
    // \sum_l^r{A_i}=ruiseki[r+1]-ruiseki[l]
    ll ans = 0;

    rep(j, N) {
        ll e = ruiseki[j];
        ll l = L + ruiseki[j], r = R + ruiseki[j];

    }
}
