#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("robes");
   set_short("long black robes");
   set_long("The long black robes come down over the body, and also has a hood "
     "that completely conceals the face. The tattered sleeves make it easy to "
     "conceal weapons.");
   set_weight(3);
   set_id(({ "robe", "robes" }));
   set_ac(3);
   set_type("robe");
   set_value(194);
   set_limbs(({ "left foot", "right foot", "torso", "left arm", "right arm" }));
}

int query_auto_load() { if (this_player()->query_level() >= 21) return 3; }
