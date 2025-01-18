#!/bin/bash

    # seperately
    echo "Enter distance in centimeters:"
    read cm
    m=$((cm / 100))
    Km=$((cm / 10000))
    echo "1. -> $Km Km -> $m m"

    # Mixed
    echo "2. $((cm / 10000)) Km $((cm % 10000)) m"
