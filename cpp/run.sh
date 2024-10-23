#!/bin/bash
if [ -z "$1" ] || [[ $1 != src* ]]; then
    echo "Usage: $0 src/cpp-filename"
    exit 1
fi
cppFile="$1"
g++ $cppFile -o a.out -std=c++17 -lpthread && ./a.out
rm a.out
