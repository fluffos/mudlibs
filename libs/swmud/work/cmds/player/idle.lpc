// Created 11-02-2006 by deforce

#include <mudlib.h>
#include <commands.h>

inherit CMD;
inherit M_ANSI;

string format_idle_time(int time);

private void main(string arg)
{
   object target;

   if (arg && find_user(arg))
   {
      target = find_user(arg);

      out(capitalize(arg) + " has been idle for " + format_idle_time(query_idle(target)) + ".");
   }
   else if (arg && !find_user(arg))
   {
      out("User " + capitalize(arg) + " is not currently connected.\n");
   }
   else
   {
      out("Usage: idle <player>\n");
   }
}

string format_idle_time(int time)
{
   string output = "";

   if (time > 59)
   {
      if (time > 3599)
      {
         if (time > 86399)
         {
            output += (time / 86400) + " days, ";

            time = time % 86400;
         }

         output += (time / 3600) + " hours, ";

         time = time % 3600;
      }

      output += (time / 60) + " minutes";

      if (time > 0) { output += ", and " + (time % 60) + " seconds"; }
   }
   else if (time > 0) { output += (time % 60) + " seconds"; }
   else { output += "0 seconds"; }

   return output;
}