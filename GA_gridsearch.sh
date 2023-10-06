#!/bin/sh

cd /Users/takuyam/Documents/workspace/GA_gridsearch

#gridsearch
for pop_size in $(seq 200 100 200); do
    for elite in $(seq 1 1 10); do
        for mutate_prob in $(seq 0.01 0.01 0.1); do
            for i in {1..10}; do
                ./a.out $pop_size $elite $mutate_prob >> "./output.txt"
            done
        done
    done
done