# ABC214 C — Distribution

- [元問題（ABC214 C）](https://atcoder.jp/contests/abc214/tasks/abc214_c)
- [ADTでの問題](https://atcoder.jp/contests/adt_all_20261120_2/tasks/abc214_c)
- [AC提出](https://atcoder.jp/contests/adt_all_20261120_2/submissions/80950218)
- 結果: **AC、300点、53:37、WAなし**
- [main.cpp](main.cpp): 本人が共有した最終ACコード

## 解法

人 \(i\) が最初に宝石を受け取る時刻を \(dp[i]\) とする。自分への直接配布時刻は \(T[i]\)、直前の人から受け取れる時刻は \(dp[prev]+S[prev]\) なので、

`dp[now] = min(dp[prev] + S[prev], T[now])`

で更新できる。

人が環状に並んでいるため、添字を \(i\bmod N\) として走査を2周分行う。最初の周回で各人の直接配布時刻と前の人からの伝播を反映し、次の周回で開始位置をまたぐ伝播まで反映できる。

最終コードでは \(dp[0]=T[0]\) として、\(i=1,\ldots,2N-1\) を走査する。

## 計算量

- 時間: **O(N)**
- 空間: **O(N)**

## 補足

- ソース内コメント「18:45復帰」は本人の記録。大会記録によれば26:00〜45:00（約19分）の夕食休憩があったため、E→FのAC時刻差はそのまま解答に要した時間ではない。
