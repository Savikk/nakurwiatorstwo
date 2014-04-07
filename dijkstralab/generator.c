/*
 *		Generator Labiryntu #Dijkstra beta nie skonczone
 *		@author: Paweł Sawicki
 *		gcc generator.c -o generator
 */
#include <stdio.h>

int main(){
int jed,jedn,minus,pom,waga,plus,i,licznik;
 licznik=0;
  for(i=1;i<51;i++){
	pom=1;
	plus=i+10;
	minus=i-10;
	jed=i+1;
	jedn=i-1;
	if(i==18 || i==27 || i ==36 || i==45){pom=1;}
	else if(minus == 18 || minus ==27 || minus==36 || minus==45){pom=1;}
	else if(plus == 18 || plus ==27 || plus == 36 || plus==45){pom=1;}
	else if(jed==18 || jed ==27 || jed ==36 || jed==45){pom=1;}
	else if(jedn==18 || jedn==27 || jedn==36 || jedn==45){ pom =1;}else{pom=0;}

	if(pom==0){waga=1;}else{ waga=100;}
	if(i%10!=0){printf("%i %i %i\n",i,jed,waga);licznik++;}
	if((i%10)!=1){printf("%i %i %i\n",i,jedn,waga);licznik++;}
	if(plus<50){printf("%i %i %i\n",i,plus,waga);licznik++;}
	if(minus>0){printf("%i %i %i\n",i,minus,waga);licznik++;}
	}

return 0;
}
