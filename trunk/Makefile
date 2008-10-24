CC=gcc
CFLAGS=-O2
LIBS=

SRCS=$(wildcard *.c)
OBJS=$(patsubst %.c,%.o,$(SRCS))

all:	$(OBJS)
	$(CC) -shared -fPIC $(CFLAGS) $(SRCS) $(LIBS) -o libpyv4l2.so
	
