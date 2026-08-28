#include <std.h>

inherit DAEMON;

int
cmd_dumpallobj(string arg)
{
  if(!archp(previous_object())) return 0;
        dumpallobj("log/objects");
	return 1;
}

int help()
{
  write( @EndText
Syntax: dumpallobj
Effect: Puts a list of all currently loaded objects in /log/objects
See man: dumpallobj
See also: callouts, cache, mstatus, netstat, fdinfo, opcprof
EndText
  );
  return 1;
}
