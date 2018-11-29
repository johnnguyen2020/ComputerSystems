#define _GNU_SOURCE
#include <stdio.h> 
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/sysinfo.h>
#include <pthread.h>
#include <sched.h>
	

//#define PAGE_SIZE sysconf(_SC_PAGE_SIZE)
#define PAGE_SIZE 4096
	
//Block struct members  
struct block{
		size_t size; 
		struct block *next;  
		int free; 
	};

typedef struct block block_t;
#define BLOCK_SIZE sizeof(block_t)
#define MAX_CPU 100
	
void *globalBase[MAX_CPU] = {NULL};     //Lists created based on the number of cpus
pthread_mutex_t mutex[MAX_CPU]; //Mutex Locks
pthread_mutex_t sbrk_lock;


//Splitting function 
void split_block2(block_t *block, size_t size){
	size_t needSize; //init size needed variable 
		
	int leftover = (BLOCK_SIZE + size) % PAGE_SIZE; //leftover memory in block arithmetic
	if(leftover > 0){ //if exists
		needSize = ((BLOCK_SIZE + size)/PAGE_SIZE) * PAGE_SIZE  + PAGE_SIZE;
	} 
    else{
		needSize = (BLOCK_SIZE + size);
	}
		
	block_t *newBlock = (void*)block + BLOCK_SIZE + size;   //create new block
	newBlock->size = needSize - size - BLOCK_SIZE - BLOCK_SIZE;
	newBlock->next = block->next; 
	newBlock->free = 1;
	block->next = newBlock; 
	block->size = size; 
}	

void split_block(block_t *block, size_t size){
	int remain = block->size - BLOCK_SIZE - size;
	block_t* newBlock = (void*)block + size + BLOCK_SIZE;
	newBlock->size = remain;
	newBlock->free = 1;
	newBlock->next = block->next;
	block->next = newBlock;
	block->size = size;
}


//function finds best fit memory space meaning the memory allocated yields the 
//fewest remaining bits, function takes in block type and size of element
block_t *bestFit(block_t **block, size_t size){
    
	int cpuNum = sched_getcpu();	
    block_t *currentBlock = globalBase[cpuNum]; //initialize current pointer
    block_t *tempBlock = NULL;           //initialize temp pointer

    while (currentBlock) {  //while currentBlock until end of segment
        if (currentBlock->free && currentBlock->size >= size){ //if free and size can fit
            if (tempBlock == NULL){ //initial set fill tempBlock with currentBlock
                tempBlock = currentBlock;
            }
            else if (currentBlock->size < tempBlock->size){ //logic to reassign tempBlock if                                                                
                tempBlock = currentBlock;                   //there is a better fit                                     
            }                     
        }    
        *block = currentBlock;              //continue loop to end of segment             
        currentBlock = currentBlock->next;  //advance linked list node 
    }  

    if (tempBlock == NULL){   //logic to return best fit for mymalloc
        return currentBlock; 
    }
    else{
        if(tempBlock->size > size){
            //block_t *newPointer = split_block(tempBlock,size);
            split_block(tempBlock,size);
        }
        return tempBlock; //return start of best fit data segment pointer
    }
}

//Function to request soace and check if the requested space is larger than pg sz
block_t *requestSpace(block_t *oldBlock, size_t size) {
		block_t *block; 
		if (size < PAGE_SIZE) { //if the requested < page size, use sbrk
            block = sbrk(0); 
			pthread_mutex_lock(&sbrk_lock);
			void *request = sbrk(size + BLOCK_SIZE);
			pthread_mutex_unlock(&sbrk_lock);
			// Fail then return NULL
			if (request == (void*) - 1) {
				return NULL; 
			}

            if(oldBlock){
                oldBlock->next = block;
            }
		
            block->size = size; //update block 
		    block->next = NULL; 

		}
        else {
		int numPages;
		block = mmap(0, size + BLOCK_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		block->next = NULL;
		if(((size+BLOCK_SIZE) % 4096) == 0) {
			numPages = ((size+BLOCK_SIZE)/4096);
		} else {
			numPages = ((size +BLOCK_SIZE)/4096) + 1;
		}
		if(block == MAP_FAILED) {
			return NULL;
		}
		block->size = numPages * 4096;
		if (block->size > size) {
			split_block(block, size);
		} else{
			block->size = size;
			block->next = NULL;
		}

		if (oldBlock) { // NULL on first request.
                       	oldBlock->next = block;
               	}
	}
    	block->free = 0; // The block is marked not free
	return block; // The memory block is returned
}





/*        
		else { // If the requested space > page size, use mmap
			block = mmap(NULL, size+BLOCK_SIZE, PROT_WRITE | PROT_READ, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0); 
			if (block->size > size){ //is fragmented/extra space 
				split_block(block, size);
			}
		}
		
		if (oldBlock) {//if the request doesnt begin at head
			oldBlock->next = block;
		}
		
		block->size = size; //update block 
		block->next = NULL; 
		block->free = 0;
		return block;

*/

	
//Best fit allocator
void* mymalloc(size_t size){
	int cpuNum = sched_getcpu(); //find cpu num
	size_t total_size; 	
	block_t *block;
	
	//Make sure size valid
	if(size<=0){
		return NULL;
	}

	if(!globalBase[cpuNum])//check for start at head of the linked list
		{
		pthread_mutex_lock(&mutex[cpuNum]);	
		block = requestSpace(NULL, size);
		if(!block)//no free block
			{
				pthread_mutex_unlock(&mutex[cpuNum]);
				return NULL;
			}
			
	    //if free block
		globalBase[cpuNum] = block;
		//printf("malloc %zu bytes\n",size);
		
	}
    else {
		//start location in middle of the linked list
		pthread_mutex_lock(&mutex[cpuNum]);
		block_t *oldBlock = globalBase[cpuNum];
		//find best fit allocation
		block = bestFit(&oldBlock, size); 
	
	if(!block){ //if block
		block = requestSpace(oldBlock,size);
		if(!block){ //if no free block
		    pthread_mutex_unlock(&mutex[cpuNum]);
			return NULL;
		}
	} 
    else {//change free flag to not free
		block->free = 0;
	}
    }
    printf("malloc %zu bytes\n",size);
	block_t* test = globalBase[cpuNum];
	while (test != NULL){
		printf("%zu\n", test->size);
		test = test->next;
	}	
    pthread_mutex_unlock(&mutex[cpuNum]);
	return (block+1); //index 0
}	

//data type to return address of block_t ptr
block_t *get_block_ptr(void *ptr){
    return (block_t*)ptr -1;
}

//Free function 
void myfree(void *ptr){	 
	int cpuNum;  
    if((cpuNum = sched_getcpu())<0){
        return;
    }
    
    if(!ptr){
	    return;
	}

	pthread_mutex_lock(&mutex[cpuNum]); 
	block_t* block_ptr = get_block_ptr(ptr);
    block_ptr->free = 1;
	pthread_mutex_unlock(&mutex[cpuNum]);
    printf("freed %zu bytes \n", block_ptr->size); 
}

//takes in number elements to allocate and size of each element
//Iniltializes all of elements bits to 0
void *mycalloc(size_t nmemb, size_t size){
    size_t total = nmemb * size; //find size of data segment
    void *ptr = mymalloc(total); //allocate space
    memset(ptr, 0 , total);      //set memory to 0 of size argument
    printf("calloc %zu bytes \n", total);
    //printf("calloc %p bytes \n", ptr);
    return ptr;              //return current block pointer
}

