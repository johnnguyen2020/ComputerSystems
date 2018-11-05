#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>


//global array
char colors[64][64];

//global painters
#define NTHREADS 64

int counter = 0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

// Modify your paint function here
void paint(int workID){  
	printf("Artist %d is painting\n",workID);
    int k;
    for(k =0; k < 64*3; k++){
        colors[workID][k] = workID;
    }
}

//thread function to call paint
void *thread(void *vargp){
    pthread_mutex_lock(&mutex1); //lock resources
        paint(counter); //call paint
        counter = counter + 1; //increment artist counter
    pthread_mutex_unlock(&mutex1); //unlock resources
    return NULL;
}

int main(int argc, char** argv){

        pthread_t tids[NTHREADS]; //decalre 64 threads/artists
        int i,j;    //counter variables
        if (pthread_mutex_init(&mutex1, NULL) != 0)  //if failed to create Mutex lock notify user
        {
                    printf("\n mutex init failed\n");
                            return 1;                 
        }

        for(i = 0; i < NTHREADS; ++i){  //create 64 threads
            pthread_create(&tids[i], NULL, thread, NULL);
        }

        for(i = 0; i < NTHREADS; ++i){  //Join 64 threads
            pthread_join(tids[i], NULL);
        }

        pthread_mutex_destroy(&mutex1); //destroy mutex lock

        FILE *fp;                        //file output code
        fp = fopen("threads.ppm","w+");
        fputs("P3\n",fp);
        fputs("64 64\n",fp);
        fputs("255\n",fp);
        for(i =0; i < 64;i++){
            for(j =0; j < 64*3; j++){
                fprintf(fp,"%d",colors[i][j]);
                fputs(" ",fp);
            }
            fputs("\n",fp);                          
        }
        fclose(fp);

    return 0;
}



