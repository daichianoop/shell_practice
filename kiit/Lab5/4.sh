#!/bin/bash
array=(12 3 5 7 19 2 8)
sorted=($(for num in "${array[@]}"; do echo $num; done | sort -n))

second_smallest=${sorted[1]}
second_largest=${sorted[-2]}

echo "Original array: ${array[@]}"
echo "Second smallest number: $second_smallest"
echo "Second largest number: $second_largest"
