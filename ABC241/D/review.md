# ABC241 D — Sequence Query

- 問題: https://atcoder.jp/contests/abc241/tasks/abc241_d
- 結果: **AC**（本人確認。初回に7 TLE・9 WA、その後修正）
- コード: [main.cpp](main.cpp)
- 手法: `multiset` と `lower_bound` / `upper_bound`、双方向イテレータ

## 解法

クエリ1は `multiset` に x を挿入する。
クエリ2（x 以下の数のうち大きい方から k 番目）は `upper_bound(x)` の直前に移動し、さらに k-1 回 `prev` する。先頭を越えるなら -1。
クエリ3（x 以上の数のうち小さい方から k 番目）は `lower_bound(x)` から k-1 回 `next` する。末尾を越えるなら -1。
重複があるため `set` ではなく `multiset` を使う。

## WA/TLE の原因と修正

初回のクエリ3実装では、`lower_bound(x)` が `A.end()` を返しても、その状態で `next(it)` を実行する可能性があった。これは未定義動作となり WA/TLE などの原因になる。
最終ACコードは `if (it == A.end()) break;` を **進める前** に置いて修正した。

## 計算量

`multiset` の挿入や bound は O(log Q)、`prev` / `next` の1回の移動は O(1)。
この問題では k<=5 なので、1クエリ O(log Q)、全体 O(Q log Q)。空間 O(Q)。

## 二重ループ脱出の疑問

クエリ2で `begin()` に達したとき、本当はそのまま外側のクエリ処理ループの次の周回に飛びたかったが、
内側のループから直接 `continue` できないため本人は `frag` フラグを使った。これは正しい書き方。

C++ にはラベル付き continue がなく、`break`/`continue` は最も内側のループに作用する。
この場合、失敗時に `it=A.end()` とすることでフラグをなくせる。あるいは判定処理を関数やラムダ式に分け、`return -1LL;` で処理を終了する方法もある。
`goto` も可能だが通常は上記の構造化した方法を選ぶ。

## 振り返り

データ構造の選択と計算量の見積もりは自力で正しい。最終修正は対話ヒントによって境界チェックの位置を直してAC。
`multiset::end()` を超えてイテレータを動かすのは未定義動作。境界を跨ぐ前に判定する。
