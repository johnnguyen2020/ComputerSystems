#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "test.h"
#include "timer.h"

#define SIZE 10
#define TIMES 30000

int main(int argc, char *argv[]){
  char *progname;
  progname = (argc > 0) ? argv[0] : "";
  start_timer();
  MESSAGE("Allocate and Assert\n");
  int *t;
  t = malloc(sizeof(int)*400);
  t[0] = 12;
  t[1] = 18;
  t[2] = 20;
  t[3] = 24;
  t[100] = 100;
  t[200] = 200;

  (t[0] == 12) ? MESSAGE("ALLOCATE SUCCESS! \n") : MESSAGE("ALLOCATE FAILED! \n");
  (t[1] == 18) ? MESSAGE("ALLOCATE SUCCESS! \n") : MESSAGE("ALLOCATE FAILED! \n");
  (t[2] == 20) ? MESSAGE("ALLOCATE SUCCESS! \n") : MESSAGE("ALLOCATE FAILED! \n");
  (t[3] == 24) ? MESSAGE("ALLOCATE SUCCESS! \n") : MESSAGE("ALLOCATE FAILED! \n");
  (t[100] == 100) ? MESSAGE("ALLOCATE SUCCESS! \n") : MESSAGE("ALLOCATE FAILED! \n");
  (t[200] == 200) ? MESSAGE("ALLOCATE SUCCESS! \n") : MESSAGE("ALLOCATE FAILED! \n");

  free(t);
  end_timer();
  print_log_timer();
  return 0;

}
