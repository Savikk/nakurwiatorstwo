#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define PI      3.141592653589793238462643383279502884197169399375105  // pi do 50miejsca po przecinku #wiki
#define obrot    100000000 //ilosc obrotow
#define size 4
//funkcja wybierajaca randomowa liczbe pomiedzy -1 a 1
 double losuj(double a, double b) {
  double r;
  r = ((b - a) * ((double) rand()/(double) RAND_MAX)) + a;
  return r;
} 
int main (int argc, char *argv[]) { // po- srednie pi, pis - suma srednich pi, er - blad pomiaru w stosunku do wartosci PI z wiki
   int    npkt, i,licz;	    // npkt - punkty w kole
   double po,pis,a,b,s;      
 
  struct timeval stime;
  pis = 0;
  npkt = 0; 
    printf("\n  Monte Carlo\n\n");
    printf("    ilosc badan     : %d\n\n", obrot);
 for(licz=1;licz<=size;licz++){
	npkt = 0;
	po = 0;  
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
 pis=pis+po;
// printf(" po: %11.10f pis: %11.10f\n", po,pis);	
 }
    pis=pis/size;
    printf("    PI #wiki   : %11.50f\n", PI);
    printf("    srednie PI  : %11.50f\n", pis);
 return 0;
}

