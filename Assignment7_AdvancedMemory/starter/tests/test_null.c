#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "test.h"
#include "timer.h"

#define SIZE 10
#define TIMES 30000

int main(int argc, char *argv[]) {
  char *progname;
  progname = (argc > 0) ? argv[0] : "";
  char *p;
  start_timer();
  MESSAGE("Allocate zero\n");
  if ((p = malloc(0)) != NULL)
    MESSAGE("* Warning: malloc(0) returned non NULL pointer!\n");
  MESSAGE("Free pointer from malloc(0)\n");
  free(p);

  end_timer();
  print_log_timer();
  return 0;
}
