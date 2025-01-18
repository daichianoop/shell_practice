#!/bin/bash

    # User Input
    echo "Enter First Number"
    read a
    echo "Enter Second Number"
    read b
    sub=$((a - b))
    echo "1. The Difference of $a and $b is : $sub"

    # Hard Coded
    c=12
    d=10
    sub2=$((c - d))
    echo "2. $sub2"

    # One Line
    echo "3. The Difference is $((a-b))"
