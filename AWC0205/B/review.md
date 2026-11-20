# AWC0205 B — 変わらなかった時間

- [問題文](https://atcoder.jp/contests/awc0205/tasks/awc0205_b)
- [AC提出](https://atcoder.jp/contests/awc0205/submissions/80951121)
- 結果: **AC、233点、3:20**
- [main.cpp](main.cpp): コンテスト時のACコード

## 解法
文字列を左から順に見て、直前の文字と等しいときだけカウンタを増やす。先頭文字を `last` に保持し、各文字との比較後に更新する。

## 計算量
- 時間: **O(N)**
- 追加空間: **O(1)**（入力文字列そのものは O(N)）
