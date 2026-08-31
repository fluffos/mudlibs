#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("mask");
   set_short("%^BOLD%^acrili%^RESET%^te mas%^BOLD%^k%^RESET%^");
   set_long("This mask is made of a rare metal, acrilite. Acrilite shares "
     "many properties of silver with the exception of it's bright white "
     "color. The mask was made to resemble a very plain yet commanding "
     "face, neither male nor female looking.");
   set_limbs(({ "head" }));
   set_id(({ "mask", "acrilite mask" }));
   set_weight(3);
   set_ac(1);
   set_type("mask");
    set_curr_value("gold", 40);
}

int query_auto_load() {
   if (this_player()->query_level() >= 25) return 1;
}
