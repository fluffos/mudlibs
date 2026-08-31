# Simple Makefile for Nanog traceroute -- 10141998 
# Matthew Ramsey <mjr@blackened.com>
# 


# ------ defs that one might want to change

# compiler
CC = gcc

# install prefix
PREFIX ?= /usr/local

#Installation directory
INSTALLBIN = ${PREFIX}/sbin

# Manpage directory
MANDIR = ${PREFIX}/man/man8

# Installation program location
INSTALL = install -c 

# ----- The rest are defs that probably don't need to be changed # in most 
# UNIXish environments

BINNAME = traceroute
MANS = traceroute.8

# Some flags that should suit AIX, BSD/OS, Digital UNIX, FreeBSD and Mach10
BSDFLAGS = -O
BSDLIBS = -lm

# Some flags that should suit Ultrix
ULTRIXFLAGS = -DULTRIX43 -O
ULTRIXLIBS = -lm

# Unixware flags
# Note that you'll probably need to use cc as your compiler
UWAREFLAGS = -O -MAX_DATALEN=1500
UWARELIBS = -lm -lresolv

# Solaris flags
SOLFLAGS = -O -DSOLARIS
SOLLIBS = -lm -lresolv -lsocket -lnsl

#DEFFLAGS: -O

all:
	@ echo 'Type "make osname" where osname is one of the following operating systems'
	@ echo 'name	   operating systems covered'
	@ echo 'bsd	   AIX, BSD/OS, DEC UNIX, FreeBSD, Mach10, BSD'
	@ echo 'ultrix	   ULTRIX 4.3 and possibly other versions'
	@ echo 'unixware   UNIXWare 1.0.3 and possibly other versions'
	@ echo 'solaris	   SunOS 5.x/Solaris 2.x'
	@ echo 'VMS users -- read the 0_readme.txt file!'
bsd: 
	$(CC) -o $(BINNAME) $(BSDFLAGS) traceroute.c $(BSDLIBS)
ultrix: 
	$(CC) -o $(BINNAME) $(ULTRIXFLAGS) traceroute.c $(ULTRIXLIBS)
unixware: 
	$(CC) -o $(BINNAME) $(UWAREFLAGS) traceroute.c $(UWARELIBS) 
solaris:
	 $(CC) -o $(BINNAME) $(SOLFLAGS) traceroute.c $(SOLLIBS)

install: 
	$(INSTALL) -m 4555 -o root -g bin -s $(BINNAME) $(INSTALLBIN)
	$(INSTALL) -m 444 traceroute.8 $(MANDIR)



