#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct line {
	struct line *prev;
	struct line *next;
	char *line;
};

int tac(const char *path)
{
	FILE *f = stdin;
	if (path && strcmp(path, "-") != 0) {
		f = fopen(path, "r");
		if (f == NULL) {
			perror("tac:fopen");
		}
	}

	/* read lines into doubly-linked list */
	/* print lines in reverse order */

	if (f != stdin) {
		fclose(f);
	}

	return 0;
}

int main(int argc, char *argv[])
{
	while (getopt(argc, argv, "") != -1) {
		/* no options supported */
		return 1;
	}

	int ret = 0;
	do {
		ret |= tac(argv[optind]);
	} while (argv[++optind]);
	return 1;
}
