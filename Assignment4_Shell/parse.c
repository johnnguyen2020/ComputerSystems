//Implement a working parser in this file that splits text into individual tokens.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//parseString takes char array and tokenizes
void parseString(char str[]){
	char * p_commandLine; //temp holds each token
	p_commandLine = strtok (str, " \t\r\n\a"); //find first token
	while (p_commandLine != NULL) //iterate until NULL since strtok implements terminating NULL
	{
		printf("%s\n", p_commandLine);
		p_commandLine = strtok (NULL, " \t\r\n\a");
	}
	return;
}

int main(int argc, char* argv[]){
	if (argc != 2) {return 1;} //if no argument then exit
	parseString(argv[1]);  //call function
	return 0;
}
































