#define _XOPEN_SOURCE
#define _XOPEN_SOURCE_EXTENDED
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
	close(mkstemp(template));
	unlink(template);
	printf("%s\n", template);
	return 0;
}
