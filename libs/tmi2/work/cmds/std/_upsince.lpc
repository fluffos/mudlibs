// upsince.c
// Lord only knows who wrote this.
// Mobydick added help and header, 11-20-92

#define UPSINCE "/log/UPSINCE"
#include <mudlib.h>

inherit DAEMON ;

int
cmd_upsince( string arg )
{
    write("The driver has been up since:\n\t");
    write(ctime( time() - uptime() ) + "\n");
    return 1;
}

int help() {
	write ("Usage: upsince\n\n"+
"This command tells you how long it has been since the last crash.\n") ;
	return 1 ;
}
