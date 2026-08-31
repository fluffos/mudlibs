#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("dress");
   set_short("%^BOLD%^%^RED%^bl%^RESET%^o%^RED%^o%^BOLD%^dy d%^RESET%^r%^RED%^%^BOLD%^ess%^RESET%^");
   set_long("This dress appears to be constructed from crystallized blood.");
   set_id(({ "dress", "bloody dress"}));
   set_weight(5);
   set_limbs(({"right arm", "right leg", "left leg", "torso", "left arm"}));
   set_type("tunic");
    set_curr_value("gold", 200);
   set_ac(2);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}
