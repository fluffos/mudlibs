#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("boots");
   set_short("%^RED%^fl%^YELLOW%^a%^RED%^mi%^YELLOW%^ng b%^RED%^oots%^RESET%^");
   set_long("These boots appear to be constructed from faerie fire.");
   set_id(({ "boots", "flaming boots"}));
   set_weight(30);
   set_limbs(({"right foot", "left foot"}));
   set_type("boots");
    set_curr_value("gold", 140);
   set_ac(5);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}
