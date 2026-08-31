#include <std.h>
inherit ARMOUR;

void create() {
::create();
set_name("breastplate");
set_short("%^BLACK%^BOLD%^Black%^RESET%^BOLD%^ Steel Breastplate%^RESET%^");
set_long("This breastplate is made of black steel and has several large spikes protruding from the shoulders.  This breastplate was once in the possession of Treggeth.");
set_id(({"armour", "armor", "plate", "breastplate", "black steel breastplate", "steel breastplate"}));
set_ac(10);
set_weight(45);
set_curr_value("gold",90);
set_type("armour");
set_limbs(({"torso"}));
}
int query_auto_load() {
  if(this_player()->query_level() < 24) return 0;
  return 1;
}
