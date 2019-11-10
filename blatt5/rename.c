/**
 * Gruppe 7
 * Andreas Diesendorf
 * Artur Siubiak
 * Jan Wolfram
 * 
 * Kompiliert mit:
 * clang -Wall -Wextra -pedantic -std=c99 -g rename.c -o rename
 * 
 * Ausgeführt: 
 * ./rename
**/

#include <stdlib.h>
#include <stdio.h>
#include <sys/syscall.h>

int main(){
	char * buf = "hallo.txt";
	char * buf2 = "welt.txt";
	syscall(82, buf, buf2);
	printf("%s > %s\n", buf, buf2);
	return 0;
}