// Write a C program that swaps two integers in a function

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int*b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


int main(){
	int a = 10;
	int b = 20;
	int* x = &a;
	int* y = &b;
	printf(" a is %d and b is %d\n",a,b);
	swap (&a,&b);
	printf("After swap, a is %d and b is %d\n",a,b);

}

















