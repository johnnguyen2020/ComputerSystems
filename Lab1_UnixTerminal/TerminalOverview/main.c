//John Nguyen
//C program power function

#include <stdio.h>

//Function initialized, takes two ints
int power(int,int);

//Main function prints up to 2 to the power of 10 and calls power function
int main(){
	printf("Power function: ");
	int i;
	for(i=0;i<=10;i++){
		printf("\n");
		printf("2 to the power of %d is %d",i, power(2,i));
	}
	printf("\n");
	return 0;
}

//Arguments are base and n (exponent)
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
	for(i =1; i<n; i++){
	result *= base;
	}
	}

	return result;
}

