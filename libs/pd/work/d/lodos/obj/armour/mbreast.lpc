#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("breastplate");
   set_short("%^BOLD%^%^WHITE%^a mithr%^RESET%^il bre%^BOLD%^astplate%^RESET%^");
   set_id(({ "breastplate", "plate", "mithril breastplate", "mithril plate" }));
   set_long("An intricately forged breastplate of mithril silver. It has three "
     "sheets of metal and a thicker outer mithril covering with spikes and "
     "plates.");
   set_weight(23);
    set_curr_value("gold", 95);
   set_type("armour");
   set_limbs(({ "torso" }));
   set_ac(5);
}

int query_auto_load() { if (this_player()->query_level() >= 20) return 1; }
