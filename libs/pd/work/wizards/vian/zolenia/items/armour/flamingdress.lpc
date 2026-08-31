#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("dress");
   set_short("%^RED%^fl%^YELLOW%^a%^RED%^mi%^YELLOW%^ng d%^RED%^ress%^RESET%^");
   set_long("This dress appears to be constructed from faerie fire.");
   set_id(({ "dress", "flaming dress"}));
   set_weight(5);
   set_limbs(({"right arm", "right leg", "left leg", "torso", "left arm"}));
   set_type("tunic");
    set_curr_value("gold", 200);
   set_ac(2);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}
