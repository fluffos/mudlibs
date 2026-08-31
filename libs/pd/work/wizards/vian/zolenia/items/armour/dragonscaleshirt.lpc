#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("shirt");
   set_short("%^BOLD%^dr%^GREEN%^ago%^RESET%^%^GREEN%^nsca%^RESET%^%^BOLD%^le s%^GREEN%^hi%^RESET%^%^GREEN%^r%^RESET%^%^BOLD%^t%^RESET%^");
   set_long("This shirt appears to be constructed from dragon scales.  It seems to be larger than the average shirt, as the material makes for a lack of flexibility.");
   set_id(({ "shirt", "dragonscale shirt"}));
   set_weight(5);
   set_limbs(({"right arm", "torso", "left arm"}));
   set_type("tunic");
    set_curr_value("gold", 200);
   set_ac(2);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}
