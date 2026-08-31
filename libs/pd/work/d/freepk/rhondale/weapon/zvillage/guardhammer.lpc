// Amarael

#include <std.h>
inherit WEAPON;
 
void create() {
::create();
    set_id(({"hammer", "warhammer"}));
    set_name("warhammer");
    set_short("Steel Warhammer");
    set_long("This hammer is made of forged steel and is used by Rhondale guardsmen to keep the village safe.");
    set_mass(20);
    set_curr_value("gold", 76);
    set_wc(10);
    set_type("blunt");
    set_hands(1);
}

int query_auto_load() {
    if (this_player()->query_level() > 29) return 1; 
}
