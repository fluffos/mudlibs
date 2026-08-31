#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
     set_name("ring");
     set_short("Ring");
     set_long("This is a plain ring made of silver, just a band with no stones or markings.");
     set_id(({"ring", "silver ring"}));
     set_ac(random(2));
     set_weight(1);
     set_curr_value("gold", 10+random(7)+random(7));
     set_type("ring");
     set_limbs(({"left hand", "right hand"}));
}


int query_auto_load() {
    if(this_player()->query_level() > 4) return 1;
    return 0;
}

