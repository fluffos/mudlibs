# Generated automatically from Makefile.in by configure.
#
# Makefile template for GIF combining lib
# This file is used by the configure program to generate Makefile
# muquit@semcor.com
# 07-11-95, -- muquit
# 09-17-95 (Count 1.5), -- muquit
# 11-25-95 (Count 2.0), -- muquit

CC= gcc
DEFS=  -DSTDC_HEADERS=1 -DHAVE_SYS_WAIT_H=1 -DTIME_WITH_SYS_TIME=1 -DHAVE_STRING_H=1 -DHAVE_FCNTL_H=1 -DHAVE_MEMORY_H=1 -DHAVE_UNISTD_H=1 -DHAVE_CTYPE_H=1 -DHAVE_STRINGS_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_SYS_PARAM_H=1 -DHAVE_SYS_FILE_H=1 -DHAVE_STDLIB_H=1 -DHAVE_FLOCK=1 -DHAVE_STRCASECMP=1 -DHAVE_MKTIME=1 
AR= ar cq
RANLIB= ranlib

INCLUDES=  -I. -I..

# replace -O with -g in order to debug

DEFINES= $(INCLUDES) $(DEFS) -D__USE_FIXED_PROTOTYPES__ -DSYS_UNIX=1
CFLAGS= -O $(DEFINES)

SRCS = crbasei.c allocim.c readgif.c rddata.c dstraimg.c\
       readblk.c lzwdec.c syncimg.c duplicim.c writegif.c lsbfwrs.c\
       lzenc.c uncmpimg.c readim.c flatten.c signature.c quantize.c\
       compimg.c rgbtran.c tranrgb.c compcmap.c frameim.c modulate.c\
       alphaim.c setpixel.c getfinfo.c imgstr.c gdfonts.c negate.c\
       rotate.c getsize.c opaqim.c cropim.c
OBJS = crbasei.o allocim.o readgif.o rddata.o dstraimg.o\
       readblk.o lzwdec.o syncimg.o duplicim.o writegif.o lsbfwrs.o\
       lzwenc.o uncmpimg.o readim.o flatten.o signature.o quantize.o\
       compimg.o rgbtran.o tranrgb.o compcmap.o frameim.o modulate.o\
       alphaim.o setpixel.o getfinfo.o imgstr.o gdfonts.o negate.o\
       rotate.o getsize.o opaqim.o cropim.o

.c.o:
	rm -f $@
	$(CC) $(CFLAGS) -c $*.c

all: libCombine.a

libCombine.a: $(OBJS)
	rm -f $@
	$(AR) $@ $(OBJS)
	$(RANLIB) $@

combine.o: combine.h

clean:
	rm -f $(OBJS) libCombine.a core
