#!/bin/bash

# Remove files leftover from the previous run
rm "*.output" >/dev/null 2>&1

# The output from the original code
# All code refactoring steps must match this output
echo "Saving original text"
gcc phillipps.c >/dev/null 2>&1
./a.out > original

# Compare the output of all steps to the original output
for file in phillipps-step*.c; do
    echo "Testing $file"

    rm "a.out" >/dev/null 2>&1 # to catch compilation errors
    gcc "$file" >/dev/null 2>&1

    ./a.out > "$file.output"
    if ! diff original "$file.output"; then
        echo "$file does not match the original text"
        exit 1
    fi
done
