#include <stdio.h>
#include <time.h>

//counter to keep track of function call count 
int counter = 0;

//variables to calculate function elapsed time
time_t start_t;
time_t end_t;
double diff_t;
time_t start_main;
time_t end_main;
double diff_main;


__attribute__((no_instrument_function))
void __cyg_profile_func_enter(void *this_fn, void *call_site){
	printf("%d\n", *(int*)call_site);
	if( *(int*)call_site == -1796683895){    //call_site is the address where the main function is being called
		time(&start_main);
		}
	printf("Function entered\n");
	counter+=1; //increment counter by 1 every time function is called
	time(&start_t); //start timer
	//sleep(5); //pause program by 5 seconds to show timer funcitonality

}

__attribute__((no_instrument_function))
void __cyg_profile_func_exit(void *this_fn, void *call_site){
	if( *(int*)call_site == -1796683895){
		time(&end_main);
		diff_main = difftime(end_main, start_main);
		}
	printf("%d\n", *(int*)call_site);
	//printf("Function exited\n");
	printf("%d\n",counter); //print count
	time(&end_t); //end timer
	diff_t = difftime(end_t, start_t); //calc end time minus start time 
	printf("Execution time = %f\n", diff_t); //print function elapse time
	printf("Execution time Main = %f\n", diff_main); //print function elapse time

}

