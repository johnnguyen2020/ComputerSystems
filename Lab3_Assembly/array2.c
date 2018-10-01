// Write a C program called array2.c that has an array of 400 integers in the function of main that is dynamically allocated
#include <stdio.h>
#include <stdlib.h>


int main(){
	int* myArray = (int*)malloc(sizeof(int)*400);
	myArray[20] = 10;
	myArray[40] = 20;
	myArray[60] = 30;
	myArray[80] = 40;
	myArray[100] = 50;


return 0;
}
















