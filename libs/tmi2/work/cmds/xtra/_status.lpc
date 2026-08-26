// _status.c
// Displays some information about mud memory usage.
// Original author unknown, probably written late in 1991
// Header added by Mobydick, 11-16-92.

#include <mudlib.h>

inherit DAEMON ;

int cmd_status(string extra)
{
        mud_status(extra == "tables");
        return 1;
}

int help() {
	write ("Usage: status\n\n"+
"Displays some information about memory usage by the MUD.\n") ;
	return 1 ;
}
