#include <stdio.h>
#include "vector.h"
#include "matrix.h"

int main(int argc, char **argv){
		Vector *Y = newVector(16);
		Matrix *A = newMatrix(16,16);
		Vector *X = newVector(16);
		FILE *ve = fopen("vector.txt","r");
		FILE *we = fopen("matrix.txt","r");
		fillMatrix(A,we);
		fillVector(X,ve);
		//test
		//printVector(X);
	//	printMatrix(A);
	int i,j;
		for(i=0;i<16;i++){
			Y->data[i] = 0;
		for(j=0;j<16;j++){
			Y->data[i]+=A->data[i*16+j] * X->data[i];
		}
	}
	printVector(Y);
			
      
      fclose(we);
      fclose(ve);
      destroyVector(Y);
      destroyVector(X);
      destroyMatrix(A);
        return 0;
}
