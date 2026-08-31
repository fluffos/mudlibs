/* Do not remove the headers from this file! see /USAGE for more info. */

inherit VERB_OB;

//: COMMAND
// USAGE
//
//  |  ``load <something> with <something>``
//  |  ``load <something> in <something>``
//
// Load your gun with ammo, load ammo into your shotgun, ready your crossbow with a bolt.
//
// .. TAGS: RST

void do_load_obj_with_obj(object ob1, object ob2)
{
   if (!try_to_acquire(ob1) || !try_to_acquire(ob2))
      return;
   ob1->do_load(ob2);
}

void do_load_obj_in_obj(object ob1, object ob2)
{
   if (!try_to_acquire(ob1) || !try_to_acquire(ob2))
      return;
   ob2->do_load(ob1);
}

void do_load_obs_in_obj(object *ob1, object ob2)
{
   handle_obs(ob1, ( : do_load_obj_in_obj:), ob2);
}

void do_load_obj_with_obs(object ob1, object *ob2)
{
   handle_obs(ob2, ( : do_load_obj_in_obj:), ob1);
}

void create()
{
   add_rules(({"OBJ with OBJ", "OBJ with OBS"}), ({}));
   add_rules(({"OBJ in OBJ", "OBS in OBJ"}), ({"ready"}));
}
