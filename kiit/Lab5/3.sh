#!/bin/bash
array=(1 2 3 4 5)

reversed=()
for ((i=${#array[@]}-1; i>=0; i--)); do
    reversed+=("${array[i]}")
done

echo "Original array: ${array[@]}"
echo "Reversed array: ${reversed[@]}"