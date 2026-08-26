// Last edited by deforce on 05-04-2010
#include <flags.h>

inherit VERB_OB;

void do_forcestatus_liv_wrd(object living, string word)
{
   if (word == "on")
   {
      living->assign_flag(F_FORCE_SENSITIVE, 1);

      write(title_capitalize(living->short()) + " is now Force-sensitive.\n");
   }
   else if (word == "off")
   {
      living->assign_flag(F_FORCE_SENSITIVE, 0);

      write(title_capitalize(living->short()) + " is no longer Force-sensitive.\n");
   }
   else
   {
      write("Usage: forcestatus <living> on | off\n");
   }
}

void do_forcestatus_liv(object living)
{
   if (living->test_flag(F_FORCE_SENSITIVE))
   {
      write(title_capitalize(living->short()) + " is Force-sensitive.\n");
   }
   else
   {
      write(title_capitalize(living->short()) + " is not Force-sensitive.\n");
   }
}

void do_forcestatus()
{
   write("Check whose Force status?\n");
}

mixed can_forcestatus_liv_wrd()
{
   if (adminp(this_body())) { return 1; }

   return "You must be an admin to set someone's Force status.\n";
}

mixed can_forcestatus_liv()
{
   if (wizardp(this_body())) { return 1; }

   return "You must be a wizard to check someone's Force status.\n";
}

mixed can_forcestatus()
{
   if (wizardp(this_body())) { return 1; }

   return "You must be a wizard to check someone's Force status.\n";
}

void create()
{
   add_rules( ({ "", "LIV", "LIV WRD" }) );
}