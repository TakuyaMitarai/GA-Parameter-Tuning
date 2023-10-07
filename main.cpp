#include "Population.h"

int main(int argc, char* argv[])
{
	int i;
	double best_fit = DBL_MAX;
	Population* pop;
	clock_t start, end;
	float comptime;
	Para* para;

	srand((unsigned int)time(NULL));

	start = clock();
	para = new Para(argv);
	Population::para = para;
	Individual::para = para;
	pop = new Population();
	for(i = 1; i <= GEN_MAX; i++) {
		pop->alternate();
		if(best_fit > pop->ind[0]->fitness) {
			best_fit = pop->ind[0]->fitness;
		}
	}
	end = clock();
	comptime = (float)(end-start) / CLOCKS_PER_SEC;
	// printf("%d %d %f %f %f\n", para->POP_SIZE, para->ELITE, para->MUTATE_PROB, best_fit, comptime);
	printf("%d %d %f %d %f %f\n", para->POP_SIZE, para->ELITE,  para->MUTATE_PROB, para->TOURNAMENT_SIZE, best_fit, comptime);
	delete pop;
	delete para;

	return 0;
}
