# AWC0205 C — 果樹園の収穫計画

- [問題文](https://atcoder.jp/contests/awc0205/tasks/awc0205_c)
- [AC提出](https://atcoder.jp/contests/awc0205/submissions/80951241)
- 結果: **AC、333点、6:13**
- [main.cpp](main.cpp): コンテスト時のACコード

## 解法
累積和 `rui[i+1] = rui[i] + A[i]` を事前計算する。各クエリで1-indexedの `l,r` を0-indexedに直し、範囲 `[l,r]` の収穫率の合計 `rui[r+1]-rui[l]` に時間 `t` を掛けて出力する。

## 計算量
- 時間: **O(N+Q)**
- 空間: **O(N)**
