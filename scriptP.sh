#!/bin/bash

DIR_NAME=$1

echo Creating directories
for i in {1..5..1}
do
    mkdir -p results/$DIR_NAME/
done

for i in {1..5..1}
do
    echo Starting iteration $i.
    for j in {1..8..1}
    do
        echo ./sieve-parallel.exe 1000000000 t $j
        ./sieve-parallel.exe 1000000000 t $j >> results/$DIR_NAME/$i.txt
    done
    echo Iteration $i done
done
