#include "../include/common_threads.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int a;
  int b;
} myarg_t;

typedef struct {
  int x;
  int y;
} myret_t;

void *mythread(void *arg) {
  myret_t *rvals = malloc(sizeof(myret_t));
  rvals->x = 1;
  rvals->y = 2;
  return (void *)rvals;
}

void run(void) {
  pthread_t p;
  myret_t *rvals;
  myarg_t args = {10, 20};

  Pthread_create(&p, NULL, mythread, &args);
  Pthread_join(p, (void **)&rvals);
  printf("returned %d %d\n", rvals->x, rvals->y);
  free(rvals);
}
