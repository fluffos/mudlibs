#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
     set_name("robe");
     set_short("%^RESET%^RED%^Mages Cloak%^RESET%^");
     set_long("This is the red cloak of an elven mage.");
     set_id(({ "cloak", "mages cloak" }));
     set_ac(1);
     set_weight(5);
     set_curr_value("gold", 7+random(5)+random(5));
     set_type("cloak");
     set_limbs(({"torso"}));
}


int query_auto_load() {
    if(this_player()->query_level() > 4) return 1;
    return 0;
}
