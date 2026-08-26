#include <lib.h>

inherit LIB_DAEMON;

int
cmd(string arg)
{
	int flag;

    if( arg && arg != "0" && arg != "" ) flag = 1;
    else flag = 0;
        this_player()->more(explode(mud_status(flag), "\n"), "system");
	return 1;
}

int help()
{
  write( @EndText
Syntax: mstatus [<arg>]
Effect: Give you statistics on the driver and mudlib
If the optional argument is given, you also get:
  add_message statistics
  Hash table of living objects
  Function cache information
  Heart beat information
  Shared string hash table
  Call out information
  Object name hash table status
See man: mud_status
See also: netstat, fdinfo, cache, callouts, dumpallobj, opcprof
EndText
  );
  return 1;
}
