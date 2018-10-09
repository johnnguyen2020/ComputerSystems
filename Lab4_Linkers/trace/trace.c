#include <stdio.h>
#include <time.h>

//counter to keep track of function call count 
int counter = 0;

//variables to calculate function elapsed time
time_t start_t;
time_t end_t;
double diff_t;


__attribute__((no_instrument_function))
void __cyg_profile_func_enter(void *this_fn, void *call_site){

	printf("Function entered\n");
	counter+=1; //increment counter by 1 every time function is called
	time(&start_t); //start timer
	sleep(5); //pause program by 5 seconds to show timer funcitonality

}

__attribute__((no_instrument_function))
void __cyg_profile_func_exit(void *this_fn, void *call_site){

	printf("Function exited\n");
	printf("%d\n",counter); //print count
	time(&end_t); //end timer
	diff_t = difftime(end_t, start_t); //calc end time minus start time 
	printf("Execution time = %f\n", diff_t); //print function elapse time

}

