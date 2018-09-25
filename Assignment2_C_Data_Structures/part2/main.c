// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "mystack.h"
// Note that we are locating this file
// within the same directory, so we use quotations 
// and provide the path to this file which is within
// our current directory.


// A sample test of your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.
void unitTest1(){

	stack_t* test1 = create_stack(10);
	printf("Attempting to push %d\n",1);
	stack_enqueue(test1,10);	
	stack_dequeue(test1);	
	stack_enqueue(test1,30);
	stack_enqueue(test1,40);
	stack_enqueue(test1,50);
	printf("Stack size is %d ", stack_size(test1));	
	printf("Removing: %d\n",stack_dequeue(test1));	
	//print_stack(test1);
	free_stack(test1);
}

void unitTest2(){
	stack_t* test2 = create_stack(5);
	free_stack(test2);
}
// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	// List of Unit Tests to test your data structure	
	unitTest2();

	return 0;
}
