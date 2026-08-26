// uptime.c
// Tells you how long the mud is up.
// Lord knows who wrote it.
// Mobydick added header and help, 11-20-92

#include <mudlib.h>

inherit DAEMON ;


int cmd_uptime() {
   write(capitalize(mud_name()) + " has been up for " +
	 format_time(uptime()) + ".\n");
   return 1;
}

int help() {
	write ("Usage: uptime\n\n"+
"Tells you how long the MUD has been running for since the last crash.\n") ;
	return 1 ;
}
