#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
     set_name("shirt");
     set_short("%^RESET%^BLUE%^Blue%^RESET%^ shirt");
     set_long("This is a nice shirt woven from a blue cloth, quite comfortable.");
     set_id(({"shirt", "blue shirt"}));
     set_ac(1);
     set_weight(3);
     set_curr_value("gold", 7+random(5)+random(5));
     set_type("shirt");
     set_limbs(({"torso"}));
}


int query_auto_load() {
    if(this_player()->query_level() > 4) return 1;
    return 0;
}

