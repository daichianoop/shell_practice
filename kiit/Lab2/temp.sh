#!/bin/bash

    echo "Enter temperature in Celsius:"
    read celsius
    fahrenheit=$(( ($celsius * 9/5) + 32 ))
    echo "$celsius °C is equal to $fahrenheit °F"
