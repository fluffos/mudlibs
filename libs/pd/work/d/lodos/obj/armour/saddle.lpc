#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("saddle");
   set_short("a saddle");
   set_id(({ "saddle" }));
   set_long("Saddles are not the most comfortable of armour, but can be "
     "used on both horses and centaurs. Saddles make riding easier.");
   set_weight(4);
    set_curr_value("silver", 425);
   set_type("saddle");
   set_limbs(({ "horse torso" }));
   set_ac(3);
}

int query_auto_load() {
   if (this_player()->query_race() == "centaur") return 1;
}
