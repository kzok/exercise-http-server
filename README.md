# Exercise - HTTP Server

[![CircleCI](https://circleci.com/gh/kzok/exercise-http-server.svg?style=shield)](https://circleci.com/gh/kzok/exercise-http-server)
[![codecov](https://codecov.io/gh/kzok/exercise-http-server/branch/master/graph/badge.svg)](https://codecov.io/gh/kzok/exercise-http-server)

## 概要

[libuv](https://github.com/libuv/libuv) を使って遊ぶためのリポジトリです。
とりあえず HTTP/1.1 サーバ作ってみます。

## 必要なツール

- C++17 compiler (GCC or Clang)
- GNU make
- [CMake](https://cmake.org/)
- [LCOV](http://ltp.sourceforge.net/coverage/lcov.php)

## コマンド

### 初期化 

```bash
git submodule sync && git submodule update --init
```

### ビルド

```bash
./build.sh
```

### 実行

```bash
./run.sh
```

### テスト

```bash
./run_test.sh
```

## 依存しているライブラリ

- [libuv](https://github.com/libuv/libuv)
- [uvw](https://github.com/skypjack/uvw)
- [doctest](https://github.com/onqtam/doctest)
