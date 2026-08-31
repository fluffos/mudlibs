# Generated automatically from Makefile.in by configure.
#######
# for unix
# Makefile template for mkstrip, program which makes a strip of image from
# combining several images
#######
INCLUDES= -I. -I../combine -I..
CC= gcc
DEFS=  -DSTDC_HEADERS=1 -DHAVE_SYS_WAIT_H=1 -DTIME_WITH_SYS_TIME=1 -DHAVE_STRING_H=1 -DHAVE_FCNTL_H=1 -DHAVE_MEMORY_H=1 -DHAVE_UNISTD_H=1 -DHAVE_CTYPE_H=1 -DHAVE_STRINGS_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_SYS_PARAM_H=1 -DHAVE_SYS_FILE_H=1 -DHAVE_STDLIB_H=1 -DHAVE_FLOCK=1 -DHAVE_STRCASECMP=1 -DHAVE_MKTIME=1 
DEFINES= $(INCLUDES) $(DEFS) -D__USE_FIXED_PROTOTYPES_
CFLAGS= -O $(DEFINES) 

BINARY=mkstrip
LIBS= ../combine/libCombine.a

OBJS= mkstrip.o

all: mkstrip

mkstrip: $(OBJS)
	$(CC) $(CFLAGS) -o $(BINARY) $(OBJS) $(LIBS)

mkstrip.o: mkstrip.c
	$(CC) $(CFLAGS) -c mkstrip.c

clean:
	rm -f mkstrip.o mkstrip core
