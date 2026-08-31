#include <std.h>
inherit WEAPON;

create() {
::create();
    set_id(({"pike","golden pike"}));
    set_name("Golden Pike");
    set_short("Golden Pike");
    set_long( "This Pike is made from gold, it was formed by " 
"the highest cleric in all the lands. It was blessed by the God of " 
"Light himself.");
    set_mass(16);
    set_curr_value("gold",90+random(40));
    set_wc(7);
    set_ac(1);
    set_type("projectile");
    set_hands(2);
}
int query_auto_load() { if (this_player()->query_level() > 30) return 1; }

