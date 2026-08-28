/*
// A useful command from the people at Portals.
// I think Huthar wrote this one.
// 94-07-24 :  Pallando added utime and stime bits from TMI
*/

#include <std.h>

inherit DAEMON;

int cmd_gauge(string cmd)
{
   object act_ob;
   mapping before, after;
   int stime, usertime, eval_cost;
   
      act_ob = previous_object();

   if(!cmd) {
      notify_fail("usage: gauge <command>\n");
      return 0;
   }
    before = rusage();
    catch(eval_cost = (int)act_ob->force_me(cmd));
    after = rusage();
    usertime = after["utime"] - before["utime"];

    stime = after["stime"] - before["stime"];
    printf( "\n%d milliseconds of system time.\n"
	"%d milliseconds of user time.\n"
        "%d CPU cycles of eval cost.\n",
	stime, usertime, eval_cost );
   return 1;
}

string query_position() { return "admin"; }

int help()
{
  write( @EndText
Syntax: gauge <command>
Effect: Gauges how many CPU cycles <command> takes to execute.
    and how much system and user time.
Nota Bene: <command> must be typed in full (no aliases)
EndText
  );
  return 1;
}
