#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
  int x, y;
  int *data;
} Matrix;

Matrix *newMatrix(int x, int y){
  Matrix *m = malloc(sizeof(Matrix));
  m->x = x;
  m->y = y;
  m->data = malloc(x*y*sizeof(int));
  return m;
}

void fillMatrix(Matrix *m, FILE *f){
  int i;
  for (i=0; i<m->x*m->y; i++){
    fscanf(f,"%i", &m->data[i]);
  }
}

void printMatrix(Matrix *m){
  int i,j;
  printf("Matrix %i x %i:\n", m->x, m->y);
  for (i=0; i<m->y; i++){
    for (j=0; j<m->x; j++){
      printf("%i ", m->data[i*m->x + j]);
    }
    printf("\n");
  }
}

void destroyMatrix(Matrix *m){
  free(m);
}

