# ABC464 B — Crop

- [問題文](https://atcoder.jp/contests/abc464/tasks/abc464_b)
- [ADTのAC提出](https://atcoder.jp/contests/adt_all_20261120_2/submissions/80949704)
- 参加回: [ADT ALL 2026-11-20 18:00](../../ADT/2026-11-20_ALL_18/review.md)
- 結果: **AC、200点、11:50、WAなし**
- [main.cpp](main.cpp): 本人が再共有した最終ACコード。

## 解法

入力した `H × W` の盤面に対して、`#` が存在するセルの行・列を調べ、
- 最上行 `top`、最下行 `bottom`
- 最左列 `left`、最右列 `right`
を特定する。その長方形 `board[top..bottom][left..right]` を切り出して出力する。

## 計算量
- 時間: **O(HW)**
- 空間: **O(HW)**（盤面の保持）

## 記録
本人から受け取った最終ACコードを保存済み。
