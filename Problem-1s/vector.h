typedef struct Vector {
  int size;
  int *data;
} Vector;
Vector *newVector(int n);

void fillVector(Vector *v,FILE *f);

void printVector(Vector *v);

void destroyVector(Vector *v);

