/* Display various information about the mud's status.

   File taken from the VikingMUD lib.  Written by Kniggit 930525

   Hamlet added some stuff, May 1997.
   Hamlet got annoyed and reworked the code, Jul 1997.
*/
 
#include <standard.h>
#include <cmd.h>

#ifndef __COMPILER__
#define __COMPILER__     "probably gcc"
#define __OPTIMIZATION__ "bugged driver?"
#endif

#define WIDTH 15

inherit CMD_BASE;

void setup()
{
  position = 0;
  dodest = 1;
}

#define PAD(x,y)      sprintf("%-*s: %s\n", WIDTH, x,"" + y)

protected int cmd(string str, object me)
{
   mapping r;
   float cpu;
   string name, cc, tmp;
   
   name = capitalize(mud_name()) + "   (" + query_host_name() + " " + 
          __PORT__ + ")";
   cc = __COMPILER__ + "   (" + __OPTIMIZATION__ + ")";
   r = rusage();
   cpu = ((r["utime"] + r["stime"]) / uptime() / 10.0);
   
   tmp = PAD("Mud name", name) +
         PAD("Driver", __VERSION__) +
         PAD("Architecture", __ARCH__) +
         PAD("Compiler", cc) +
         PAD("Driver uptime", pretty_time(uptime(), 4)) +
         PAD("Avg Cpu usage", sprintf("%4.2f%%",cpu)) +
         PAD("Load Average", query_load_average()) +
         PAD("No of users", sizeof(users())) +
//   PAD("Named Livings", sizeof(named_livings())) + 
         PAD("Objects", sizeof(objects())) +
         PAD("Call Outs", sizeof(call_out_info()) + " pending.") +
         PAD("Memory usage", memory_info());
   tell_object(me, tmp);
   return 1;
}

string short_help() { 
  return "Show some information about the mud's system usage.\n"; 
}
