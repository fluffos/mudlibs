#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("shirt");
   set_short("%^RED%^fl%^YELLOW%^a%^RED%^mi%^YELLOW%^ng s%^RED%^hirt%^RESET%^");
   set_long("This shirt appears to be constructed from faerie fire.");
   set_id(({ "shirt", "flaming shirt"}));
   set_weight(5);
   set_limbs(({"right arm", "torso", "left arm"}));
   set_type("tunic");
    set_curr_value("gold", 200);
   set_ac(2);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 29);
}

