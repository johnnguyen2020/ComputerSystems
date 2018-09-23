// Modify this file
// compile with: gcc linkedlist.c -o linkedlist
//source: http://www.zentut.com/c-tutorial/c-linked-list/


#include <stdio.h>
#include <stdlib.h>

//function prototypes
int print_list();
int free_list();

// Create your node_t type here
typedef struct node{
	int myData;
	struct node* next;
}node_t; 


node_t* prepend(node_t* head, int data);

// Write your functions here
// There should be 1.) create_list 2.) print_list 3.) free_list
// You may create as many helper functions as you like.
//
// Creare_list reads in data and then prints and frees te=he linked list
int create_list(){
	//Read in File
	//FILE is struct that holds file info
	node_t* head;
	FILE *filePointer;
	filePointer = fopen("data.txt", "r");

	int buffer;
	int i = 0;
	while(!feof(filePointer)){
		i+=1;
		fscanf(filePointer, "%d", &buffer);
		//printf( " %p ", *head);
		//printf("I read %d\n", buffer);
		head = prepend(head, buffer);
	}

	print_list(head);
	free_list(head);
	return 0;
}

//Function to traverse the linked list and print all the myData data members
//Conditionals decribe what kind of bitcoin day it was
int print_list(node_t* node ){ 
	while (node != NULL){
	printf(" %d ", node->myData);
	if (node->myData >5000 ){
	printf(" It is a good bitcoin day \n");
	}
	else if (node->myData<4000){
	printf(" It is a bad bitcoin day \n");
	}
	else{
	printf(" It is an okay bitcoin day \n");
	}
		
	node = node->next; 
	}
	return 0;
}

//free linkedlist memory allocated using temp var swap
int free_list(node_t* head){
	node_t* temp;
	while (head != NULL)
	{
	temp = head;
	head = head->next;
	free(temp);
	}
	return 0;
}

//prepend function inserts new data at the head of the linked list
//The tail of the linked list is NULL
node_t* prepend(node_t* head, int data){
	node_t* new_node = (node_t*) malloc(sizeof(node_t));
	new_node->myData = data;
	new_node->next = head;
	//printf(" %d ",new_node->myData);
	head = new_node;
	return head;
}

//Main Program creates linked list from data.txt file
int main(){
	//Read in File
	//FILE is struct that holds file info
	create_list();
    return 0;
}
