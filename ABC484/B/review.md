# ABC484 B — 振り返り

- コンテスト: [AtCoder Beginner Contest 484](https://atcoder.jp/contests/abc484)
- 問題: [B](https://atcoder.jp/contests/abc484/tasks/abc484_b)
- 提出: [AC (80815081)](https://atcoder.jp/contests/abc484/submissions/80815081)
- 配点: 200点
- AC時刻: 2:47（Aから1:49）

## 解法・実装

`K` 個の整数を1つずつ読み、最小値 `mn` と値 `9` が含まれるかを同時に管理する。
最初に `mn=9`、`finish=true` とし、各入力値 `e` に対して `chmin(mn,e)`、`e==9` なら `finish=false` とする。
最後に `finish` が真なら `-1`、偽なら `mn` を出力する。

## 計算量

- 時間計算量: `O(K)`
- 追加の空間計算量: `O(1)`

## レビュー

- 入力を配列に保持せず、1回の走査で必要な情報を更新している。
- `chmin` の利用が簡潔。
- `finish` は「9が存在しない」を意味するので、`has9` などの名前のほうが意図が伝わりやすい。
- `mn=9` という初期値の適切さは問題の値域に依存する。

## 振り返り

本人の追加コメントがあれば更新する。
