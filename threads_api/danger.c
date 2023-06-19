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
  myarg_t *args = (myarg_t *)arg;
  printf("%d %d\n", args->a, args->b);
  myret_t oops; // allocated on stack: bad!
  oops.x = 1;
  oops.y = 2;
  return (void *)&rvals;
}
