// _opcprof.c: coded by Truilkan@TMI, 1992/08/06
// Lists all the efuns into the file  OPCPROF.efun in the root dir.

#include <mudlib.h>

inherit DAEMON ;

int cmd_opcprof()
{
#ifndef HAS_OPCPROF
  write("Driver compiled without profiling!\n");
#else
    opcprof();
#endif
        return 1;
}

string help() {
	return (
"This command dumps a list of all the efuns into the root directory.\n"+
"You need to enable this in the driver options.h file at compile\n"+
"time.\nSee also: \"help efuns opcprof\"\n"+
"" );
}
