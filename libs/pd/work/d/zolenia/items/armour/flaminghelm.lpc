#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("helm");
   set_short("%^RED%^fl%^YELLOW%^a%^RED%^mi%^YELLOW%^ng h%^RED%^elm%^RESET%^");
   set_long("This helm appears to be constructed from faerie fire.");
   set_id(({ "helm", "flaming helm"}));
   set_weight(30);
   set_limbs(({"head"}));
   set_type("helmet");
    set_curr_value("gold", 120);
   set_ac(8);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}
