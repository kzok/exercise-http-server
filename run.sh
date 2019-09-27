#!/bin/bash -eu

cd $(dirname $0)
./build.sh
./build/http-server
