#include <mudlib.h>

inherit CMD;

#define USAGE "Usage: at <living> <command>\n"

private void main(mixed *arg)
{
   object start, targ;

   if (!wizardp(this_body()))
   {
      out("This command is for wizard use only.\n");
      return;
   }

   start = environment(this_body());
   targ = environment(arg[0]);

   if (!targ)
   {
      out("Your target has no environment.\n");
      return;
   }

   this_body()->move(targ);
   this_user()->force_me(implode(arg[1], " "));

   if (start)
   {
      this_body()->move(start);
   }
}