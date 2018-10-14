//Implement a working parser in this file that splits text into individual tokens.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	if (argc != 2) return 1; //if no argument then exit
	char * commandLine;
	commandLine = argv[1];
	char * p_commandLine;
	p_commandLine = strtok (commandLine, " ");
	while (p_commandLine != NULL)
	{
		printf("%s\n", p_commandLine);
		p_commandLine = strtok (NULL, " ");
	}
	printf("hi");
	return 0;
}
































