#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("horseshoes");
   set_short("an old pair of horseshoes");
   set_id(({ "shoes", "horseshoes" }));
   set_long("The old steel horseshoes can be worn by horses and centaurs "
      "to protect their feet.");
   set_weight(4);
    set_curr_value("gold", 15);
   set_type("boots");
   set_limbs(({ "right rear hoof", "left rear hoof", "right fore hoof",
      "left fore hoof" }));
   set_ac(2);
}

int query_auto_load() {
  if (this_player()->query_race() == "centaur") return 1;
}
