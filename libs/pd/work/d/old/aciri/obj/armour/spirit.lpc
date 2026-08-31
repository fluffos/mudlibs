#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("armour");
   set_short("spirit armour");
   set_long("This armour is made out of a glossy, clear material. It is as hard "
     "as metal, but appears to be glass. The spirit armour not only protects "
     "your physical body, but your spirit as well.");
   set_weight(10);
   set_id(({ "armour", "spirit armour" }));
   set_ac(7);
   set_type("armour");
   set_value(307);
   set_wear("You hear many whispering voices as you don the armour.");
   set_remove("The voices cease as you remove the armour.");
   set_limbs(({ "torso", "head" }));
}

int query_auto_load() {
   if (this_player()->query_level() >= 20) return 3;
}
