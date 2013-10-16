#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
  int size;
  int *data;
} Vector;

Vector *newVector(int n){
  Vector *v = malloc(sizeof(Vector));
  v->size = n;
  v->data = malloc(n*sizeof(int));
  return v;
}

void fillVector(Vector *v, FILE *f){
  int i;
  for (i=0; i<v->size; i++){
    fscanf(f,"%i", &v->data[i]);
  }
}

void printVector(Vector *v){
  int i;
  printf("Size: %i [ ", v->size);
  for (i=0; i<v->size-1; i++){
    printf("%i, ", v->data[i]);
  }
  printf("%i ]\n", v->data[v->size-1]);
}

void destroyVector(Vector *v){
  free(v);
}
