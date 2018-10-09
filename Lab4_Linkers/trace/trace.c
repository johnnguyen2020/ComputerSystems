#include <stdio.h>
#include <time.h>

int counter = 0;
time_t start_t;
time_t end_t;
double diff_t;

__attribute__((no_instrument_function))
void __cyg_profile_func_enter(void *this_fn, void *call_site){

	printf("Function entered\n");
	counter+=1;
	time(&start_t);
	sleep(5);

}

__attribute__((no_instrument_function))
void __cyg_profile_func_exit(void *this_fn, void *call_site){

	printf("Function exited\n");
	printf("%d\n",counter);
	time(&end_t);
	diff_t = difftime(end_t, start_t);
	printf("Execution time = %f\n", diff_t);

}

