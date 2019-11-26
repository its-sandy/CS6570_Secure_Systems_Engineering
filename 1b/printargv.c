#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*  
 * compiled with:
 * gcc -m32 -O0 -fno-stack-protector tut1.c -o tut1
 * 
 * 1. objdump --disassemble-all tut1 > tut1.diss
 */

extern char **environ;
char globalbuf[9000];

struct tmp_t{
	char *p;
	int i,j;
}tt; /* struct ensures no compiler tricks in the stack layout */


volatile mergecmdline(int argc, char **argv, char *buf){
	char localbuf[512];

	tt.j=8;

	memset(localbuf, 0, sizeof(localbuf));
	strcat(localbuf, "CMDLINE=");
	for(tt.i=0; tt.i<argc; ++tt.i){
		tt.p = argv[tt.i];
		printf("%s\n", tt.p);
		while(*tt.p != '\0'){
			localbuf[tt.j] = *tt.p;
			tt.p++;	
			tt.j++;
		}
	}
	strcpy(buf, localbuf);
	return;
}

void getdetails(int argc, char **argv, char *mainbuf){
	int i = 0, j = 0;
	char localbuf[9000];

	while(environ[i]){
		strcat(&localbuf[j], environ[i]);
		j = j + strlen(environ[i]);
		localbuf[j] = '\n';
		i++; j++;
	}
	mergecmdline(argc, argv, &localbuf[j]);
	strcpy(mainbuf, localbuf);
}

int main(int argc, char **argv)
{
	char localbuf[9000];
	
	getdetails(argc, argv, globalbuf);
	printf("%s\n", globalbuf);	
}
