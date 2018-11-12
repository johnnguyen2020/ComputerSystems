// For this exercise, you are going to read in data from a file called 'data.txt'
// Increment all of the values by 1.
// 
// You will compile this source using the following:
// 
// clang -std=c11 -mavx2 ex1.c -o ex1prog
//
// Run as normal with: 
// 
// ./ex1prog
//
#include <stdio.h>
#include <immintrin.h>



// print
void print__m256(__m256 data){
	float*f = (float*)&data;
	printf("%f %f %f %f %f %f %f %f\n", f[0],f[1],f[2],f[3],f[4],f[5],f[6],f[7]);
}

int main(){

	FILE *filePointer; // create file pointer
	filePointer = fopen("data.txt", "r"); // open as read only
	float buffer[8]; // buffer to fold line read, 8 elements for register parallelization

	__m256 reg_1 = _mm256_set_ps(1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0);

    int counter = 0;
	while(!feof(filePointer) && counter != 4){ // read unitl end of file
		fscanf(filePointer, "%f", &buffer[0]); // store data in buffer by element 
		fscanf(filePointer, "%f", &buffer[1]);
		fscanf(filePointer, "%f", &buffer[2]);
		fscanf(filePointer, "%f", &buffer[3]);
		fscanf(filePointer, "%f", &buffer[4]);
		fscanf(filePointer, "%f", &buffer[5]);
		fscanf(filePointer, "%f", &buffer[6]);
		fscanf(filePointer, "%f", &buffer[7]);
        counter++;

		__m256 reg_2 = _mm256_setr_ps(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6], buffer[7]); //set register
		__m256i result = _mm256_add_ps(reg_1, reg_2); //add results in register 
		print__m256(result); // print results in result register 
	}

	return 0;
}
