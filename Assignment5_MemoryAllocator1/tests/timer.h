#include <sys/time.h>

struct timeval start, end;

void start_timer() {
  gettimeofday(&start, NULL);
}

void end_timer() {
  gettimeofday(&end, NULL);
}

void print_log_timer() {
  printf ("Total time = %f seconds\n",
          (double) (end.tv_usec - start.tv_usec) / 1000000 +
          (double) (end.tv_sec  - start.tv_sec));
}
