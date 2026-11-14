# ABC484 A — 振り返り

- コンテスト: [AtCoder Beginner Contest 484](https://atcoder.jp/contests/abc484)
- 問題: [A](https://atcoder.jp/contests/abc484/tasks/abc484_a)
- 提出: [AC (80810602)](https://atcoder.jp/contests/abc484/submissions/80810602)
- 配点: 100点
- AC時刻: 0:58

## 解法

入力を `N, M` として、`(30 - N) * (30 - M)` を出力する。
それぞれの候補数が `30-N`, `30-M` となり、組み合わせを独立に選べるので積の法則で求められる。

## 計算量

- 時間計算量: `O(1)`
- 空間計算量: `O(1)`

## コードレビュー

- 定数時間で直接求められており、無駄なループがない。
- `long long` を使用している。
- テンプレートが長いが、解法部分は簡潔。
- 開始から58秒でAC。

## 振り返り

考察過程については、本人からの追記を待つ。
