// gcc -std=c99 -fopenmp omp5.c -o omp5
// You fill in
//this is not quick sort but a modular way to parallelize the pi program
//since it works regardless of computer architecture by implementing a
//critical section lock which does not rely on any padding logic to 
//in accordance with the cache line size

#include <stdio.h>
#include <omp.h>


static long num_steps = 100000;
double step;
#define NUM_THREADS 2

int main(){
  double pi = 0.0;  //variables outside the parallel construct
  int nthreads;
  step = 1.0/(double)num_steps;
  omp_set_num_threads(NUM_THREADS);

  #pragma omp parallel
  {
    int i,id,nthrds;   //variables on each threads stack
    double x,sum;
    id = omp_get_thread_num();
    nthrds = omp_get_num_threads();
    if(id == 0) nthreads = nthrds;
    id = omp_get_thread_num();
    nthrds = omp_get_num_threads();
    for(i = id, sum = 0.0; i < num_steps; i=i + nthrds){  //parallized so each thread has a sum
        x = (i+0.5)*step;
        sum += 4.0/(1.0+x*x);
    }
    #pragma omp critical  //pi is final sum od each threads sum
        pi += step * sum; //protected locked section
  }
  
  printf("PI = %f\n", pi);
  return 0;
}
