#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
     set_name("boots");
     set_short("Elven boots");
     set_long("Elven boots are made of a material that is very soft, yet quite durable. They feel very comfortable.");
     set_id(({"boots", "elven boots"}));
     set_ac(1);
     set_weight(7);
     set_curr_value("gold", 7+random(5));
     set_type("boots");
     set_limbs(({"left foot", "right foot"}));
}


int query_auto_load() {
    if(this_player()->query_level() > 3) return 1;
    return 0;
}
