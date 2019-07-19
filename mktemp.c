#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char template[FILENAME_MAX] = "tmp.XXXXXXXXXX";
	if (argc != 1) {
		strcpy(template, argv[1]);
	}
	if (!strstr(template, "XXXXXX")) {
		fprintf(stderr, "template must contain at least six 'X' characters\n");
		return 1;
	}
	rmdir(template);
	printf("%s\n", mkdtemp(template));
	return 0;
}
