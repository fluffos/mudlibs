#include <std.h>

inherit DAEMON;

int
cmd_mstatus(string arg)
{
	int flag;

	flag = !!arg;
	mud_status(flag);
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
