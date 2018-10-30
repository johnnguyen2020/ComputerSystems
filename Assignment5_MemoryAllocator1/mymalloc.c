#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

//Data struct to hold block info
struct block{
    size_t size;
    struct block *next;
    int free;
};

typedef struct block block_t; //defined variable type
#define META_SIZE sizeof(block_t)  //define size of meta struct

void *global_base = NULL;               //head for linked list

/*
//first fit function to find available free space, the allocate space if not possible
//returns pointer to current start of region on heap
block_t *find_free_block(block_t **last, size_t size) {
    block_t *current = global_base;
    while (current && !(current->free && current->size >= size)) {
        *last = current;
        current = current->next;
    }
    return current;
}
*/

//function finds best fit memory space meaning the memory allocated yields the 
//fewest remaining bits, function takes in block type and size of element
block_t *find_free_block(block_t **block, size_t size){
    block_t *currentBlock = global_base; //initialize current pointer
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
        return tempBlock; //return start of best fit data segment pointer
    }
}

//function requests space from system using sbrk and appends new space to end of linked list
block_t *request_space(block_t* last, size_t size) {
    block_t *block;
    block = sbrk(0); //block = pointer to cuurent data segment break addresss
    void *request = sbrk(size + META_SIZE); //allocates space for meta information
    //assert((void*)block == request); // Not thread safe.
    if (request == (void*) -1) {
        return NULL; // sbrk failed.            
    }

    if (last) { // NULL on first request.
        last->next = block;
    }
    block->size = size; //reallocate size
    block->next = NULL; //point to NULL
    block->free = 0;    //set not free 
    return block;
}

//mymalloc uses helper functions to check and request space
void *mymalloc(size_t size) {
      //printf("malloc %zu bytes \n", size);
      block_t *block; 
      if (size <= 0) {
              return NULL;                
      }

    if (!global_base) { //If global base pointer is NULL, request space
        block = request_space(NULL, size);
        if (!block) {
            return NULL;              
        }
        global_base = block;
        } 
    else { //If base pointer is not NULL, check to re-use space
        block_t *last = global_base;
        block = find_free_block(&last, size);
        if (!block) { // Failed to find free block.
            block = request_space(last, size); //Request new space
            if (!block) {
                return NULL;
            }
        } 
        else {      // Found free block
            // TODO: consider splitting block here.
            block->free = 0;
        }           
    }
    printf("%p \n", block);
    return(block+1); //Return pointer to region after meta info
}


//data type to return address of block_t ptr
block_t *get_block_ptr(void *ptr){
    return (block_t*)ptr -1;
}

//Free is passed a pointer that is previously returned from my malloc
void myfree(void * ptr){
    if(!ptr){
        return; //free can be called on NULL but program just returns
    }
    block_t* block_ptr = get_block_ptr(ptr);
    //printf("freed %zu bytes \n", block_ptr->size); 
    block_ptr->free = 1;
}

//takes in number elements to allocate and size of each element
//Iniltializes all of elements bits to 0
void *mycalloc(size_t nmemb, size_t size){
    //printf("calloc %zu bytes \n", size);
    size_t total = nmemb * size; //find size of data segment
    void *ptr = mymalloc(total); //allocate space
    memset(ptr, 0 , total);      //set memory to 0 of size argument
    //printf("calloc %zu bytes \n", total);
    return ptr;              //return current block pointer
}












