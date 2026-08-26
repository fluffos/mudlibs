/*
// A useful command from the people at Portals.
// I think Huthar wrote this one.
// 94-07-24 :  Pallando added utime and stime bits from TMI
*/

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
#ifndef __HAS_RUSAGE__
    return "This MUD's driver was not compiled with HAS_RUSAGE.";
#else
   object act_ob;
   mapping before, after;
   int stime, usertime, eval_cost;
   
   if( !args || args == "" ) return "You must specify a command to execute.";
   before = rusage();
   catch(eval_cost = (int)previous_object()->eventForce(args));
   after = rusage();
   usertime = after["utime"] - before["utime"];
   stime = after["stime"] - before["stime"];
   message("system", "\n" + stime + " ms system time, " + usertime +
	   " ms user time, and " + eval_cost + " CPU cycles eval cost.",
	   this_player());
   return 1;
#endif /* __HAS_RUSAGE__ */
}

void help() {
#ifndef __HAS_RUSAGE__
    message("help", "This command cannot be used under this driver "
	    "configuration.", this_player());
#else
    message("help", "Syntax: <gauge [command]>\n\n"
	    "Executes the command named and gauges how many CPU cycles, "
	    "system time, and user time took to execute.  You may not use "
	    "aliases.", this_player());
#endif /* __HAS_RUSAGE__ */
}
