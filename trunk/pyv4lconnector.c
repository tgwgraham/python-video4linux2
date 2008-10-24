#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>
#include <time.h>
#include <linux/ioctl.h>
#include <linux/videodev2.h>

//  =====================================================================
int Errno()
{
	return errno;
}

//  =====================================================================
char* Error()
{
	return strerror(errno);
}

//  =====================================================================
char* bool2str(int b)
{
	if (b)
		return "True";
	
	return "False";
}

//  =====================================================================
int BufferDiff(char* b1, char* b2, int size, int format)
{
	int i 		= 0;
	int count = 0;
	
	for (i = 0; i < size; i++)
	{
		if (b1[i] != b2[i])
		{
			count++;
		}
	}

	return count;
}

//  =====================================================================
int Open(char* dev)
{
	int	fd	=	open(dev, O_RDWR);
	return fd;
}

//  =====================================================================
int Close(int fd)
{
	close(fd);
	return 0;
}

//  =====================================================================
int QueryCaps(int fd, struct v4l2_capability* caps)
{
	if (ioctl(fd, VIDIOC_QUERYCAP, caps) == -1)
		return -1;
	
	return 0;
}

//  =====================================================================
int EnumInput(int fd, struct v4l2_input* input)
{
	if (ioctl(fd, VIDIOC_ENUMINPUT, input) == -1)
		return -1;
	
	return 0;
}

//  =====================================================================
int EnumFormat(int fd, struct v4l2_fmtdesc* input)
{
	if (ioctl(fd, VIDIOC_ENUM_FMT, input) == -1)
		return -1;
	
	return 0;
}

//  =====================================================================
int SetInput(int fd, int input)
{
	if (ioctl(fd, VIDIOC_S_INPUT, &input ) == -1)
		return -1;
	
	return 0;
}

//  =====================================================================
int SetStandard(int fd, v4l2_std_id std)
{
	if (ioctl(fd, VIDIOC_S_STD, &std ) == -1)
		return -1;
	
	return 0;
}

//  =====================================================================
int GetFormat(int fd, struct v4l2_format* f)
{
	if (ioctl(fd, VIDIOC_G_FMT, f) == -1)
		return -1;
	
	return 0;
}

//  =====================================================================
int SetFormat(int fd, struct v4l2_format* f)
{
	if (ioctl(fd, VIDIOC_S_FMT, f) == -1)
		return -1;
	
	return 0;
}

//  =====================================================================
int Read(int fd, char* buf, int bufsize)
{
	return read(fd, buf, bufsize);
}

//  =====================================================================
int RequestBuffers(int fd, struct v4l2_requestbuffers* f)
{
	if (ioctl(fd, VIDIOC_REQBUFS, f) == -1)
		return -1;
	
	return 0;
}

//  =====================================================================
int Queue(int fd, struct v4l2_buffer* f)
{
	if (ioctl(fd, VIDIOC_QBUF, f) == -1)
		return -1;
	
	return 0;
}

//  =====================================================================
int Dequeue(int fd, struct v4l2_buffer* f)
{
	if (ioctl(fd, VIDIOC_DQBUF, f) == -1)
		return -1;
	
	return 0;
}

int main(int argc, char* argv)
{
	return 0;
}
