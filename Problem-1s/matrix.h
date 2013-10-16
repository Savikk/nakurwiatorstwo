#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
  int x, y;
  int *data;
} Matrix;
Matrix *newMatrix(int x, int y);

void fillMatrix(Matrix *m, FILE *f);

void printMatrix(Matrix *m);

void destroyMatrix(Matrix *m);
