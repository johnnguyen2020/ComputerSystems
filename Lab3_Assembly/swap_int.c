// Write a C program that swaps two integers(in the main body of code).

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
	int* temp;
	temp = a;
	a = b;
	b = temp;
}	
	

int main(){
	int a =10;
	int b =20;
	printf( "a is %d and b is %d ", a, b);
	int temp = a;
	a = b;
	b = temp;
	printf( "After swap a is %d and b is %d ", a, b);

}
