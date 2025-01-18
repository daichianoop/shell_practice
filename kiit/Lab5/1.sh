#!/bin/bash

#Write a program to merge two sorted Arrays into another Sorted Array
array1=(1 3 5 7)
array2=(2 4 6 8)

merged=("${array1[@]}" "${array2[@]}")
sorted=($(for num in "${merged[@]}"; do echo $num; done | sort -n))

echo "Merged and sorted array: ${sorted[@]}"
