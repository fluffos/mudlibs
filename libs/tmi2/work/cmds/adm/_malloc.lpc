// _malloc.c
// Front-end for the malloc_status efun.
// Installed in the TMI-2 mudlib by Moby on 10-22-93.
// Decker@TMI-2 gave it to us, he got it from CW. He may be the original
// author, or someone else at CW, not sure.
// Moby added this head and the help on 10-22-93.
// In any event, don't use this file without permissions. :)

#include <mudlib.h>

inherit DAEMON;

#define SCREEN_WIDTH 75

int cmd_malloc( string str ) 
{
	malloc_status();
	return 1;
}

string help() {
	return ("Usage: malloc\n\n"+
"The malloc command prints information on the amount of memory the MUD\n"+
"has allocated, and how that memory is being used.\n") ;
}
