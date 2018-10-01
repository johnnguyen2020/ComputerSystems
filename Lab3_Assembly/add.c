// Write a C program that calls an add function(long add(long a, long b).

#include <stdio.h>
#include <stdlib.h>

long add_function(long x, long y){
	long z = x+y;
	return z;
}

int main(){
	long a = 33;
	long b =245;
	printf("Sum is %ld ", add_function(a,b));
	return 0;
}












