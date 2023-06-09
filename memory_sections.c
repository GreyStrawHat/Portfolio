#include <stdio.h>
#include <stdlib.h>

int global_var;
int initialized_global_var = 5;

void main() {
	static int static_var;
	static int initialized_static_var = 5;
	int stack_var;
	int *heap_var_ptr;

	heap_var_ptr = (int *) malloc(5);

	printf("This is the data segment.\n");
	printf("initialized_global_var is located at %p, and initialized_static_var is located at %p.\n", &initialized_global_var, &initialized_static_var);
	printf("\n");
	printf("This is the bss segment.\n");
	printf("global_var is located at %p, static_var is located at %p. \n", &global_var, &static_var);
	printf("\n");
	printf("This is the heap segment.\n");
	printf("heap_var_ptr is located at %p.\n", heap_var_ptr);
	printf("\n");
	printf("Finally this is the stack segment.\n");
	printf("stack_var is located %p.\n.", &stack_var);
}
