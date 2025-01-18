#!/bin/bash

    # User Input
    echo "Enter first number:"
    read num1
    echo "Enter second number:"
    read num2
    sum=$((num1 + num2))
    echo "The sum of $num1 and $num2 is: $sum"

    # Hard Coded
    num3=12
    num4=12
    sum2=$((num3 + num4))
    echo "$sum2"
