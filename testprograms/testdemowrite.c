#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

static void usage(void)
{
	fprintf(stderr, "testdemowrite: usage: testdemowrite n (where n is a 32 bit integer\n");
	exit(1);
}

int main(int argc, char *argv[])
{
	int fd, rc;
	uint32_t register_value;

	if (argc < 2)
		usage();

	rc = sscanf(argv[1], "0x%08x", &register_value);
	if (rc != 1)
		usage();

	fd = open("/dev/demo0", O_RDWR);
	if (fd < 0) {
		fprintf(stderr, "Cannot open %s: %s\n", 
			"/dev/demo0", strerror(errno));
		exit(1);
	}

	rc = write(fd, &register_value, 4);
	if (rc != 4) {
		fprintf(stderr, "Wrote %d bytes instead of 4\n", rc);
		if (rc < 0) {
			fprintf(stderr, "err: %s\n", 
				strerror(errno));
		}
		exit(1);
	}
	printf("Done.\n");
	close(fd);
	return 0;
}
