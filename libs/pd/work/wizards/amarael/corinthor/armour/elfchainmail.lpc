#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
     set_name("chainmail");
     set_short("Elven chainmail");
     set_long("A suit of well made elven chainmail, often used by the guards of the tree-city Corinthor.");
     set_id(({"chainmail", "elven chainmail"}));
     set_ac(3);
     set_weight(10);
     set_curr_value("gold", 16+random(5));
     set_type("chainmail");
     set_limbs(({"torso", "left arm", "right arm"}));
}


int query_auto_load() {
    if(this_player()->query_level() > 6) return 1;
    return 0;
}
