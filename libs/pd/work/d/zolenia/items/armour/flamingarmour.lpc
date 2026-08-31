#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("armour");
   set_short("%^RED%^fl%^YELLOW%^a%^RED%^mi%^YELLOW%^ng a%^RED%^rmour%^RESET%^");
   set_long("This armour appears to be constructed from faerie fire.");
   set_id(({ "armour", "flaming armour"}));
   set_weight(70);
   set_limbs(({"torso", "right arm", "left arm"}));
   set_type("armour");
    set_curr_value("gold", 260);
   set_ac(11);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}
