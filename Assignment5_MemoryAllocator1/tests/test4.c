#include <stdio.h>
#include <malloc.h>


int main(){

      int* data =  (int*)malloc(8);    
      int* data1 = (int*)malloc(8);
      int* data2 = (int*)malloc(16);
      free(data2);
      int* data3 = (int*)malloc(8);
      int* data4 = (int*)malloc(8);
      
      free(data);
      free(data1);
      //free(data2);
      free(data3);
      free(data4);

  return 0;
}
