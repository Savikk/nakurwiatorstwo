/*
 *	@author: Savikk
 *	@e-mail: savikk@boo.pl
 */
#include <stdio.h>
#include <mpi.h>
#include "vector.h"
#include "matrix.h"
#define TAB 16

int main(int argc, char **argv){
	double pom=0; double pom2=0;
	int size,rank;
		Vector *Y = newVector(TAB);
		Vector *K = newVector(TAB);
		Matrix *A = newMatrix(TAB,TAB);
		Vector *X = newVector(TAB);
		FILE *ve = fopen("vector.txt","r");
		FILE *we = fopen("matrix.txt","r");
		fillMatrix(A,we);
		fillVector(X,ve);
	MPI_Init(&argc,&argv);
	MPI_Status statusik;
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	int i,j,l;
	for(i=rank*4;i<rank*4+4;i++){
	K->data[i]= 0;
	for(j=0;j<TAB;j++){
	K->data[i]+=A->data[i*TAB+j] * X->data[i];
	}}

printVector(K);
//kurwa ze tez te 2int sie nie sumuje

for(j=0;j<16;j++){	
	pom+=K->data[j];

//printf("%lf\n",pom);}
MPI_Reduce(&pom,&pom2,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
if(rank==0){Y->data[j]=pom2;}
pom=0;}
if(rank==0){
printVector(Y);
	}		
      
      fclose(we);
      fclose(ve);
      destroyVector(K);
      destroyVector(Y);
      destroyVector(X);
      destroyMatrix(A);
MPI_Finalize();
        return 0;
}

