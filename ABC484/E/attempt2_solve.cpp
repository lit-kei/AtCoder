// 未完成の第2案。提出コードから solve()、getIndex()、関連するグローバル変数を抜粋。
// 共通テンプレートは ABC484/D/main.cpp に記録済み。
// 注: getIndex の while 条件は未修正のまま保存。
vl ruiseki;
ll mn = 0, mx = 0;

ll getIndex(ll n, vl& a) {
    ll ok = 0, ng = sz(a)+1;
    while(ok + ng != 1) {
        ll h = (ok+ng)/2;
        if (a[h] <= n) {
            ok = h;
        } else {
            ng = h;
        }
    }
    return ok;
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

    vl q = {mn, mx+1};
    rep(j, N) {
        ll l = L + ruiseki[j], r = R + ruiseki[j] + 1;
        q.push_back(l);
        q.push_back(r);
    }
    sort(nall(q));
    vc_unique(q);
    ll s = sz(q);

    rep(j, N) {
        ll l = L + ruiseki[j], r = R + ruiseki[j] + 1;
        ll iL = getIndex(l, q), iR = getIndex(r, q);
    }
}
