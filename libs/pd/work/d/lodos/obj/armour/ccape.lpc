#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("cape");
   set_short("%^RESET%^%^CYAN%^long c%^BOLD%^ya%^RESET%^%^CYAN%^n "
     "cape%^RESET%^");
   set_long("A cape of many different hues of cyan. At the bottom of "
     "the cape is a very dark, almost blue cyan. The part of the cape "
     "around the wearer's neck is a very light, close to baby blue cyan.");
   set_limbs(({ "torso", "left leg", "right leg" }));
   set_id(({ "cape", "cyan cape" }));
   set_weight(5);
   set_ac(1);
   set_type("cloak");
    set_curr_value("gold", 30);
}

int query_auto_load() {
   if (this_player()->query_level() >= 20) return 1;
}
