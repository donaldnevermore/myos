#include "../include/common_threads.h"
#include <stdio.h>
#include <stdlib.h>

void *mythread(void *arg) {
  long long int value = (long long int)value;
  printf("%lld\n", value);
  return (void *)(value + 1);
}

void run(void) {
  pthread_t p;
  long long int rvalue;
  Pthread_create(&p, NULL, mythread, (void *)100);
  Pthread_join(p, (void **)&rvalue);
  printf("returned %lld\n", rvalue);
}
