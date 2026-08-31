#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("boots");
   set_short("%^BOLD%^%^BLACK%^black leather steel-toed boots%^RESET%^");
   set_long("The black leather boots have a rounded steel tip on the inside "
     "of them. The boots lace up just above calf-height with silver rings, in "
     "the style of the Knights of Aciri");
   set_weight(13);
   set_id(({ "boots", "steel toed boots", "steel-toed boots" }));
   set_ac(3);
   set_type("boots");
   set_value(204);
   set_limbs(({ "left foot", "right foot" }));
}

int query_auto_load() { if (this_player()->query_level() >= 21) return 3; }
