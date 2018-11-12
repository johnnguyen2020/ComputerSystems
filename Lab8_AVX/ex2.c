// Simple Caeser Shift decrypt
// 
// Load the data from data2.txt. Increment all of the values by 1 then output
// the result
// 
// You will compile this source using the following:
// 
// clang -std=c11 -mavx2 ex2.c -o ex2prog
//
// Run as normal with: 
// 
// ./ex2prog
//
#include <stdio.h>
#include <immintrin.h>



// print char data
void print__m256(__m256 data){
	
	char*f = (char*)&data;
    
    printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n", 
	    f[0],f[1],f[2],f[3],f[4],f[5],f[6],f[7],f[8],f[9],f[10],f[11],f[12],f[13],f[14],f[15],
		f[16],f[17],f[18],f[19],f[20],f[21],f[22],f[23],f[24],f[25],f[26],f[27],f[28],f[29],f[30],f[31]);
}

int main(){

	FILE *filePointer; // create file pointer
        filePointer = fopen("data2.txt", "r"); //open as read only
        int buffer[32]; // buffer to read data

    	__m256i ones = _mm256_set_epi8(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1); //fill register with ones
	
	int i = 0;
        while(!feof(filePointer)){ //until end of file
		for (i = 0; i < 32; i++){
			fscanf(filePointer, "%d", &buffer[i]); //fill in buffer by line
		}

		__m256i reg = _mm256_setr_epi8(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6], buffer[7],
							buffer[8], buffer[9], buffer[10], buffer[11], buffer[12], buffer[13], buffer[14], buffer[15],
							buffer[16], buffer[17], buffer[18], buffer[19], buffer[20], buffer[21], buffer[22], buffer[23],
							buffer[24], buffer[25], buffer[26], buffer[27], buffer[28], buffer[29], buffer[30], buffer[31]);
		__m256i result = _mm256_add_epi8(ones, reg); //increment 1
        
        print__m256(result); // call pirnt char
	}

	return 0;
}
