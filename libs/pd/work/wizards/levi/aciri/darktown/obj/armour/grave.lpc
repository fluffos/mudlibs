#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("shrouds");
   set_short("shrouds of the grave");
   set_long("Tattered and musty, these shrouds are put on a corpse when it is "
     "laid to rest.");
   set_weight(4);
   set_id(({ "shrouds", "shrouds of the grave" }));
   set_ac(3);
   set_type("robe");
   set_value(50);
   set_limbs(({ "torso" }));
}

int query_auto_load() {
   if (this_player()->query_level() >= 15) return 3;
}
