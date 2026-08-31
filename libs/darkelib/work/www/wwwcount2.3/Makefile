# Generated automatically from Makefile.in by configure.
#####
# Makefile template for Count 2.0
# This file is used by the configure program to generate Makefile
# by Muhammad A Muquit
# 04/10/95, muquit@semcor.com
# http://www.semcor.com/~muquit/
# updated for Count 1.2 06/06/95, --muquit
# updated for Count 1.5 09/17/95, -- muquit
# updated for Count 2.0 11/25/95, -- muquit
#
# $Revision: 2.3 $
# $Date: 1996/05/03 02:20:22 $
#
#####

INCLUDES= -I. -I./combine
CC= gcc
DEFS=  -DSTDC_HEADERS=1 -DHAVE_SYS_WAIT_H=1 -DTIME_WITH_SYS_TIME=1 -DHAVE_STRING_H=1 -DHAVE_FCNTL_H=1 -DHAVE_MEMORY_H=1 -DHAVE_UNISTD_H=1 -DHAVE_CTYPE_H=1 -DHAVE_STRINGS_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_SYS_PARAM_H=1 -DHAVE_SYS_FILE_H=1 -DHAVE_STDLIB_H=1 -DHAVE_FLOCK=1 -DHAVE_STRCASECMP=1 -DHAVE_MKTIME=1 
LIBS=  
##
# do not undefine ACESS_AUTH
##
ACCESS_AUTH= -DACCESS_AUTH=1
DEFINES= $(INCLUDES) $(DEFS) $(ACCESS_AUTH) -D__USE_FIXED_PROTOTYPES__
CFLAGS= -O $(DEFINES) -DSYS_UNIX=1 -DDEBUG=1


OBJS= main.o parse.o strimage.o

all:	libCombine.a Count

#
# make the GIF combining library
#
libCombine.a:
	(cd combine; make)
#
Count:	$(OBJS)
		$(CC) $(CFLAGS) -o Count.cgi $(OBJS) ./combine/libCombine.a

main.o:	main.c
		$(CC) $(CFLAGS) -c main.c

parse.o:	parse.c
		$(CC) $(CFLAGS) -c parse.c

strimage.o:	strimage.c
		$(CC) $(CFLAGS) -c strimage.c

main.o:	count.h config.h
parse.o:	count.h config.h

clean:
	(cd combine; make clean)
	rm -f $(OBJS) Count.cgi core
	rm -f config.cache config.log config.status
