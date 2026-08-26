// Last edited by deforce on 04-13-2010
//  06-14-1996 - Alexus adds timed shutdown daemon support
//  12-15-1996 - Deathblade: removed time stamping (let LOG_D do it)

#include <log.h>

#define THE_BIG_GUY     "Yoda"
#define tell_all(s)     tell(users(), (s))
#define COLOR "%^BOLD%^"

inherit CMD;

int call_number;

private void do_shutdown(string s)
{
   if (!check_privilege(1) && (SECURE_D->query_is_wizard(this_body()->query_userid()) < 3))
   {
      LOG_D->log(LOG_SHUTDOWN, "do_shutdown() failed: insufficient privilege\n");

      return;
   }

   LOG_D->log(LOG_SHUTDOWN, sprintf("SHUTDOWN performed (%s)\n", s));

   while (sizeof(users()))
   {
      foreach (object ob in users())
      {
         catch(ob->quit());
         catch(destruct(ob));
      }
   }

//   unguarded(1, (: shutdown :));
   call_out((: unguarded, 1, (: shutdown :) :), sizeof(users()));
}

private void count_down(int num, string s)
{
   if (!num)
   {
      tell_all(THE_BIG_GUY " tells you: Shutting down immediately the game is!\n");

      do_shutdown(s);

      return;
   }

   tell_all(COLOR + THE_BIG_GUY " tells you: Shutdown in " + M_GRAMMAR->number_of(num, "minute") + ".%^RESET%^\n");

   num--;

   call_number = call_out((: count_down, num, s :), 60);
}

private void main(mixed *args, mapping flags)
{
   int num;
   string s;

   if (!wizardp(this_body()))
   {
      out("This command is for wizard use only.\n");
      return;
   }

   if (!check_privilege(1) && (SECURE_D->query_is_wizard(this_body()->query_userid()) < 3))
   {
      out("A Wizard Master or Teacher is needed for shutdown.\n");

      return;
   }

   s = implode(args[0], " ");

   // Handle cancelation checking first!
   if (flags["c"])
   {
      if (remove_call_out(call_number) == -1)
      {
         out("There is no shutdown in progress.\n");

         return;
      }

      LOG_D->log(LOG_SHUTDOWN, sprintf("Shutdown cancelled by %s (%s)\n", this_body()->query_name(), s));

      tell_all(COLOR + THE_BIG_GUY " tells you: Shutdown has been cancelled.%^RESET%^\n");

      call_number = 0;

      return;
   }

   // Check to make sure that a shutdown isn't already in progress
   if (call_number)
   {
      out("Shutdown is already in progress.\n");

      call_number = 0;

      return;
   }

   // Check to see if a -t # switch was given.  If so, don't shut down, just start the shutdown daemon.
   if (flags["t"])
   {
      LOG_D->log(LOG_SHUTDOWN, sprintf("Shutdown started by %s (%s)\n", this_body()->query_name(), s));

      num = to_int(flags["t"]);
      count_down(num, s);
      out("Shutdown started.\n");

      return;
   }

   LOG_D->log(LOG_SHUTDOWN, sprintf("Immediate shutdown requested by %s\n",
      this_user()->query_userid()));
   tell_all(COLOR + THE_BIG_GUY " tells you: Shutting down immediately the game is!%^RESET%^\n");
   do_shutdown(s);
}

// Used by the out of memory code; could be added elsewhere too
void automatic_shutdown(string reason)
{
   if (!check_privilege(1) && (SECURE_D->query_is_wizard(this_body()->query_userid()) < 3))
   {
      error("automatic_shutdown() failed: Permission denied\n");
   }

   tell_all(COLOR + THE_BIG_GUY " shouts: Automatic shutdown (" + reason + ") triggered.%^RESET%^\n");
   LOG_D->log(LOG_SHUTDOWN, "Shutdown started by " THE_BIG_GUY "(" + reason + ")\n");

   count_down(10, reason);
}