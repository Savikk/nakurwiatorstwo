/*
 *	@author: Savikk
 *	@e-mail: savikk@boo.pl
 */
#include <stdio.h>
#include <mpi.h>
#include "vector.h"
#include "matrix.h"
#define TAB 16
Vector *Y = newVector(TAB);
Matrix *A = newMatrix(TAB,TAB);
Vector *X = newVector(TAB);
FILE *ve = fopen("vector.txt","r");
FILE *we = fopen("matrix.txt","r");
fillMatrix(A,we);
fillVector(X,ve);
int main(int argc, char **argv){
	int size,rank;
		/*Vector *Y = newVector(TAB);
		Matrix *A = newMatrix(TAB,TAB);
		Vector *X = newVector(TAB);
		FILE *ve = fopen("vector.txt","r");
		FILE *we = fopen("matrix.txt","r");
		fillMatrix(A,we);
		fillVector(X,ve);*/
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	int i,j;
	if(rank==0){
	for(i=0;i<16;i++){
			Y->data[i] = 0;
		for(j=0;j<3;j++){
			Y->data[i]+=A->data[i*16+j] * X->data[i];
		}
	}}
	else{
	for(i=0;i<16;i++){
		for(j=rank*4;j<rank*4+3;j++){
			Y->data[i]+A->data[i*16+j] * X->data[i];
	printVector(Y);
			
      
      fclose(we);
      fclose(ve);
      destroyVector(Y);
      destroyVector(X);
      destroyMatrix(A);
	MPI_Finalize();
        return 0;
}
