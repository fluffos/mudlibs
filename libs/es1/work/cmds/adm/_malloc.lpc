//#pragma save_binary
// _malloc.c
// Original author and date unknown.
// Mobydick, who had no idea what this did, added this header on 11-9-92
// on the theory that each file should have a header even if it was a 
// completely uninformative one.
// Besides, the command is one line long, how hard could it be to figure
// it out?

#include <mudlib.h>

inherit DAEMON ;

int cmd_malloc() { malloc_status(); return 1; }

int help() {
	write (
"The malloc command tells you which memory allocation package the driver\n"+
"is currently using. It calls the malloc_status efun, see the man page on\n"+
"that efun for more information.\n") ;
	return 1 ;
}
