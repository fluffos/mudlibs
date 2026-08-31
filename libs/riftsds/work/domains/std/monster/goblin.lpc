/* Do not remove the headers from this file! see /USAGE for more info. */

#include <behaviour.h>

inherit ADVERSARY;
inherit BEHAVIOUR_TREE;

void setup()
{
   set_name("George");
   set_id("george", "geo");
   set_race("goblin");
   set_gender(1);
   set_proper_name("George the Goblin");
   set_in_room_desc("A small ugly goblin called George.");
   set_long("George is a small goblin, but with a strange glint in his eye.");
   set_max_health(30);
   set_wielding("/domains/std/weapon/sword");
   set_level(3);
   set_wander_area("wiz_area");
   start_behaviour();
   set_objects((["^std/consumable/peanuts":1, "^std/consumable/bandage":1]));
}

int association_for(object liv)
{
   // George really likes other goblins
   if (liv->query_race() == "goblin")
      return FRIENDLY;
   // But is suspicious about everyone else.
   return SUSPICIOUS;
}
