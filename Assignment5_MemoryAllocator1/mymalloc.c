#include <string.h>
#include <sys/types.h>
#include <unistd.h>

struct block_meta{
    size_t size;
    struct block_meta *next;
    int free;
    //int magic;
};

typedef struct block_meta block_meta_t; //defined variable type
#define META_SIZE sizeof(block_meta_t)  //define size of meta struct

void *global_base = NULL;               //head for linked list

/*
//function finds available free space, the allocate space if not possible
//returns pointer to current start of region on heap
block_meta_t *find_free_block(block_meta_t **last, size_t size) {
    block_meta_t *current = global_base;
    while (current && !(current->free && current->size >= size)) {
        *last = current;
        current = current->next;
    }
    return current;
}
*/


block_meta_t *find_free_block(block_meta_t **block, size_t size){
    block_meta_t *currentBlock = global_base;
    block_meta_t *tempBlock = NULL;

    while (currentBlock) {
        if (currentBlock->free && currentBlock->size >= size){
            if (tempBlock == NULL){
                tempBlock = currentBlock;
            }
            else if (currentBlock->size < tempBlock->size){                                                                
                // *block = currentBlock;
                tempBlock = currentBlock;                                                        
            }                     
        }    
        *block = currentBlock;
        currentBlock = currentBlock->next;
    }  

    if (tempBlock == NULL){
        return currentBlock;
    }
    else{
        return tempBlock; 
    }
}

//function requests space from system using sbrk and appends new space to end of linked list
block_meta_t *request_space(block_meta_t* last, size_t size) {
    block_meta_t *block;
    block = sbrk(0); //block = pointer to cuurent data segment break addresss
    void *request = sbrk(size + META_SIZE); //allocates space for meta information
    //assert((void*)block == request); // Not thread safe.
    if (request == (void*) -1) {
        return NULL; // sbrk failed.            
    }

    if (last) { // NULL on first request.
        last->next = block;
    }
    block->size = size;
    block->next = NULL;
    block->free = 0;
    //block->magic = 0x12345678;
    return block;
}

//mymalloc uses helper functions to check and request space
void *mymalloc(size_t size) {
      //printf("%zu \n", size);
      block_meta_t *block; 
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
        block_meta_t *last = global_base;
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
            //block->magic = 0x77777777;
        }           
    }
    //printf("%p \n", block);
    return(block+1); //Return pointer to region after meta info
}


//data type to return address of block_meta_t ptr
block_meta_t *get_block_ptr(void *ptr){
    return (block_meta_t*)ptr -1;
}

//Free is passed a pointer that is previously returned from my malloc
void myfree(void * ptr){
    if(!ptr){
        return; //free can be called on NULL but program just returns
    }
    block_meta_t* block_ptr = get_block_ptr(ptr);
    block_ptr->free = 1;
    //block_ptr->magic = 0x55555555;
}

//takes in number elements to allocate and size of each element
//Iniltializes all of elements bits to 0
void *mycalloc(size_t nmemb, size_t size){
    size_t s = nmemb * size;
    void *ptr = mymalloc(s);
    memset(ptr, 0 , s);
    return ptr;
}












