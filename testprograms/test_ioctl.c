#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int fd, rc;

	fd = open(argv[1], O_RDWR);
	if (fd < 0) {
		fprintf(stderr, "%s: open: %s\n", argv[0], strerror(errno));
		exit(1);
	}
	rc = ioctl(fd, 1, 0);
	printf("ioctl returns %d\n", rc);
	exit(0);
}
