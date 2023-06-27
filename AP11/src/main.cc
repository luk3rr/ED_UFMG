#include <cstdlib>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include "disjoin_set.h"
#include "relation.h"

double GetTime(struct timespec t1, struct timespec t2) {
	struct timeval res;

	if (t2.tv_nsec < t1.tv_nsec) {
		// ajuste necessario, utilizando um segundo de tv_sec
		res.tv_usec = 1000000000 + t2.tv_nsec - t1.tv_nsec;
		res.tv_sec = t2.tv_sec - t1.tv_sec - 1;
	}
	else {
		// nao e necessario ajuste
		res.tv_usec = t2.tv_nsec - t1.tv_nsec;
		res.tv_sec = t2.tv_sec - t1.tv_sec;
	}

	return (double)res.tv_sec + (double)res.tv_usec / 1000000000.0;
}

int main(){
	//arquivo para armazenar os dados
	FILE* file = fopen("data.dat", "w");

	struct timespec start;
	struct timespec stop;

	//relacao de equivalencia
	Relation* rel = NULL;

	//a estrutura de conjuntos disjuntos
	DisjoinSet* uf = NULL;

	for (long i = 100; i < 2000; i= i+100 ) {
		printf("TESTANDO PARA %ld elementos\n", i);
		rel = new Relation(i);
		uf = new DisjoinSet();

		//comecando a cronometrar o tempo
		clock_gettime(CLOCK_MONOTONIC, &start);

		//criando os conjuntos
		for (long j = 0; j < i; j++)
			uf->MakeSet(j);
		

		for (long j = 0; j < i; j++)
			for(long k = 0; k < i; k++)
				if(rel->HasRelation(j,k))
					uf->UnionSet(j,k);
		

		clock_gettime(CLOCK_MONOTONIC, &stop);
		fprintf(file, "%ld %f\n", i, GetTime(start, stop));

		for (long j = 0; j < i; j++)
			for (long k = 0; k < i; k++)
				if (rel->HasRelation(j,k) && (uf->FindSet(j) != uf->FindSet(k)))
					printf("ERROR: %ld e %ld deviam estar no mesmo conjunto!\n", j, k);

		delete rel;
		delete uf;
	}

	fclose(file);

	return EXIT_SUCCESS;
}
