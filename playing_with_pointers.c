#include <stdio.h>

int main() {
	void *hackypointer;
	int i;
	
	int int_array[5] = {1,2,3,4,5};
	char char_array[5] = {'a','b','c','d','e'};
	hackypointer = (void *) char_array;
	printf("The char array begins at memory address %p\n", char_array);	
	for (i=0;i < 5;i++) {
	printf("hackypointer points to %p and contains %c\n", hackypointer, *((char *) hackypointer));
	hackypointer = hackypointer + sizeof(char);
			}
	printf("hackypointer's memory address is %p\n", hackypointer);
	
	hackypointer = (void *) int_array;
	printf("The int array begins at memory address %p\n", int_array);
	for (i=0;i < 5;i++) {
	printf("hackypointer points to %p and contains the value %d\n", hackypointer, *((int *) hackypointer));
	hackypointer = hackypointer + sizeof(int);
}
}
