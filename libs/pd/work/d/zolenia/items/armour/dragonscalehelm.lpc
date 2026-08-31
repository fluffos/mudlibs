#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("helm");
   set_short("%^BOLD%^dr%^GREEN%^ago%^RESET%^%^GREEN%^nsca%^RESET%^%^BOLD%^le h%^GREEN%^e%^RESET%^%^GREEN%^l%^RESET%^%^BOLD%^m%^RESET%^");
   set_long("This helm appears to be constructed from dragon scales.");
   set_id(({ "helm", "dragonscale helm"}));
   set_weight(30);
   set_limbs(({"head"}));
   set_type("helmet");
    set_curr_value("gold", 120);
   set_ac(8);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}
