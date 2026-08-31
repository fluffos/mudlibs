#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("boots");
   set_short("%^BOLD%^%^RED%^bl%^RESET%^o%^RED%^o%^BOLD%^dy b%^RESET%^o%^RED%^%^BOLD%^ots%^RESET%^");
   set_long("These boots appear to be constructed from crystallized blood.");
   set_id(({ "boots", "bloody boots"}));
   set_weight(30);
   set_limbs(({"right foot", "left foot"}));
   set_type("boots");
    set_curr_value("gold", 140);
   set_ac(5);
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 39);
}

