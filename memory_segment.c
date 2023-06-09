#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	char *char_ptr;
	int *int_ptr;
	int mem_size;

	if (argc < 2) {
		mem_size = 50;
	}
	else {
		mem_size = atoi(argv[1]);
	}
	printf("[+] allocating %d bytes of memory from the heap for char_ptr.\n", mem_size);
	char_ptr = (char *) malloc(mem_size);
	
	if(char_ptr == NULL){
		fprintf(stderr, "Error, could not allocate memory from the heap. \n");
		exit(-1);
	}

	strcpy(char_ptr, "This statement is stored in the heap.");
	printf("The pointer char_ptr is located at the memory address (%p), and the value stored there is '%s'\n", char_ptr, char_ptr);

	printf("[+] allocating 15 bytes of memory from the heap for int_ptr. \n");
	int_ptr = (int *) malloc(15);

	if(int_ptr == NULL) {
		fprintf(stderr, "Error, could not allocate memory from the heap. \n");
		exit(-1);
	}

	*int_ptr = 31337;
	printf("The pointer int_ptr is located at (%p), and the value stored there is '%d'\n", int_ptr, int_ptr);

	printf("[-] deallocating memory in char_ptr.\n");
	free(char_ptr);

	printf("[-] deallocating memory in int_ptr.\n");
	free(int_ptr);
}
