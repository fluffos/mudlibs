/* Do not remove the headers from this file! see /USAGE for more info. */

#include <combat_modules.h>
#include <driver/type.h>

inherit VERB_OB;

//: COMMAND
// USAGE
//
//  |  ``wield <something>``
//  |  ``wield all``
//  |  ``wield <something> in left hand``
//
// Wield something somewhere.
//
// .. TAGS: RST

void do_wield_obj(object ob)
{
   if (!try_to_acquire(ob))
      return;
   this_body()->do_wield(ob);
}

void do_wield_obs(object *obs)
{
   foreach (object ob in obs)
   {
      int force_dual_wield = 0;
      string limb;
      if (typeof(ob) == T_STRING)
         continue;
      if (ob->is_living() || environment(ob) != this_body())
         continue;

      limb = this_body()->find_an_open_limb();

      if (ob->query_must_dual_wield())
         force_dual_wield = 1;
      // TBUG("Calling do_wield(" + ob->short() + "," + limb + "," + force_dual_wield + ")");
      this_body()->do_wield(ob, limb, force_dual_wield);
   }
}

void do_wield_obj_in_str(object ob, string limb)
{
   // TBUG("do_wield_obj_in_str(" + ob + "," + limb + ")");

   if (!try_to_acquire(ob))
      return;

   if (limb == "both arms" || limb == "both hands" || limb == "both")
   {
      this_body()->do_wield(ob, 0, 1);
   }
   else
   {
      limb = replace_string(limb, "hand", "arm");
      // TBUG(limb);
      this_body()->do_wield(ob, limb);
   }
}

void do_wield_obj_with_str(object ob, string limb)
{
   do_wield_obj_in_str(ob, limb);
}

void create()
{
   add_rules(({"OBJ", "OBJ in STR", "OBJ with STR", "OBS"}));
}
