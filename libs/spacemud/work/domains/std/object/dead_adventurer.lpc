/* Do not remove the headers from this file! see /USAGE for more info. */

inherit CORPSE;

void setup()
{
   ::mudlib_setup("adventurer"); // Sets the ID in the corpse.
   set_proper_name(0);
   set_adj("adventurer's", "brave");
   set_objects(
       (["/domains/std/weapon/pac_sword":1,
           "/domains/std/armour/fullplate":1, "/domains/std/object/lantern":1, "/domains/std/object/backpack":1, ]));
   set_unique(1);
}

// Do not decay. STATE_D will ignore it for returning 0 here.
int state_update()
{
   return 0;
}