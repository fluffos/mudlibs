#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("platemail");
   set_short("bronze platemail armour");
   set_long("Long plates of bronze make up the knight's platemail. "
     "The platemail isn't the strongest of armour, but it'll do for "
     "battle.");
   set_weight(12);
   set_id(({ "plate", "platemail", "armour", "bronze platemail" }));
   set_ac(4);
   set_type("armour");
   set_value(230);
   set_limbs(({ "torso" }));
}

int query_auto_load() { if (this_player()->query_level() >= 16) return 3; }
