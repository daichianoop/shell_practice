#!/bin/bash
numbers=()
echo "Enter Array Size"
read -r size 

for ((i = 0 ; i <=  size ; i++)); do 
echo "enter element $((i+1))"
read 
done