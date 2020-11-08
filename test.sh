#!/bin/bash

rm "*.output" >/dev/null 2>&1

for file in *.c
do
    if [ "$file" == "mystery01.c" ]; then
        rm "a.out" >/dev/null 2>&1 # to catch compilation errors
        echo "original version"
        gcc "$file" >/dev/null 2>&1
        ./a.out > original
    else
        rm "a.out" >/dev/null 2>&1 # to catch compilation errors
        echo "testing $file"
        gcc "$file" >/dev/null 2>&1
        ./a.out > "$file.output"
        if ! diff original "$file.output"; then
            echo "File does not match the original text"
            exit 1
        fi
    fi
done
