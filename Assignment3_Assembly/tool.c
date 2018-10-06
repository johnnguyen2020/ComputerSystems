// Implement your cycle count tool here.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Create array of strings
const char *strings[] = {"add", "sub", "mul", "div", "mov", "lea", "push", "pop", "ret"};
//Length of array equation using 
int len = sizeof(strings)/sizeof(strings[0]);

//arguments allow command line input to be specified which is file to be parsed
int main(int argc, char *argv[]){
	if (argc != 2) return 1; //if no argument than exit loop
	//Create file index buffer
	FILE* filePointer;
	filePointer = fopen(argv[1], "r"); //open file inputed in commad as read only 
	char singleLine[400];             //max size of single line

	if (filePointer == NULL) return 1;   //if no file inputted, exit
	int i;
	int cycle =0;       //variable to count number instructions       
	int cycleAdd=0;    //variable to count individual cycles
	int cycleSub=0;
	int cycleMul=0;
	int cycleDiv=0;
	int cycleMov=0;
	int cycleLea=0;
	int cyclePush=0;
	int cyclePop=0;
	int cycleRet=0;
	int count = 0;   //variable to count total cycles
	while(!feof(filePointer)){  //until end of file
		fgets(singleLine, 400, filePointer); //read in line by lin	
		for(i = 0; i <len; i++){             //for loop for all instructions
			if (strstr(singleLine, strings[i]) != NULL){        //make sure line is not NULL condition
				count +=1;  //increment number instructions
				if (i==0) {cycle +=1; cycleAdd+=1;}        //add         using intel pentium instruction set
				else if (i==1) {cycle +=1; cycleSub +=1;}  //sub
				else if (i==2) {cycle +=11; cycleMul +=1;} //mul
				else if (i==3) {cycle +=17; cycleDiv +=1;} //div
				else if (i==4) {cycle +=1; cycleMov +=1;}  //mov
				else if (i==5) {cycle +=1; cycleLea +=1;}  //lea
				else if (i==6) {cycle +=1; cyclePush +=1;} //push 
				else if (i==7) {cycle +=1; cyclePop +=1;}  //pop
				else if (i==8) {cycle +=1; cycleRet +=1;}  //ret
			} 
		} 
	}
	fclose(filePointer);
	//printf(" ADD %d\n SUB %d\n MUL %d\n DIV %d\n MOV %d\n LEA %d\n PUSH %d\n POP %d\n RET%d\n",
		// cycleAdd, cycleSub, cycleMul, cycleDiv, cycleMov, cycleLea, cyclePush, cyclePop, cycleRet);
	if(cycleAdd != 0) {printf("ADD %d\n", cycleAdd);}   //prunt variable findings
	if(cycleSub != 0) {printf("SUB %d\n", cycleSub);}
	if(cycleMul != 0) {printf("MUL %d\n", cycleMul);}
	if(cycleDiv != 0) {printf("DIV %d\n", cycleDiv);}
	if(cycleMov != 0) {printf("MOV %d\n", cycleMov);}
	if(cycleLea != 0) {printf("LEA %d\n", cycleLea);}
	if(cyclePush != 0) {printf("PUSH %d\n", cyclePush);}
	if(cyclePop != 0) {printf("POP %d\n", cyclePop);}
	if(cycleRet != 0) {printf("RET %d\n", cycleRet);}
	printf("Total instructions = %d\n", count);
	printf("Total cycles = %d\n", cycle);
	//print("%s\n ", strings[0]);
	//printf("%s\n ", strings[7]);
	return 0;
}



















