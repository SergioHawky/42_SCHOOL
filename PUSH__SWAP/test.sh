#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <number_of_integers>"
    exit 1
fi

n=$1

generate_unique_random_integers() {
    local count=$1
    local numbers=()

    while [ "${#numbers[@]}" -lt "$count" ]; do
        num=$(( (RANDOM << 15 | RANDOM) % 20001 - 10000 ))  # Range: -10000 to 10000
        if [[ ! " ${numbers[@]} " =~ " $num " ]]; then
            numbers+=("$num")
        fi
    done

    echo "${numbers[@]}"
}

total=0
min=-1
max=0

for i in {1..10}; do
    echo "Test #$i"
    input=$(generate_unique_random_integers "$n")

    result=$(./push_swap $input | ./checker_linux $input)
    echo -e "Result: $result"

    count=$(./push_swap $input | wc -l)
    echo -e "Number of operations: $count"
    echo "-----------------------------"

    total=$((total + count))

    if [ "$min" -eq -1 ] || [ "$count" -lt "$min" ]; then
        min=$count
    fi

    if [ "$count" -gt "$max" ]; then
        max=$count
    fi
done

average=$((total / i))

echo "Lowest number of operations:  $min"
echo "Highest number of operations: $max"
echo "Average number of operations: $average"