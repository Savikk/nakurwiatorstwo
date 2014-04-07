/*
 *		Labirynt #Dijkstra
 *		@author: Paweł Sawicki
 *		g++ dijkstra_s.cpp -o dijkstra
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int MAX = 100;
const int INF = 9999;

struct Node
{
  int nw;
  int waga;          // waga ( W labiryncie kazda waga wynosi 1)
  struct Node * nast;
};


int main(int argc,char **argv){

FILE *we;          //Inicjalizacja zczytywania z pliku
//if(argc==0){ 
//cout << "Uzycie ./dijkstra plik_danych" << endl;
//}
else{
  
  we = fopen("dane.txt","r");
  int i,j,x,y,z,v0,vk,u.n.m;
  int k[MAX+1],p[MAX+1];
  bool QS[MAX+1];
  struct Node *L[MAX+1],*pw;
  for(i = 1; i <= MAX; i++)
  {
    k[i]  = INF; 
    p[i]  = 0;    
    QS[i] = false; // jest w Q(t) czy nie Q(f)
    L[i]  = NULL;   // sasiedzi
  }
  n = 0;

  fscanf(we,"%i %i %i",&v0,&vk,&m); //zczytywanie z pliku,
  for(i = 1; i <= m; i++)
  {
    fscanf(we,"%i %i %i",&x,&y,&z);
    if(x > n) n = x;
    if(y > n) n = y;
    pw = new Node;
    pw->nast = L[x]; pw->nw = y; pw->waga = z; L[x] = pw;
  }
  cout << endl;

  k[v0] = 0; 
  
  for(i = 1; i <= n; i++)
  {				// Sprawdzenie czy droga do wierzcholka nie jest zbyt kosztowna
    u = -1;			// (sciany labiryntu maja wieksza wage niz normalne drogi pomiedzy wierzcholkami)
    for(j = 1; j <= n; j++)
    if(!QS[j] && ((u == -1) || (k[j] < k[u]))) u = j;
    QS[u] = true;
    pw = L[u];			// uaktualnienie sasiadow wierzcholka
    while(pw)
    {
      if(!QS[pw->nw] && (k[pw->nw] > k[u] + pw->waga))
      {
        k[pw->nw] = k[u] + pw->waga;
        p[pw->nw] = u;
      }
      pw = pw->nast;
    }
  }

  int s[MAX],ws;
  cout << vk << ": ";
  ws = 0; j = vk;
  
    while(j)
    {
      s[ws++] = j; j = p[j];
    }
    while(ws) cout << s[--ws] << " ";  // wypisywanie kolejnych wierzcholkow drogi od v0 do vk  
    cout << "#" << k[vk] << endl;    
}
fclose(we);
return 0;
}
