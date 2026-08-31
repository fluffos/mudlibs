/* Do not remove the headers from this file! see /USAGE for more info. */

#include <spells.h>

inherit SPELL;

void setup()
{
   set_name("light");
   set_category("conjuration");
   set_cast_time(3);
   set_level(0);
   extra_reflex_cost(2);
   set_targets(TARGET_ROOM); 
   set_description("This spell creates a small light source.");
}

void do_effects(object target, object reagent)
{
   int old_light = target->query_light();

   if (old_light > 0)
   {
      this_body()->simple_action("Although the $o $v1are already lit, "
                                 "$n $vtry to light $o.",
                                 target);
      return 0;
   }

   target->adjust_light(-old_light + 1);

   if (target->query_light() > 0)
   {
      this_body()->simple_action("$N $vstare at the $o intensely for a brief moment.  Suddenly, $o is surrounded by a "
                                 "sickly light, just bright enough to see by!",
                                 target);
   }
   else
   {
      this_body()->simple_action("$N $vstare at the $o intensely for a brief moment.", target);
      write("Nothing happens.\n");
   }
}
