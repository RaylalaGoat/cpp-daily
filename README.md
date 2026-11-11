# cpp-study

C++17 の学習記録。1日1テーマ、84日間。

ゲームプログラマーを目指して、文法だけでなく「なぜそうなるのか」と
「綺麗に書くにはどうするか」まで含めて記録していく。

## 環境

- C++17
- Visual Studio 2022 / MSVC（主）
- g++ 13（動作確認）
- Windows (x64)

実行結果は上記環境のもの。`long` と `long double` のサイズは処理系依存で、
同じコードでも MSVC と g++ で値が変わる。

## 構成

```
DayNN_テーマ名/main.cpp
```

各フォルダに、そのテーマを確認するための単独で動くプログラムが1本入っている。

## 進捗

| Day | テーマ | 学んだこと |
|:---:|---|---|
| 01 | 型とsizeof | 型のサイズは処理系依存（`long` は MSVC で4byte、Linux/g++ で8byte）。`sizeof` はコンパイル時に決まる演算子で実行コストは無い。符号なし整数のラップアラウンドは規格で定義された動作だが、符号付きオーバーフローは未定義動作。`float` は有効桁が約7桁で、524,288 を超えると `+0.016f` が丸めで消える |
| 02 | 整数の割り算とstatic_cast | |
| 03 | 関数と値渡し | |
| 04 | 配列とstd::array | |
| 05 | enum class | |
| 06 | struct | |
| 07 | 復習 | |

## カリキュラム

| 週 | 内容 |
|:---:|---|
| W1 | 基礎の確認 |
| W2 | 参照とポインタ |
| W3 | classの基本 |
| W4 | classの応用 |
| W5 | メモリ管理1（stack/heap, RAII, unique_ptr） |
| W6 | メモリ管理2（shared_ptr, ムーブ, Rule of 0/3/5） |
| W7 | オブジェクト指向（継承, virtual, 抽象クラス） |
| W8 | STL1（vector, string, map） |
| W9 | STL2（set, queue, stack, sort） |
| W10 | Modern C++（ラムダ, optional, function） |
| W11 | テンプレート |
| W12 | 発展（例外, スレッド, 分割コンパイル） |

## ビルド方法

Visual Studio（MSVC）:

```
cl /std:c++17 /W4 /EHsc main.cpp
main.exe
```

g++（動作確認用）:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o main
./main
```
