#include <std.h>
inherit WEAPON;

create() {
::create();
    set_id(({"pike","golden pike"}));
    set_name("Golden Pike");
    set_short("%^YELLOW%^Gol%^BOLD%^%^WHITE%^den Pi%^RESET%^%^YELLOW%^ke%^RESET%^");
    set_long( "This Pike is made from a great gold, it was formed by " 
"the highest cleric in all the lands. It was blessed by the God of " 
"Light himself.");
    set_mass(16);
    set_curr_value("gold",150+random(40));
    set_wc(7);
    set_ac(1);
    set_type("projectile");
    set_hands(2);
}
 int query_auto_load() {  return 1;}
