#include <stdio.h>
#include <malloc.h>


int main(){
    
      int i = 10;

      int* data =  (int*)malloc(8);    
      int* data1 = (int*)malloc(8);
      int* data2 = (int*)malloc(16);
      free(data2);
      int* data3 = (int*)malloc(8);
      int* data4 = (int*)malloc(8);
      int* data5 = (int*)malloc(8);
      int* pData = (int*) calloc (i, sizeof(int));
      int* data6 = (int*)malloc(8);
      free(pData);

      free(data);
      free(data1);
      //free(data2);
      free(data3);
      free(data4);
      free(data5);
      free(data6);
      //free(pData);
    


/*

              int* data =  (int*)malloc(8);    
                    int* data1 = (int*)malloc(32);
                          int* data2 = (int*)malloc(16);
                                free(data1);
                                      free(data2);
                                            int* data3 = (int*)malloc(64);
                                                  int* data5 = (int*)malloc(8);    

                                                          free(data);
                                                                  free(data3);
                                                                          free(data5);
*/

  return 0;
}
