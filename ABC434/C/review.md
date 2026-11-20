# ABC434 C — Flapping Takahashi

- [問題文（ABC434 C）](https://atcoder.jp/contests/abc434/tasks/abc434_c)
- [ADTでの問題](https://atcoder.jp/contests/adt_all_20261120_2/tasks/abc434_c)
- [AC提出](https://atcoder.jp/contests/adt_all_20261120_2/submissions/80949879)
- 結果: **AC、300点、25:43、WAなし**
- コード: [main.cpp](main.cpp)

## 解法

各時刻までに到達できる高度の集合を区間 `[low, high]` で管理する。最初は `[H, H]`。

時刻差が `d = t-T` のとき、高度を上下に最大 `d` 変えられるので、到達可能な範囲は `[low-d, high+d]` に広がる。時刻 `t` に必要な高度制約 `[l,u]` との共通部分を取り、

`low[i+1] = max(l, low[i]-d)`

`high[i+1] = min(u, high[i]+d)`

として更新する。共通部分が空なら、そのテストケースは不可能（`No`）。最後まで可能なら `Yes`。

## 計算量

各テストケースで時間 **O(N)**、空間 **O(N)**（区間の端点を配列で保持）。現在の区間のみを保持すれば追加空間 **O(1)** にできるが、ACコードは配列を利用した実装。
