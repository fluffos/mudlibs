#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("ring");
    set_short("Silver Ring");
    set_long("This is a plain band made of silver.");
    set_id(({"ring", "silver ring"}));
    set_ac(1);
    set_weight(1);
    set_curr_value("gold", 10+random(7));
    set_type("ring");
    set_limbs(({"left hand", "right hand"}));
}


int query_auto_load() {
    if(this_player()->query_level() > 1) return 1;
    return 0;
}
