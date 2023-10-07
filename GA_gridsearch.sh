#!/bin/sh

cd /Users/takuyam/Documents/workspace/GA_gridsearch

# #gridsearch
# for pop_size in $(seq 200 100 200); do
#     for elite in $(seq 1 1 20); do
#         for mutate_prob in $(seq 0.001 0.001 0.02); do
#             for i in {1..10}; do
#                 ./a.out $pop_size $elite $mutate_prob >> "./output.txt"
#             done
#         done
#     done
# done

#Tournament_size
for pop_size in $(seq 200 100 200); do
    for elite in $(seq 1 3 19); do
        for mutate_prob in $(seq 0.001 0.001 0.02); do
            for tournament_size in $(seq 1 1 10); do
                for i in {1..10}; do
                    ./a.out $pop_size $elite $mutate_prob $tournament_size >> "./output.txt"
                done
            done
        done
    done
done