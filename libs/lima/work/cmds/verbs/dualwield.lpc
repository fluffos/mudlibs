/* Do not remove the headers from this file! see /USAGE for more info. */

#include <combat_modules.h>

inherit VERB_OB;

void do_dualwield_obj(object ob)
{
   if (!try_to_acquire(ob))
      return;
   this_body()->do_wield(ob, 0, 1);
}

void do_dualwield_obs(object *obs)
{
   foreach (object ob in obs)
   {
      int force_dual_wield = 0;
      string limb;
      if (typeof(ob) == "string")
         continue;
      if (ob->is_living() || environment(ob) != this_body())
         continue;

      limb = this_body()->find_an_open_limb();
      this_body()->do_wield(ob, limb, 1);
   }
}

void do_dualwield_obj_in_str(object ob, string limb)
{
   // TBUG("do_wield_obj_in_str(" + ob + "," + limb + ")");

   if (!try_to_acquire(ob))
      return;

   limb = replace_string(limb, "hand", "arm");
   this_body()->do_wield(ob, limb, 1);
}

void do_dualwield_obj_with_str(object ob, string limb)
{
   do_dualwield_obj_in_str(ob, limb);
}

void create()
{
   add_rules(({"OBJ", "OBJ in STR", "OBJ with STR", "OBS"}));
}
