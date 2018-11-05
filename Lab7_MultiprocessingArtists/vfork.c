#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>


//global array
char colors[64][64*3];

// Modify your paint function here
void paint(int workID){ 
	printf("Artist %d is painting\n",workID);
    int k;
    for(k =0; k < 64*3; k++){
        colors[workID][k] = workID;
    }
}


int main(int argc, char** argv){
        int* arr = (int*)malloc(8 *sizeof(int));
        int numberOfArtists = 64; // How many child processes do we want?
        pid_t pid;

        // main loop where we fork new threads
        int i,j;
        for(i =0; i < numberOfArtists; i++){
                // (1) Perform a fork
                pid = vfork();
		
                //(2) Make only the child do some work (i.e. paint) and then terminate.
                if (pid == 0){
			    // make child paint
                    paint(i);
                    exit(0);
		        }
                printf("Child created: %d\n", pid);
            }
        
        pid_t wpid;
        int status = 0;
        while((wpid = wait(&status)) > 0);
        
        printf("Masterpiece(vfork.ppm) is being assembled\n");
        //printf("parent is exiting(last artist out!)\n");
        free(arr);

        FILE *fp;
        fp = fopen("vfork.ppm","w+");
        //fp = fopen("threads.ppm","w+");
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
