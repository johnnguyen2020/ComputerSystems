// Now modify your program to swap two long's.
//
//
#include <stdio.h>

int main(){
	long a = 10;
	long b = 20;
	long temp = a;
	printf(" a is %ld and b is %ld ", a,b);
	a = b;
	b = temp;
	printf("After swap a is %ld and b is %ld ", a,b);

}
