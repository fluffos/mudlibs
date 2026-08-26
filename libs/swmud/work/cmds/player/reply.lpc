// Last edited by deforce on 02-11-2008
// USAGE: reply <message>

// Updated 7/15/2006 by deforce

//:PLAYERCOMMAND
//USAGE: reply <message>
//
//When you are given a message via tells, it is much easier to
//type 'reply <put message here>' than 'tell <somebody> <message>'.
//Just 'reply' on it's own will show you who you're currenty replying to.

#include <mudlib.h>
#include <commands.h>
#include <playerflags.h>

inherit CMD;
inherit M_GRAMMAR;
inherit M_COMPLETE;
inherit M_ANSI;

string format_idle_time(int time);

void create()
{
   ::create();
   no_redirection();
}

private void main(string arg)
{
   object target = find_user(this_user()->query_reply());
   int idletime;
   string mystring;
   string deststring;

   if (!arg || (arg == ""))
   {
      if (target) { out("You would reply to " + capitalize(target->query_userid()) + ".\n"); }
      else { out("You have no one to reply to.\n"); }

      return;
   }

   if (!target)
   {
      out("No target found for reply.\n");

      return;
   }

   if (this_body()->test_flag(F_SILENCED))
   {
      out("You have been silenced from replying to tells.\n");

      return;
   }

   mystring = sprintf("%%^TELL%%^You reply to %s:%%^RESET%%^ %s\n", capitalize(target->query_userid()), arg);

   deststring = "%^TELL%^" + capitalize(this_user()->query_userid()) + " replies: %^RESET%^" + arg + "\n";

   idletime = query_idle(target);

   out(mystring);
   this_user()->add_tell_history(mystring);

   target->receive_private_msg(deststring, MSG_INDENT);
   target->add_tell_history(deststring);
   target->set_reply(this_user()->query_userid());
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

      if (time > 0) { output += ", " + (time % 60) + " seconds"; }
   }
   else if (time > 0) { output += " (" + (time % 60) + " seconds"; }

   return output;
}