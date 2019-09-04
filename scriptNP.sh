#!/bin/bash

DIR_NAME=$1

echo Creating directories
for i in {1..5..1}
do
    mkdir -p results/$DIR_NAME/$i
done

for i in {1..5..1}
do
    echo Starting iteration $i.
    for j in {1..8..1}
    do
        for k in {250000000..1000000000..250000000}
        do
            echo ./sieve-parallel.exe $k t $j
            ./sieve-parallel.exe $k t $j >> results/$DIR_NAME/$i/s$k.txt
        done
    done
    echo Iteration $i done
done
