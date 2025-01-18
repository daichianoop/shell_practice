#!/bin/bash
# WAP to count the occurace of any element in an array of n elements

array=(1 2 3 4 2 5 2 6 7 2 1 2 5 4 2 3 4 5 6 7 8 9 0 0 9 8 7 6 5 4 3 2 1)
read -p "Enter the element to count: " element

count=0
for num in "${array[@]}"; do
    if [[ $num -eq $element ]]; then
        count=$((count + 1))
    fi
done
echo "Element $element occurs $count times in the array."
