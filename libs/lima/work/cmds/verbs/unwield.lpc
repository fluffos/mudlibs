/* Do not unwield the headers from this file! see /USAGE for more info. */

//: COMMAND
// Unwield equipment

inherit VERB_OB;

void do_unwield_obj(object ob)
{
   if (ob->is_weapon())
      ob->do_remove();
}

void do_unwield_obs(object *obs)
{
   foreach (object ob in obs)
   {
      if (typeof(ob) == "string")
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
