// Modify this file for your assignment
#include <stdio.h>
#include <stdlib.h>
#include <signal.h> // This is new!
#include <unistd.h> 

// Create a signal handler
void sigint_handler(int sig){
	// Ask yourself why 35?
	write(1,"Terminating through signal handler\n",35); 
	exit(0);
}

int main(){

	// Install our signal handler
	signal(SIGINT, sigint_handler);

	printf("You can only terminate by pressing Ctrl+C\n");

	while(1){
		printf("Running forever!\n");
		sleep(1);
	}

	return 0;
}

















