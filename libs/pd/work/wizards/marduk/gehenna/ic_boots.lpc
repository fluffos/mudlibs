#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("boots");
   set_short("Iron cast boots.");
   set_long("These boots have an iron cage molded around the boots. They "
     "look extremely durable.");
   set_limbs(({ "left foot", "right foot" }));
   set_id(({ "boots", "iron cast boots", "iron boots" }));
   set_weight(6);
   set_ac(6);
   set_type("boots");
   set_value(240);
}

int query_auto_load() {if (this_player()->query_level() >= 20) return 1;
}
