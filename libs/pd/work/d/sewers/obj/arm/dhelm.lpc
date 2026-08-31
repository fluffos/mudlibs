#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("demon helm");
   set_short("%^BOLD%^%^BLACK%^Demon H%^RESET%^el%^BOLD%^%^BLACK%^m%^RESET%^");
   set_id(({ "armour", "helm", "helmet", "demon helm" }));
   set_long("This helmet was made specifically for the demons, with "
      "metal horn covers, sharpened to a bladed tip.  Swirling black "
      "designs cover the helm.");
   set_weight(8);
   set_curr_value("gold", 25+random(20));
   set_type("helmet");
   set_limbs(({ "head", "horns" }));
   set_ac(4);
}

int query_auto_load() { if (this_player()->query_level() >= 28) return 1; }
