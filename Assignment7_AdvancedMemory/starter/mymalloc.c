#define _GNU_SOURCE 
#include <string.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <sched.h>
#include <pthread.h>
#include <stdlib.h>

// Structure that holds the blocks of memory
struct block{
    	size_t size; // How many bytes beyond this block have been allocated in the heap
    	struct block *next; // Where is the next block
    	int free; // Is this memory free?
	    int cpu; // Cpu that the memory block belongs to
};

typedef struct block block_t; // Structure block defined as block_t
#define BLOCK_SIZE sizeof(block_t)  // Define size of block_t struct

//#define numProcs get_nprocs();


static void *global_base;
static pthread_mutex_t global_mutex_lock;

static int boolean = 1;
void init_malloc(){
    int cpuCount = get_nprocs();
    
    //static void *global_base;
    global_base = (void*)malloc(sizeof(void)*cpuCount);
    //pthread_mutex_t global_mutex_lock
    global_mutex_lock = (pthread_mutex_t)malloc(sizeof(pthread_mutex_t)*cpuCount);
    boolean = 0;
}


//void *global_base[32] = {NULL}; // Head for linked list of memory addresses initialized as NULL
//pthread_mutex_t global_mutex_lock[32];


block_t *split(void *block, size_t size, int cpuNum){
        printf("Enter split\n");
        void *pointer = block + BLOCK_SIZE + size;
	    block_t *newPointer = (block_t*)pointer;
	    block_t *newBlock = (block_t*)block;
	    ((block_t*)block)->size = size;
        newPointer->size = newBlock->size - (size + BLOCK_SIZE);
        newPointer->next = NULL;
        newPointer->free = 1;
        newPointer->cpu = cpuNum;
        newBlock->size = size;
        return newPointer;
}

void list_add(block_t *block, int cpuNum){
	    //int cpuNum;
	    if ((cpuNum = sched_getcpu()) < 0){
		    return;
	    }

        block_t *currentBlock = global_base[cpuNum]; 
        while(currentBlock->next) {
                currentBlock = currentBlock->next; // Loop continues and the current block is now the next block of memory      
        }   
        currentBlock->next = block; 
}

// find_free_block_best_fit finds the smallest already allocated free block that is large enough to fit data of an input size
block_t *find_free_block_best_fit(block_t **block, size_t size, int cpuNum){
	block_t *currentBlock = global_base[cpuNum]; // Initializes a pointer to the current block, used to loop through all available memory spaces
    	block_t *tempBlock = NULL; // Initializes a pointer to hold the best fitting block of memory for the requested malloc

    	while (currentBlock) {  // Loops through every memory block that has been allocaed to the memory segment
        	if (currentBlock->free && currentBlock->size >= size && currentBlock->cpu == cpuNum){
            		if (tempBlock == NULL){ // Entered if the tempblock is null, so it has not yet been given a best-fit space
                		tempBlock = currentBlock; // The best-fit holder points to the current block
            		} else if (currentBlock->size < tempBlock->size){ // Entered if the current block is smaller than the best fit in terms of size, but also large enough
                		tempBlock = currentBlock; // The best-fit holder points to the current block, which is the new best fit
            		}                     
        	}    
        
		*block = currentBlock;  // The block now points to the current block (will become the previous block on next loop)
        	currentBlock = currentBlock->next; // Loop continues and the current block is now the next block of memory
    	}  

    	if (tempBlock == NULL){ // Enters if the tempBlock is null, meaning no memory block was found for the data 
        	return currentBlock; // The current block is returned
    	} else{ // Enters if the tempblock is not null, meaning a memory block was found for the data
		if (tempBlock->size > size) {
			block_t *newPointer = split(tempBlock, size, cpuNum);
			list_add(newPointer, cpuNum);
		}
        	return tempBlock; // The best fit memory block is returned
    	}
}

// get_space requests more dynamically allocated space from the system, uses sbrk to move data segment break address
block_t *get_space(block_t *lastBlock, size_t size, int cpuNum) {
    	block_t *block; // Block that will point to the current data segment break address
    	
	if (size <= 4096) {
		block = sbrk(0); // Block pointer to current data segment break addresss
    		void *request = sbrk(size + BLOCK_SIZE); // Allocates space for meta information
    		if (request == (void*) -1) {
        		return NULL; // sbrk failed and null is returned            
    		}

    		if (lastBlock) { // NULL on first request.
        		lastBlock->next = block;
    		}
	} 
    else if(size >4096) {
        //block=sbrk(0);
		void *block_m;
		if ((size + BLOCK_SIZE) % 4096 == 0){
			int numPages = (size + BLOCK_SIZE) / 4096;
			block_m = mmap(0, numPages, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
			//block->size = numPages * 4096;
		} 
        else {
			printf("Here\n");
			int numPages = (size + BLOCK_SIZE) / 4096 + 1;
            block_m = mmap(0, numPages, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
			//block->size = numPages * 4096;
		}
		printf("Here2\n");
		block_t *newPointer = split(block_m, size, cpuNum);
		printf("Here3\n");
		list_add(newPointer, cpuNum);
        printf("Here4\n");

        block = block_m;
	

	    if (lastBlock) { // NULL on first request.
		    lastBlock->next = block;
        }
    }
	    block->size = size; // The block size is set to size
        printf("KindaReturned \n");
    	block->next = NULL; // The next block is set to null
        printf("KindaReturned2 \n");
    	block->free = 0; // The block is marked not free
        printf("KindaReturned3 \n");
	    block->cpu = cpuNum;
        printf("BlockReturned \n");
    	return block; // The memory block is returned
}


// mymalloc allocates memory of size size dynamically on the heap
void *mymalloc(size_t size) {
    if (boolean){
        init_malloc();
    }
    
    if (size <= 0) { // Entered if 0 or less space is trying to be allocated
   	     return NULL; // In this case, NULL is returned.               
      	}

	int cpuNum;// = sched_getcpu();
	if ((cpuNum = sched_getcpu()) < 0){
		return NULL;
	}

    pthread_mutex_lock(&global_mutex_lock[cpuNum]);
		
	block_t *block;
    	if (!global_base[cpuNum]) { // If the global_base is null, no space has been allocated yet so space needs to be requested by sbrk
        	block = get_space(NULL, size, cpuNum); // Space is allocated to accomodate data of size size
        	if (!block) { // If the returned block from get_space is null, null is returend by malloc
                    pthread_mutex_unlock(&global_mutex_lock[cpuNum]);
            		return NULL;              
        	}
        	global_base[cpuNum] = block; // The global base is now reset to the new base, which is the memory block that was just allocated
        } 
        else { // If the global_base pointer is not NULL, the program will attempt to find space that has beeen freed to re-use
        	block_t *lastBlock = global_base[cpuNum]; // Holds the last used block that was allocated
	        block = find_free_block_best_fit(&lastBlock, size, cpuNum); // Searches for a free block of memory
        	if (!block) { // Enters if no free blocks were found
            		block = get_space(lastBlock, size, cpuNum); // More space is requested by calling get_space which uses sbrk
	                if (!block) { // If get_space returned null, mymalloc returns null
                        pthread_mutex_unlock(&global_mutex_lock[cpuNum]);
		                return NULL;
            		}
        	} else { // Enters if more space was successfully allocated
            		block->free = 0; // The memory block that was allocated is marked as not free
			block->cpu = cpuNum;
	        }           
    	}
	
	printf("malloc %zu bytes\n", size);
	
	return (block+1); // Return pointer to region after meta info that holds memory block size
}

// get_block_pointer returns the memory address where the memory block passed in (via a pointer to the second spot of its memory) is located
block_t *get_block_ptr(void *ptr){
	return (block_t*)ptr - 1; // Returns the address of the beginning of the memory block passed in (originally one space over from the beginning is pointed to)
}

// myfree sets free the block of memory pointed to by the pointer input
void myfree(void * ptr){
	int cpuNum;// = sched_getcpu();
	if ((cpuNum = sched_getcpu()) < 0){
		return;
	}
	 
    if(!ptr){ // Entered if the pointer is null and no memory space is being pointed to
        	return; // If no memory is pointed to, the function just returns
    	}
    	
	block_t* block_ptr = get_block_ptr(ptr); // Gets the pointer to the beginning of the memory block (pointer passed in points to one space over from the beginning)
	
	printf("Freed %zu bytes\n", block_ptr->size);

    	block_ptr->free = 1; // The free member of the memory block is set to 1, meaning the memory is free
}

// mycalloc allocates memory and initializes the spaces to 0. It takes in the number of members and the size of each member.
void *mycalloc(size_t nmemb, size_t size){
    	size_t totalSize = nmemb*size; // The total size of the memory block is calculed by multiplying the number of members by their individual size
    	void *ptr = mymalloc(totalSize); // mymalloc is called to allocate enough space for the new data
    	memset(ptr, 0 , totalSize); // memset sets takes the pointer to the start of the block and sets 
				    // totalsize number of spaces (the number that was calculated) equal to zero
	
	printf("calloc %zu bytes\n", totalSize);
    	
	return ptr; // The pointer to the memory block is returned
}
