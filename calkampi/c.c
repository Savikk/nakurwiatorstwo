#include <math.h>
#include <stdio.h>
#include <mpi.h>
#include <time.h>
#define MAX 600001
#define MLD 1000000000.0

void stoper();
int main(int argc,char** argv){
   int a,b,n,h,rank, size;
   double s;
   struct timespec tp0, tp1;
   double sp,sum;
   int pom;
   MPI_Init(&argc,&argv);        
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp0);
   MPI_Comm_rank(MPI_COMM_WORLD,&rank);
   MPI_Comm_size(MPI_COMM_WORLD,&size);
   
   a = atoi(argv[1]);
   b = atoi(argv[2]);
   n = 10;
   h = b-a;
      
   double g1 = a + ((double) rank)/((double) size)*(b-a);
   double g2 = a + ((double) rank+1)/((double) size)*(b-a);
   double trap = 0;
   
   if(g2<=b){
       int i;
       for(i=0; i<n; i++){
           double g11 = g1+(g2-g1)*((double)i/n);
           double g22 = g1+(g2-g1)*((double)(i+1)/n);
           trap = trap + (g22-g11)*(exp(-(g11*g11))+exp(-(g22*g22)))/2;
       }
       printf("P %i: %e - %e = %e\n", rank, g1, g2, trap);
   }
   
   MPI_Reduce(&trap,&s,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
   
        
   if ( rank == 0 ){
	 clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp1);
     sp=(tp1.tv_sec+tp1.tv_nsec/MLD)-(tp0.tv_sec+tp0.tv_nsec/MLD);
     sum=sum+sp;
     printf("\n e^(-x^2) \n");
     printf(" z a=%i do b=%i\n", a, b);
     printf(" liczba zadan: %d\n",size);
     printf(" wynik: %e\n\n", s);
     printf("czas %3.15lf\n",sum/1000000);


            
      }
   
   MPI_Finalize();
   return 0;
}
