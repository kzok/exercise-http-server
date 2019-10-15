# Exercise - HTTP Server

[![CircleCI](https://circleci.com/gh/kzok/exercise-http-server.svg?style=shield)](https://circleci.com/gh/kzok/exercise-http-server) [![codecov](https://codecov.io/gh/kzok/exercise-http-server/branch/master/graph/badge.svg)](https://codecov.io/gh/kzok/exercise-http-server)

## Overview

Http server repository as an exercise of using [libuv](https://github.com/libuv/libuv).
This is **NOT** production-ready.

## Required tools

- C++17 compiler (GCC or Clang)
- GNU make
- [CMake](https://cmake.org/)
- [LCOV](http://ltp.sourceforge.net/coverage/lcov.php)

## Scripts

### Build & Run

```bash
./run.sh
```

### Run tests

```bash
./run_test.sh
```

## Depending libraries

- [libuv](https://github.com/libuv/libuv)
- [uvw](https://github.com/skypjack/uvw)
- [doctest](https://github.com/onqtam/doctest)
