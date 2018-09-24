// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "myqueue.h"
// Note that we are locating this file
// within the same directory, so we use quotations 
// and provide the path to this file which is within
// our current directory.


// A sample test of your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.
void unitTest1(){

	queue_t* test1 = create_queue(1);
	printf("Attempting to add %d\n",1);
	queue_enqueue(test1,1);	
	printf("Removing: %d\n",queue_dequeue(test1));	

	free_queue(test1);
}

void unitTest2(){
	queue_t* test2 = create_queue(7);
	printf("Attempting to add %d\n",7);
	queue_enqueue(test2,10);	
	queue_enqueue(test2,20);	
	queue_enqueue(test2,30);	
	queue_enqueue(test2,40);	
	queue_enqueue(test2,500);	
	queue_enqueue(test2,60);	
	queue_enqueue(test2,70);	
	
	printf("Is queue empty?: %d\n",queue_empty(test2));	
	printf("Is queue full?: %d\n",queue_full(test2));	
	printf("Queue Size: %d\n",queue_size(test2));
	print_list(test2);
	free_queue(test2);
}





// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	// List of Unit Tests to test your data structure	
	unitTest2();

	return 0;
}
