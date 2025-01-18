#!/bin/bash
# Program to check if an array is a palindrome

read -p "Enter the elements of the array separated by spaces: " -a input_array
palindrome_flag=1
array_length=${#input_array[@]}

for ((start=0, end=array_length-1; start<end; start++, end--)); do
    if [[ ${input_array[start]} -ne ${input_array[end]} ]]; then
        palindrome_flag=0
        break
    fi
done

if [[ $palindrome_flag -eq 1 ]]; then
    echo "The array is a palindrome."
else
    echo "The array is not a palindrome."
fi
