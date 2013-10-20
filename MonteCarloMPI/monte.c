#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <mpi.h>
#define PI      3.141592653589793238462643383279502884197169399375105  // pi do 50miejsca po przecinku #wiki
#define obrot    100000000 //ilosc obrotow
//funkcja wybierajaca randomowa liczbe pomiedzy -1 a 1
double losuj(double a, double b) {
  double w;
  w = ((b - a) * ((double) rand()/(double) RAND_MAX)) + a;
  return w;
} 
int main (int argc, char *argv[]) { // po- srednie pi, pis - suma srednich pi, er - blad pomiaru w stosunku do wartosci PI z wiki
   int   rank,size, npkt, i;	    // npkt - punkty w kole
   double po,pis,a,b,s,er,start,end;      
 
  struct timeval stime;
 
  npkt = 0;
 
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
 
  if (rank == 0) {
    printf("\n  Monte Carlo\n\n");
    printf("    size : %d\n", size);
    printf("    ilosc badan     : %d\n\n", obrot);
 
    start = MPI_Wtime();
  }  
  gettimeofday(&stime, NULL);
  srand(stime.tv_usec * stime.tv_usec * stime.tv_usec * stime.tv_usec);
  for (i = 1; i <= obrot; i++) {
    a = losuj(-1, 1);
    b = losuj(-1, 1);
    s = pow(a, 2) + pow(b, 2);
 
    if (s <= 1.0) {
       npkt++;
    }
 
  } 
  po = 4.0 * (double)npkt/(double)obrot;
 
  MPI_Reduce(&po, &pis, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
 
  if (rank == 0) {
	pis= pis / size;
    end = MPI_Wtime();
    printf("    PI #wiki   : %11.50f\n", PI);
    printf("    srednie PI  : %11.50f\n", pis);
    printf("    czas (sec)   : %10.8f\n\n", end - start);
  }
 MPI_Finalize(); 
 return 0;
}

