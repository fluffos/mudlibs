
#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("breastplate");
   set_short("a silver breastplate");
   set_long("The silver breastplate was made to fit a human, but the "
     "adjustable straps on the back could be moved to fit someone else of "
     "a different race.");
   set_weight(17);
   set_id(({ "plate", "breast", "breastplate" }));
   set_ac(6);
   set_type("armour");
   set_value(201);
   set_limbs(({ "torso" }));
}

int query_auto_load() { if (this_player()->query_level() >= 20) return 3; }
