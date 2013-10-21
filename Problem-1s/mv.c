/*
 *	@author: Savikk
 *	@e-mail: savikk@boo.pl
 */
#include <stdio.h>
#include "vector.h"
#include "matrix.h"
#include <time.h>
double timeDiff(struct timespec *timeA_p, struct timespec *timeB_p)
{
        double diff = (((timeA_p->tv_sec * 1000000000) + timeA_p->tv_nsec) -
                                         ((timeB_p->tv_sec * 1000000000) + timeB_p->tv_nsec));
        return diff / 1000000000;
}
int main(int argc, char **argv){
		Vector *Y = newVector(16);
		Matrix *A = newMatrix(16,16);
		Vector *X = newVector(16);
		FILE *ve = fopen("vector.txt","r");
		FILE *we = fopen("matrix.txt","r");
		fillMatrix(A,we);
		fillVector(X,ve);
		struct timespec start,end;
		int i,j;
		clock_gettime(CLOCK_MONOTONIC, &start);		
		for(i=0;i<16;i++){
			Y->data[i] = 0;
		for(j=0;j<16;j++){
			Y->data[i]+=A->data[i*16+j] * X->data[i];
		}
	}
	clock_gettime(CLOCK_MONOTONIC,&end);
	printVector(Y);
			
      printf("%.16f\n",timeDiff(&end,&start));
      fclose(we);
      fclose(ve);
      destroyVector(Y);
      destroyVector(X);
      destroyMatrix(A);
        return 0;
}
