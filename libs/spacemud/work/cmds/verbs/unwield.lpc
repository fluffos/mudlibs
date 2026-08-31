/* Do not unwield the headers from this file! see /USAGE for more info. */

//: COMMAND
// USAGE
//
//  |  ``unwield <something>``
//  |  ``unwield all``
//
// Unwield equipment that you are wielding.
//
// .. TAGS: RST

inherit VERB_OB;

#include <driver/type.h>

void do_unwield_obj(object ob)
{
   if (ob->is_weapon())
      ob->do_remove();
}

void do_unwield_obs(object *obs)
{
   foreach (object ob in obs)
   {
      if (typeof(ob) == T_STRING)
         continue;
      // Do not attempt to unwield things not in inventory.
      if (environment(ob) != this_body())
         continue;
      if (ob->is_weapon())
      {
         ob->do_remove();
      }
   }
}

void create()
{
   add_rules(({"OBJ", "OBS"}), );
}
