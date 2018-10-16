// Modify this file for your assignment
#include <stdio.h>
#include <stdlib.h>
#include <signal.h> // This is new!
#include <unistd.h> 
#include <string.h>
#include <sys/types.h>
#include <time.h>


const int MAX_BUF_SZ = 80;
char str_exit[4];

// Create a signal handler
void sigint_handler(int sig){
	// Ask yourself why 35?
	write(1,"mini-shell terminatd\n",21); 
	exit(0);
}


void parse(char *line, char ** argv){
	/*
	while (*line != '\0'){
		while (*line == ' ' || *line == '\t' || *line == '\n')
			*line++ = '\0';
			*argv++ = line;
		while (*line != '\0' && *line != ' ' && *line != '\t' && *line != '\n')
			line++;
	}
	*argv = '\0';
	*/
	int i = 0;
	//char * argv[80];
	char * token;
	token = strtok(line," \t\r\n\a");
	while (token != NULL){
		argv[i] = token;
		i++;
		token = strtok(NULL, " \t\r\n\a");
	}
	argv[i] = '\0';
}

void execute(char **argv){
	pid_t pid;
	int status;

	if((pid = fork()) < 0){
		printf("Command not found\n");	
		exit(1);
	}
	
	else if(pid == 0){
		if (execvp(*argv, argv)<0){
		printf("Command not found\n");	
		exit(1);
		}
		else
		{printf("hi");}
	}

	else{
		while (wait(&status) != pid);
	}
}

void foo_cd(char *d)
{
	if (chdir(d) != 0){
		perror("error");
	} 
}



int help(){
	printf("HERE IS HELP MANUAL\n");
	printf("Builtin command:help -->displays help guide\n");
	printf("Builtin command:exit -->exits mini shell\n");
	printf("Builtin command:guessgame -->starts guessing game\n");
	printf("\tTry to select the correct number between 1-100\n");
	printf("Builtin command: cd -->change directories\n");
	return 0;	
}

void guessgame(){
	printf("Welcome to Guessing Game\n");
	int random_num = 0;
	int guess_num = 0;
	int counter = 0;

	srand(time(NULL));
	random_num = rand() % 100 + 1;
	printf("Guess a number from 0 to 100! ");
	
	while(1){
		counter++;
		scanf("%d", &guess_num);
		if (guess_num == random_num)
		{
			printf("Congrats, %d is the winning number!\n", random_num);
			printf("You guess correctly in %d attempts\n", counter);
			break;
		}
		if (guess_num < random_num)
			printf("Your guess is too low. Guess again. ");
		if (guess_num > random_num)
			printf("Your guess is too high. Guess again. ");
	}
}

int main(){
	
	strcpy(str_exit, "exit");
	// Install our signal handler
	signal(SIGINT, sigint_handler);

	//printf("You can only terminate by pressing Ctrl+C\n");
	char line[MAX_BUF_SZ];
	
	char* argv[80];
	
	char* path= "/bin/";
	char progpath[20];
	int argc; 

	while(1){
		printf("mini-shell->");
		//fgets(commandLine, MAX_BUF_SZ, stdin);
		//printf("%s\n", commandLine);
		//printf("%s\n", str_exit);
		//printf("%d\n", strcmp(commandLine, str_exit));
		//if (strcmp(commandLine,str_exit) == 10){ exit(0);}
		//execvp(argv[0], argv);

		/*
		char *token;
		token = strtok(commandLine, " ");
		int i = 0;
		while (token != NULL){
			argv[i] = token;
			//token = strtok(NULL, " ");
			i++;
		}
		argv[i] = NULL;
		argc = i;
		
		for(i = 0; i <argc; i++){
			printf("%s\n", argv[0]);
		}
		*/
		//fgets(line, MAX_BUF_SZ, stdin);
		//printf("\n");
		fgets(line, MAX_BUF_SZ, stdin);
		if (*line != '\0'){
		parse(line, argv);
		
	        
		int i;	
		for(i=0; argv[i] != '\0'; i++){
			printf("%s\n", argv[i]);
			//printf("hi\n");
		}

		int j;
		int k;
		char *argvLeft[80];
		//argvLeft = (char*)malloc(MAX_BUF_SZ*sizeof(char));
		char *argvRight[80];
		//argvRight = (char*)malloc(MAX_BUF_SZ*sizeof(char));
		for(j=0; argv[j] != '\0'; j++){
			if(*argv[j] != 124){
				argvLeft[j] = argv[j];
			
			}
			else{
				j++;
				for(k=0; argv[j] != '\0'; k++){
					argvRight[k] = argv[j];
					printf("pipe detect\n");
					j++;
				}
				break;
			}
		}
		
		/*
		for(i=0; argvLeft[i] != '\0'; i++){
			printf("%s\n", argvLeft[i]);
			//printf("hi\n");
		}	
		for(i=0; argvRight[i] != '\0'; i++){
			printf("%s\n", argvRight[i]);
			//printf("hi\n");
		}
		*/

		if(argvRight[0] != NULL){
			pid_t pid2;
			int mypipe[2];
			pipe(mypipe);
			pid2 = fork();

			if (pid2==0){
				dup2(mypipe[0], 0);
				close(mypipe[1]);
				execvp(argvRight[0], argvRight);
				exit(1);
			}
			else{
				dup2(mypipe[1], 1);
				close(mypipe[0]);
				execvp(argvLeft[0], argvLeft);
			}
		}		
		else{
			if (strcmp(argv[0],"exit") == 0){ exit(0);}
			else if (strcmp(argv[0],"help") == 0){ help();}
			else if (strcmp(argv[0],"guessgame") == 0){ guessgame();}	
			else if (strcmp(argv[0],"cd") == 0){ foo_cd(argv[1]);}
			else{execute(argv);}
		}
		}
		}

	return 0;	
}

















