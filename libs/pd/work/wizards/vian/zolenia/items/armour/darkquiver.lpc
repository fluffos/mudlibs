#include <std.h>
inherit QUIVER;
void create() {
 ::create();
   set_name("quiver");
   set_short("%^BOLD%^%^BLACK%^da%^RESET%^r%^BOLD%^%^BLACK%^k q%^RESET%^u%^BLACK%^%^BOLD%^iver%^RESET%^");
   set_long("This quiver appears to be constructed from pure darkness.  It sucks the light from its immediate surroundings.");
   set_id(({ "quiver", "darkquiver", "dark quiver"}));
   set_weight(10);
   set_limbs(({"torso"}));
   set_arrows(12);
   set_max_arrows(24);
    set_curr_value("gold", 140);
   set_ac(1);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}
