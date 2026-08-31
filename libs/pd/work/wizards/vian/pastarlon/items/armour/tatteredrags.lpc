#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("rags");
   set_short("%^BOLD%^%^BLACK%^ta%^RESET%^t%^BOLD%^%^BLACK%^t%^RESET%^e%^BOLD%^r%^BLACK%^ed r%^RESET%^a%^BLACK%^%^BOLD%^gs%^RESET%^");
   set_long("These tattered rags can't do much to protect you.");
   set_id(({ "rags", "tattered rags"}));
   set_weight(5);
   set_limbs(({"torso", "right arm", "left arm"}));
   set_type("armour");
    set_curr_value("gold", 20);
   set_ac(3);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}

