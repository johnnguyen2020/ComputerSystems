// Modify this file for your assignment
#include <stdio.h>
#include <stdlib.h>
#include <signal.h> // This is new!
#include <unistd.h> 
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <ctype.h>


const int MAX_BUF_SZ = 80; //Assumed max size for input buffer
char str_exit[4]; //size of string exit
//Create a signal handler
void sigint_handler(int sig){
	write(1,"mini-shell terminatd\n",21); //execute exit syscall
	exit(0);
}

void parse(char *line, char ** argv){
	int i = 0;
	char * token;  //char pointer of tokens   
	token = strtok(line," \t\r\n\a"); //line is split by follwing specifiers
	while (token != NULL){           //loop until null chacter and tokenize items in line into argv array
		argv[i] = token;        
		i++;
		token = strtok(NULL, " \t\r\n\a");
	}
	argv[i] = '\0'; //assign last element null character
	free(token);
}

void execute(char **argv){
	pid_t pid;         //initialize process id
	int status;        //varible holding process status

	if((pid = fork()) < 0){                  //if pid doesn't exist
		printf("Command not found\n");	
		exit(1);
	}
	else if(pid == 0){                       //if child process
		if (execvp(*argv, argv)<0){      //execute commands in tokenize line
		printf("Command not found\n");	 
		exit(1);
		}
	}
	else{while (wait(&status) != pid);}	//wait for child process to finish executing	
}

void foo_cd(char *d)                            //Built in command change directory
{
	if (chdir(d) != 0)
		{perror("error");} 
}

int help(){                                                     //prints help manual
	printf("HERE IS HELP MANUAL\n");
	printf("Builtin command:help -->displays help guide\n");
	printf("Builtin command:exit -->exits mini shell\n");
	printf("Builtin command:guessgame -->starts guessing game\n");
	printf("\tTry to select the correct number between 1-100\n");
	printf("Builtin command: cd -->change directories\n");
	return 0;	
}

void guessgame(){
	printf("Welcome to Guessing Game\n");            //built in to play guess game
	int random_num = 0; //initialize variables used in game                         
	int guess_num = 0;
	int counter = 0;
	srand(time(NULL));
	random_num = rand() % 100 + 1;  //call rand library for int from 0 to 100  
	printf("Guess a number from 1 to 100! ");
	
	while(1){ //loop until correct number guesses
		counter++; //track guesses
		scanf("%d", &guess_num); //take user input
		if (guess_num == random_num) //if correct nuber guessed, exit loop and function ends
		{
			printf("Congrats, %d is the winning number!\n", random_num);
			printf("You guess correctly in %d attempts\n", counter);
			break;
		}
		if (guess_num < random_num)
			printf("Your guess is too low. Guess again. ");  //hints for user, continues in loop after execution
		if (guess_num > random_num)
			printf("Your guess is too high. Guess again. ");
	}
}

int main(){
	strcpy(str_exit, "exit");           //fill buffer with "exit"
	// Install our signal handler
	signal(SIGINT, sigint_handler);
	char line[MAX_BUF_SZ];	            //initialize with max size
	char* argv[80];			    //initialize char arrary pointer 

	while(1){
		printf("mini-shell->");          //shell prompt
		fgets(line, MAX_BUF_SZ, stdin);  //read in command line with max buffer restraint
		if (isspace(line[0])){           //logic to detect whitespace and pass in while loop
			;
		}
		
		else if (line[1] != '\0'){  //execute if line is not empty
		parse(line, argv); //tokenize command line
		
		int i,j,k; //counter variables
	
		char *argvLeft[80]; //declare left char array before pipe
		char *argvRight[80]; //declare right char array after pipe
		for(j=0; argv[j] != '\0'; j++){    //124 is ascii representation of pipe
			if(*argv[j] != 124){       //iterate through command until pipe
				argvLeft[j] = argv[j];   //store before pipe into argvLeft		
			}
			else{
				j++;
				for(k=0; argv[j] != '\0'; k++){  //store after pipe into argvRight
					argvRight[k] = argv[j];
					j++;
				}
				break;
			}
		}
		
		/*                                       //print tokens 	
		for(i=0; argvLeft[i] != '\0'; i++){
			printf("%s\n", argvLeft[i]);
		}	
		for(i=0; argvRight[i] != '\0'; i++){
			printf("%s\n", argvRight[i]);
		}
		*/
		if(argvRight[0] != NULL){ //if pipe exists then that means 
			pid_t pid2, pid3; //create process id 
			int mypipe[2];    //file desriptor for mypipe
			int status;
			pipe(mypipe);     //create a pipe    
			pid2 = fork();    //spawn a new process

			if (pid2==0){     //if pid2 is child
				dup2(mypipe[0], 0); //open write end of pipe and close read end
				close(mypipe[1]);   // close pipe
				execvp(argvRight[0], argvRight); //execute command for right of pipe
				exit(1);  //exit child
			}
			pid3 = fork();   //create second process and execute command for left of pipr
			if (pid3 == 0){
				dup2(mypipe[1], 1); 
				close(mypipe[0]);
				execvp(argvLeft[0], argvLeft);
				}
	
			close(mypipe[0]); //close both ends of pipe
			close(mypipe[1]);
			waitpid(pid2); //wait for processs to finish and then exit
			waitpid(pid3);
			
			i = 0;                           //clear argvLeft
			while(argvLeft[i] != '\0'){
				argvLeft[i] = '\0';
				i++;
			}
			j = 0;                           //clear argvRight
			while(argvRight[j] != '\0'){
				argvRight[j] = '\0';
				j++;
			}
		}		
		else{
			if (strcmp(argv[0],"exit") == 0){ exit(0);} //if command is exit, exit()
			else if (strcmp(argv[0],"help") == 0){ help();} //triggers help menu
			else if (strcmp(argv[0],"guessgame") == 0){ guessgame();} //triggers guessgame	 
			else if (strcmp(argv[0],"cd") == 0){ foo_cd(argv[1]);} //triggers built in cd 
			else{execute(argv);} //execute command 
			i = 0;                         //clear argvLeft and argvRight
			while(argvLeft[i] != '\0'){
				argvLeft[i] = '\0';
				i++;
			}
			j = 0;
			while(argvRight[j] != '\0'){
				argvRight[j] = '\0';
				j++;
			}
		}	
	
			i = 0;
			while(argvLeft[i] != '\0'){
				argvLeft[i] = '\0';
				i++;
			}
			j = 0;
			while(argvRight[j] != '\0'){
				argvRight[j] = '\0';
				j++;
			}
			k = 0;
			while(argv[k] != '\0'){
				argv[k] = '\0';
				k++;
			}

		}
	}	
	free(argv);
	free(line);
	return 0;	
}
