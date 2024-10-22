#!/bin/bash
if [ -z "$1" ]; then
    echo "Usage: $0 experiment-filename"
    exit 1
fi
cppFile="$1"
g++ $cppFile -o a.out -std=c++17 && ./a.out
rm a.out
