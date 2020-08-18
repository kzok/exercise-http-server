#!/bin/bash -eu

cd $(dirname $0)
mkdir -p ./build
cd ./build
cmake ..
make run_tests

./run_tests
rm -fr ./lcov.info ../coverage
mkdir -p ../coverage
lcov -c -d . -o ./lcov.info > /dev/null
lcov -r ./lcov.info */deps/* */test/* */c++/* -o ./lcov.info > /dev/null
genhtml -o ../coverage ./lcov.info
