#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("armour");
   set_short("%^BOLD%^%^RED%^bl%^RESET%^o%^RED%^o%^BOLD%^dy a%^RESET%^r%^RED%^%^BOLD%^mour%^RESET%^");
   set_long("This armour appears to be constructed from crystallized blood.");
   set_id(({ "armour", "bloody armour"}));
   set_weight(70);
   set_limbs(({"torso", "right arm", "left arm"}));
   set_type("armour");
    set_curr_value("gold", 260);
   set_ac(11);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}
