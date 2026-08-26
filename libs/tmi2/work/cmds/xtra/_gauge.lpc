/*
// A useful command from the people at Portals.
// I think Huthar wrote this one.
*/

#include <mudlib.h>

inherit DAEMON ;

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
   eval_cost = act_ob->force_me(cmd);
   after = rusage();
    usertime = after["utime"] - before["utime"];
   stime = after["stime"] - before["stime"];
   write("\n"+ stime +" milliseconds of system time.\n"+
      usertime +" milliseconds of user time.\n" +
      eval_cost + " eval cost.\n");
   return 1;
}

string query_position() { return "admin"; }

int help() {
	write ("Usage: gauge <command>\n\n"+
"The gauge command will execute the given command, and will tell you\n"+
"how many milliseconds of CPU the command took. It does NOT recognize\n"+
"aliases in the argument, so you have to type things out.\n") ;
	return 1 ;
}
