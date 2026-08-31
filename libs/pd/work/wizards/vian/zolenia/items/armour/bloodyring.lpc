#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("ring");
   set_short("%^BOLD%^%^RED%^bl%^RESET%^o%^RED%^o%^BOLD%^dy r%^RESET%^i%^RED%^%^BOLD%^ng%^RESET%^");
   set_long("This ring appears to be constructed from crystallized blood.");
   set_id(({ "ring", "bloody ring"}));
   set_weight(5);
   set_limbs(({"right hand", "left hand"}));
   set_type("ring");
    set_curr_value("gold", 200);
   set_ac(2);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}
