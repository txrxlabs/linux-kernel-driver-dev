
all:	test_ioctl test_ioctl2 resize_buffer

test_ioctl:	test_ioctl.c
	gcc -o test_ioctl test_ioctl.c

test_ioctl2:	test_ioctl2.c
	gcc -o test_ioctl2 test_ioctl2.c

resize_buffer:	resize_buffer.c
	gcc -o resize_buffer resize_buffer.c

clean:
	rm -f test_ioctl test_ioctl2 resize_buffer
