#include <stdlib.h>
#include <stdio.h>
#include <sys/syscall.h>

int main(){
	char * buf = "Hallo";
	char * buf2 = "Welt";
	syscall(82,buf,buf2);
	printf("%s", buf);
	return 0;
}