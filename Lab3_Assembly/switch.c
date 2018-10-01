// Write a C program using a switch statement
#include <stdio.h>
#include <stdlib.h>

int main(){
	int grade = 100;
	switch(grade){
		case 100:
			printf("Excellent");
			break;
		case 90:
			printf("Good");
			break;
		case 80:
			printf("OK");
			break;
		case 70:
			printf("Poor");
			break;
		case 60:
			printf("Fail");
			break;
		default:
			printf("Invlaid Grade");

	}


	return 0;
}




