#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("gloves");
   set_short("%^BOLD%^%^RED%^bl%^RESET%^o%^RED%^o%^BOLD%^dy g%^RESET%^l%^RED%^%^BOLD%^oves%^RESET%^");
   set_long("These gloves appear to be constructed from crystallized blood.");
   set_id(({ "gloves", "bloody gloves"}));
   set_weight(10);
   set_limbs(({"right hand", "left hand"}));
   set_type("gloves");
    set_curr_value("gold", 90);
   set_ac(3);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}
