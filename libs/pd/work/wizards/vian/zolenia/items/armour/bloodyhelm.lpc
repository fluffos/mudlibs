#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("helm");
   set_short("%^BOLD%^%^RED%^bl%^RESET%^o%^RED%^o%^BOLD%^dy h%^RESET%^e%^RED%^%^BOLD%^lm%^RESET%^");
   set_long("This helm appears to be constructed from crystallized blood.");
   set_id(({ "helm", "bloody helm"}));
   set_weight(30);
   set_limbs(({"head"}));
   set_type("helmet");
    set_curr_value("gold", 120);
   set_ac(8);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}
