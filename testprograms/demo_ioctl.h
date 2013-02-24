#ifndef DEMO_IOCTL_H
#define DEMO_IOCTL_H

#include <linux/types.h>
#include <linux/ioctl.h>
#include <linux/types.h>

#define DEMO_IOC_MAGIC 'x'

#define DEMO_ZAP_BUFFER _IOW(DEMO_IOC_MAGIC, 1, unsigned char)
#define DEMO_RESIZE_BUFFER _IOW(DEMO_IOC_MAGIC, 2, __u32)

#endif

