#!/bin/bash

rm "*.output" >/dev/null 2>&1

for file in *.c
do
    rm "a.out" >/dev/null 2>&1 # to catch compilation errors
    gcc "$file" >/dev/null 2>&1

    if [ "$file" == "mystery01.c" ]; then
        echo "saving original text"
        ./a.out > original
    else
        echo "testing $file"
        ./a.out > "$file.output"
        if ! diff original "$file.output"; then
            echo "$file does not match the original text"
            exit 1
        fi
    fi
done
