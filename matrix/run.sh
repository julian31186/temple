#!/bin/bash

if [ "$#" -eq 0 ]; then
    echo "How to use ./run {file_to_run.c}"
    exit 1
fi

gcc *.c -g -lm -I./include/*.h -o out

./out