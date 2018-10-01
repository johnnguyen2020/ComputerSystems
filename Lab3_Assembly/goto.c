// Write a C program using the goto command and a label.
#include <stdio.h>
#include <stdlib.h>

int main(){
	int num = 35;
	if (num%2 == 0)
		goto even;
	else
		goto odd;

	even:
		printf("Num is even");
	odd:
		printf("Num is odd");
 
	return 0;



}



















