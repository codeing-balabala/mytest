#!/bin/bash

set -e

mkdir -p build
rm -rf build/*
cd build && cmake ..
make
# cd -
./my_test

