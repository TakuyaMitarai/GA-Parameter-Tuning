from hyperopt import fmin, tpe, hp, Trials
import subprocess
import numpy as np

def evaluate_function(paras):
    para_str = " ".join(map(str, paras.values()))
    
    for _ in range(10):
        subprocess.run(f"./a.out {para_str} >> \"./output.txt\"", shell=True)
    
    with open("output.txt", "r") as f:
        lines = f.readlines()
        last_10_lines = lines[-10:]
        evaluations = [float(line.split()[0]) for line in last_10_lines]
        average_evaluation = np.mean(evaluations)
    
    print(f"{paras} {average_evaluation}")
    
    return average_evaluation

para_space = {
    '1pop_size': hp.uniform('1pop_size', 99, 100),
    '2elite': hp.uniform('2elite', 1, 40),
    # '3mutate_prob': hp.loguniform('3mutate_prob', np.log(0.0001), np.log(1)),
    '3mutate_prob': hp.uniform('3mutate_prob', 0.00001, 0.3),
    '4tournament_size': hp.uniform('4tournament_size', 1, 30)
}

# fminの呼び出し（アルゴリズムをTPEに設定）
trials = Trials()
best = fmin(evaluate_function, para_space, algo=tpe.suggest, trials=trials, max_evals=400)

print(f"Best parameters: {best}")
