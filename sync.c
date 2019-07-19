#define _XOPEN_SOURCE
#define _XOPEN_SOURCE_EXTENDED 1
#include <unistd.h>

int main(void)
{
	sync();
	return 0;
}
