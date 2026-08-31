#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("gloves");
   set_short("%^RED%^fl%^YELLOW%^a%^RED%^mi%^YELLOW%^ng g%^RED%^loves%^RESET%^");
   set_long("These gloves appear to be constructed from faerie fire.");
   set_id(({ "gloves", "flaming gloves"}));
   set_weight(10);
   set_limbs(({"right hand", "left hand"}));
   set_type("gloves");
    set_curr_value("gold", 90);
   set_ac(3);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}
