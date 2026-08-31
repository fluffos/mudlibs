#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("mask");
   set_short("%^RESET%^%^BLUE%^A Sh%^BOLD%^%^BLACK%^adow Ma%^RESET%^%^BLUE%^sk%^RESET%^");
   set_long("The mask is made out of shadows, darkening any light around your "
     "face. The solid shadow actually makes fairly good armour.");
   set_weight(10);
   set_id(({ "shadow mask", "mask" }));
   set_ac(9);
   set_type("mask");
   set_value(390);
   set_limbs(({ "head" }));
}

int query_auto_load() {
   if (this_player()->query_level() >= 38) return 3;
}
