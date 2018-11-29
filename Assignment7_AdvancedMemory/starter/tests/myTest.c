#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <malloc.h>

#define NTHREADS 100 // # of threads to spawn

char** shared_data;

void *some_thread1(int index_to_shared_data){
        char newString[1] = "A";
        shared_data[index_to_shared_data] = malloc(sizeof(char));
        shared_data[index_to_shared_data][0] = newString[0]; 
        free(shared_data[index_to_shared_data]);    
        pthread_exit(0);
}

void *some_thread2(int index_to_shared_data){
        char newString[1] = "B";
        shared_data[index_to_shared_data] = malloc(sizeof(char));
        shared_data[index_to_shared_data][0] = newString[0];
        free(shared_data[index_to_shared_data]);
        pthread_exit(0);
}

int main(){

        // (1) Malloc for some size of your shared data (i.e. how many strings will you have)
        shared_data = (char**)malloc(sizeof(char*)*NTHREADS);

        // (2) Launch some number of threads (perhaps with two or more different functions)
        pthread_t tids[NTHREADS];
    
        size_t i;
        for(i = 0; i < NTHREADS; i++){
                pthread_create(&tids[i], NULL, (void*)some_thread1, (void*)i);
                pthread_create(&tids[i], NULL, (void*)some_thread2, (void*)i);
        }   
    
        // (3) Join some number of threads
        int j;
        for(i = 0; j < NTHREADS; j++){
                pthread_join(tids[j], NULL);
        }   

        // (4) Print the results of shared data (i.e. this is done sequentially)
        int k;
        for(k = 0; k < NTHREADS; k++){
                printf("%s\n",  shared_data[k]);
        }
}



