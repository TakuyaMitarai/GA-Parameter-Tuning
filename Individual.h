// 標準ヘッダのインクルード
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include "Para.h"
using namespace std;

// 定数の定義
#define GEN_MAX			1000	// 世代交代数
#define N				2000	// 集合の要素となる最大数の平方値
#define TOURNAMENT_SIZE	30		// トーナメントサイズ

// 0以上1以下の実数乱数
#define RAND_01 ((double)rand() / RAND_MAX)

class Individual
{
public:
	static Para* para;
	Individual();
	~Individual();
	void evaluate();									// 適応度を算出する
	void crossover1(Individual *p1, Individual *p2);	// 交叉による子にする
	void crossover2(Individual *p1, Individual *p2);	// 交叉による子にする
	void crossoveru(Individual *p1, Individual *p2);	// 交叉による子にする
	void mutate();									// 突然変異を起こす

	int chrom[N];	// 染色体
	double fitness;	// 適応度
};
