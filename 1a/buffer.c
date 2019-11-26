#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int memo[1000000];

int fib(int n){
  if(memo[n] != 1) return memo[n];
   if( n == 0 ) return 0;
   if( n == 1 ) return 1;
   return memo[n] = ( fib(n-1)  +  fib(n-2) );
}

int main( ){
memset(memo,1, sizeof(memo));
   int n = 174570;
   char *str = (char *) malloc(50);
   gets(str);
   printf("Str: %s\n Fib Result: %d\n", str, fib(n));
   free(str);
   return 0;
}

