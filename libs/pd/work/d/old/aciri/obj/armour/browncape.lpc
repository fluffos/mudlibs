#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("gloves");
   set_short("%^ORANGE%^a b%^BOLD%^%^BLACK%^row%^RESET%^%^ORANGE%^n c%^BOLD%^%^BLACK%^ap%^RESET%^%^ORANGE%^e%^RESET%^");
   set_long("The long, thin brown cape blows around in the wind. It hangs almost "
     "to your feet. The cloak is pretty thick, and slick enough to work as a "
     "windbreaker.");
   set_weight(6);
   set_id(({ "brown cape", "cape" }));
   set_ac(5);
   set_type("cape");
   set_value(252);
   set_limbs(({ "torso" }));
}

int query_auto_load() {
   if (this_player()->query_level() >= 20) return 3;
}
