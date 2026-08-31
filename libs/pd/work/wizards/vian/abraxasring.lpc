#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("ring");
   set_short("%^RESET%^%^BOLD%^a platinum ring with an %^GREEN%^emerald %^WHITE%^gemstone%^RESET%^");
   set_long("This ring was made specially for Abraxas from Vian!");
   set_id(({ "ring", "abraxas ring", "emerald ring"}));
   set_weight(5);
   set_limbs(({"right hand", "left hand"}));
   set_type("ring");
   set_ac(1);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 1);
}

