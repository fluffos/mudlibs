#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup()
{
position = 1;
}

protected int cmd(string str, object me) {
   tell_object(me, cache_stats());
  return 1;
} /* do_malloc() */


string short_help()
{
   return "Returns cache information about FR's driver and mudlib.\n";
}
