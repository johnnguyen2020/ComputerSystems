//John Nguyen
//C program power function

#include <stdio.h>

int power(int,int);

int main(){
	printf("Hello World");
	int i;
	for(i=0;i<10;i++){
		printf("\n");
		printf("%d", power(2,i));
	}
	return 0;
}

int power(int base,int n){
	int result = base;

	if(n==0){
	result = 1;
	}

	else if (n==1){
	result = base;
	}

	else{
	int i;
	for(i =1; i<=n; i++){
	result *= base;
	}
	}

	return result;
}

