#pragma once

class Para
{
public:
    Para(char* para[]);
    ~Para();
    //int GEN_MAX           // 世代交代数
    int POP_SIZE;            // 個体群のサイズ
    int ELITE;	            // エリート保存戦略で残す個体の数
    double MUTATE_PROB;      // 突然変異確率
    int TOURNAMENT_SIZE;	// トーナメントサイズ
};