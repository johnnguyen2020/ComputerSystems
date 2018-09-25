// =================== Support Code =================
// Stack
//
//
//
// - Implement each of the functions to create a working stack.
// - Do not change any of the function declarations
//   - (i.e. stack_t* create_stack() should not have additional arguments)
// - You should not have any 'printf' statements in your stack functions. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYSTACK_H
#define MYSTACK_H
#include <stdlib.h>
#include <stdio.h>

// Stores the maximum 'depth' of our stack.
// Our implementation enforces a maximum depth of our stack.
# define MAX_DEPTH 32

// Create a node data structure to store data within
// our stack. In our case, we will stores 'integers'
typedef struct node{
	int data;
	struct node_t* next;
}node_t;

// Create a stack data structure
// Our stack holds a single pointer to a node, which
// is a linked list of nodes.
typedef struct stack{
	int count;		// count keeps track of how many items
				// are in the stack.
	unsigned int capacity;	// Stores the maximum size of our stack
	node_t* head;		// head points to a node on the top of our stack.
}stack_t;

// Creates a stack
// Returns a pointer to a newly created stack.
// The stack should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The stacks fields should also be initialized to default values.
stack_t* create_stack(unsigned int capacity){
	// Modify the body of this function as needed.
	stack_t* myStack = NULL;                       //create myStack and initialize data members
	myStack = (stack_t*)malloc(sizeof(myStack));
	myStack->count = 0;
	if(capacity > MAX_DEPTH){                     //logic for est. max_depth if capcity inputted is too high
		myStack->capacity = MAX_DEPTH;
	}
	else{
		myStack->capacity = capacity;
	}
	myStack->head = NULL;
	return myStack;
}

// Stack Empty
// Check if the stack is empty
// Returns 1 if true (The stack is completely empty)
// Returns 0 if false (the stack has at least one element enqueued)
int stack_empty(stack_t* s){
	if (s->count == 0){          //true if count of stack is 0
		return 1;
	}
	else{
		return 0;
	}
}

// Stack Full
// Check if the stack is full
// Returns 1 if true (The Stack is completely full, i.e. equal to MAX_DEPTH)
// Returns 0 if false (the Stack has more space available to enqueue items)
int stack_full(stack_t* s){	
	if (s->count == s->capacity){        //true if count of stack is capacity
		return 1;
	}
	else{
		return 0;
	}
}

// Enqueue a new item
// i.e. push a new item into our data structure
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. if the Stack is full that is an error, but does not crash the program).
int stack_enqueue(stack_t *s, int item){
	if (stack_full(s) == 0){    //if stack is not full
		s->count++;         //increment the size by 1
		node_t* stackNode = NULL;       //create new node to be added
		stackNode = (node_t*) malloc(sizeof(node_t));
		stackNode->data = item;    //new node stores data inputted
		stackNode->next = NULL;    //new node is now the head and points to NULL
		if(s->head == NULL){       //old head checks then head is update to new node 
			s->head = stackNode;
		}
		else{                       //otherwise list is traversed until last eleemnt and the tempNode points to the new node                                 			
			node_t* tempNode = s->head;
			while(tempNode->next != NULL){             //traverse condition until last element 
				tempNode = (node_t*) tempNode->next;
			}
			tempNode->next = (void*) stackNode;
		}
		return 0;
	}
	else{
		return -1; // Note: you should have two return statements in this function.
	}
}

// Dequeue an item
// Returns the item at the front of the stack and
// removes an item from the stack.
// Removing from an empty stack should crash the program, call exit(1).
int stack_dequeue(stack_t *s){
	if (stack_empty(s) == 0 && s->count==1){ //if stack is not empty and there is one element
		s->count--;                      //decrment by one for removal 
		node_t* temp = s->head;          //delete the head and use next to make head point to next
		free(s->head);
		int item = temp->data;	
		return item;                     //return data removed
	} 
	else if (stack_empty(s) == 0 && s->count>1){ //if not empty and stack is greater than one
		s->count--;                          //decrment by one 
		node_t* tempNode = s->head;          //set temp to head of list 
		node_t* temp;                        //temp is used to track of node before its deleted
		while(tempNode->next != NULL){
			temp = tempNode;            //while temp is not null, iterate and update net data member           
			tempNode = (node_t*) tempNode->next;
		}
		int item = tempNode->data; //once tracked to last element, return data item
		free(temp->next);         //free and set temp to NULL
		temp->next = NULL;
		return item;
	}
	else{
		exit(1); // Note: This line is a 'filler' so the code compiles.
	}
}

// Stack Size
// Queries the current size of a stack
// A stack that has not been previously created will crash the program.
// (i.e. A NULL stack cannot return the size)
unsigned int stack_size(stack_t* s){
	if(s != NULL){                  //if s is created, return number of elements 
		return s->count;
	}
	else{
		return 0;
	}
}

// Free stack
// Removes a stack and ALL of its elements from memory.
// This should be called before the proram terminates.
void free_stack(stack_t* s){
	node_t* tempNode = s->head;           //create 2 node_t for tracking head and next node       
	node_t* nextNode = NULL;
	while(tempNode->next != NULL){               //while head does not point to NULL
		nextNode = (void*) tempNode->next;   //next node becomes pointer to head
		free(tempNode);                      //frees tempNode to update head to next  node to be deleted 
		tempNode = nextNode;
	}
	free(s);
}




#endif
