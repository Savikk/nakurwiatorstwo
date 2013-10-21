/*
 *	@author: Savikk
 *	@e-mail: savikk@boo.pl
 */
#include <stdio.h>
#include <mpi.h>
#include <time.h>
#include "vector.h"
#include "matrix.h"
#define TAB 16
#define MAX 60000l
#define MLD 1000000000.0

void stoper();
int main(int argc, char **argv){
	double pom=0; double pom2=0;
	int size,rank;
	struct timespec tp0, tp1;
	int a[MAX];
	long ii,jj; double sp, sum;
	double start,end;
	start=MPI_Wtime();      
 //	clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp0);

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
	//for(i=rank*4;i<rank*4+4;i++){
	//K->data[i]= 0;
	//for(j=0;j<TAB;j++){
	//K->data[i]+=A->data[i*TAB+j] * X->data[i];
	//}}
	int rest = (size - (TAB % size)) % size;
        int n_size = TAB + rest;
        int part = n_size / size;
	//int part=TAB/size;
	for(i=0;i<n_size;i++){
	//	K->data[i]=0;
	   for(j=0;j<part;j++){
		K->data[i]+=A->data[(i*n_size)+j]*X->data[i];
		//printf("%i\n",K->data[i]);
}
}


for(j=0;j<16;j++){	
	pom+=K->data[j];
//printf("%lf\n",pom);}
MPI_Reduce(&pom,&pom2,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
//clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp1);
end=MPI_Wtime();
if(rank==0){Y->data[j]=pom2;}
pom=0;}
if(rank==0){
printVector(Y);
sp=(tp1.tv_sec+tp1.tv_nsec/MLD)-(tp0.tv_sec+tp0.tv_nsec/MLD);
sum=sum+sp;
printf("czas %3.15lf\n",end-start);

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

