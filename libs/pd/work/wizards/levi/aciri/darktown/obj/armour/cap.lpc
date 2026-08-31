#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("cap");
   set_short("a wide-brimmed cap");
   set_long("The cap is made to block out sunlight. The wide brim "
     "has been bent for comfort.");
   set_weight(3);
   set_id(({ "cap", "wide-brimmed cap", "hat" }));
   set_ac(2);
   set_type("helmet");
   set_value(90);
   set_limbs(({ "head" }));
}

int query_auto_load() {
   if (this_player()->query_level() >= 8) return 3;
}
