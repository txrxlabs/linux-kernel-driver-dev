#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <string.h>
#include <errno.h>
#include <inttypes.h>

#include "demo_ioctl.h"

static void usage(void)
{
	fprintf(stderr, "Usage: test_ioctl2 *device* *buffersize*\n");
	exit(1);
}

int main(int argc, char *argv[])
{
	int fd, rc;
	__u32 buffersize;

	if (argc < 3)
		usage();

	rc = sscanf(argv[2], "%u", &buffersize);
	if (rc != 1)
		usage();

	fd = open(argv[1], O_RDWR);
	if (fd < 0) {
		fprintf(stderr, "%s: open: %s\n", argv[0], strerror(errno));
		exit(1);
	}
	rc = ioctl(fd, DEMO_RESIZE_BUFFER, &buffersize);
	printf("ioctl returns %d\n", rc);
	exit(0);
}
