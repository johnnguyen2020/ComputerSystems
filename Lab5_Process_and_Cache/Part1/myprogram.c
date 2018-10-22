#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

	
	char* myargv[16];      //buffer size of myargv
	myargv[0]="/bin/ps";   //first command "ps:
	//myargv[1]="-F";
	myargv[2]=NULL; // Terminate the argument list
	
	if(fork()==0){
		execve(myargv[0],myargv,NULL);
		printf("Child: Should never get here\n");
		exit(1);
		}else{	 										
			wait(NULL); //handy synchronization function again!
		        //printf("This always prints last\n");
			myargv[0]="/bin/pwd"; //second command "pwd"
			myargv[2]=NULL; // Terminate the argument list
			
			if(fork()==0){
			execve(myargv[0],myargv,NULL);
			printf("Child: Should never get here\n");
			exit(1);
			}else{	 										
				wait(NULL); //handy synchronization function again!
		   	    	printf("This always prints last\n");
			    	myargv[0] = "/bin/man"; //third command "man" all in nested for loop ran in children
					if(fork()==0){
						execve(myargv[0],myargv,NULL);
						printf("Child: Should never get here\n");
					exit(1);	
					}else{	 										
						wait(NULL);
					}	
			}
		}	
	return 0;
}












