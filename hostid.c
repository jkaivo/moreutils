#define _XOPEN_SOURCE
#define _XOPEN_SOURCE_EXTENDED 1
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	printf("%08lx\n", gethostid());
	return 0;
}
