#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int count;
char rollnumber1[16] = "CS16B022";
char rollnumber2[16] = "CS16B107";

void copy_chars(int argc, char **argv){
	char array[80];
	short idx;
	int foo = atoi(argv[1]);
	idx = foo;

	if(idx >= 80) {
		return;
	}

	memcpy(array, argv[2], foo);

}

int main(int argc, char **argv) {
	
	char buff[32784];
	copy_chars(argc, argv);
	printf("Roll Numbers : %s and %s\n", rollnumber1, rollnumber2);
	printf("Value in count is %d\n", count);
	return EXIT_SUCCESS;
}
