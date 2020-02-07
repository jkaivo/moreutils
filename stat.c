#define _XOPEN_SOURCE 700
#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

void print_time(const char *label, struct timespec ts)
{
	char dtg[BUFSIZ];
	char zone[BUFSIZ];
	time_t t = ts.tv_sec;
	struct tm *tm = localtime(&t);
	strftime(dtg, sizeof(dtg), "%F %T", tm);
	strftime(zone, sizeof(zone), "%z", tm);
	printf("%s: %s.%09lu %s\n", label, dtg, ts.tv_nsec, zone);
}

int print_stat(const char *path)
{
	struct stat st;
	if (stat(path, &st) != 0) {
		fprintf(stderr, "stat: %s: %s\n", path, strerror(errno));
		return 1;
	}

	struct passwd *user = getpwuid(st.st_uid);
	struct group *group = getgrgid(st.st_gid);

	printf("  File: %s\n", path);
	printf("  Size: %-10zu", (size_t)st.st_size);
	printf("\tBlocks: %-11zu", (size_t)st.st_blocks);
	printf("IO Block: %-8zu", (size_t)st.st_blksize);
	/* TODO: file type */
	printf("\n");

	printf("Device: %zxh/%zud", (size_t)st.st_dev, (size_t)st.st_dev);
	printf("\tInode: %-12zu", (size_t)st.st_ino);
	printf("Links: %zu", (size_t)st.st_nlink);
	/* TODO: device number (major,minor) */
	printf("\n");

	printf("Access: (%04o/", 07777 & (unsigned int)st.st_mode);
	if (S_ISDIR(st.st_mode)) {
		putchar('d');
	} else if (S_ISFIFO(st.st_mode)) {
		putchar('p');
	} else if (S_ISLNK(st.st_mode)) {
		putchar('l');
	} else if (S_ISCHR(st.st_mode)) {
		putchar('c');
	} else if (S_ISBLK(st.st_mode)) {
		putchar('b');
	} else {
		putchar('-');
	}

	putchar(st.st_mode & S_IRUSR ? 'r' : '-');
	putchar(st.st_mode & S_IWUSR ? 'w' : '-');
	if (st.st_mode & S_ISUID) {
		putchar(st.st_mode & S_IXUSR ? 's' : 'S');
	} else {
		putchar(st.st_mode & S_IXUSR ? 'x' : '-');
	}

	putchar(st.st_mode & S_IRGRP ? 'r' : '-');
	putchar(st.st_mode & S_IWGRP ? 'w' : '-');
	if (st.st_mode & S_ISGID) {
		putchar(st.st_mode & S_IXGRP ? 's' : 'S');
	} else {
		putchar(st.st_mode & S_IXGRP ? 'x' : '-');
	}

	putchar(st.st_mode & S_IROTH ? 'r' : '-');
	putchar(st.st_mode & S_IWOTH ? 'w' : '-');
	if (st.st_mode & S_ISVTX) {
		putchar(st.st_mode & S_IXOTH ? 't' : 'T');
	} else {
		putchar(st.st_mode & S_IXOTH ? 'x' : '-');
	}

	printf(")  Uid: (%5zu/%8s)", (size_t)st.st_uid, user->pw_name);
	printf("   Gid: (%5zu/%8s)", (size_t)st.st_gid, group->gr_name);
	printf("\n");

	print_time("Access", st.st_atim);
	print_time("Modify", st.st_mtim);
	print_time("Change", st.st_ctim);
	printf(" Birth: -\n");

	return 0;
}

int main(int argc, char *argv[])
{
	int c;
	while ((c = getopt(argc, argv, "")) != -1) {
		switch (c) {
		default:
			return 1;
		}
	}

	if (optind >= argc) {
		fprintf(stderr, "stat: missing operand\n");
		return 1;
	}

	int ret = 0;
	while (optind < argc) {
		ret |= print_stat(argv[optind++]);
	}
	return ret;
}
