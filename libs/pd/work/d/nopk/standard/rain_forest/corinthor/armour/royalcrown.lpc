#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
     set_name("helm");
     set_short("Royal Crown");
     set_long("The Royal Crown signifies the current king or queen of a realm. It is gold, with several precious stones embedded in it.");
     set_id(({"crown", "royal crown"}));
     set_ac(2);
     set_weight(15);
     set_curr_value("gold", 25+random(5));
     set_type("helmet");
     set_limbs(({"head"}));
}


int query_auto_load() {
    if(this_player()->query_level() > 6) return 1;
    return 0;
}
