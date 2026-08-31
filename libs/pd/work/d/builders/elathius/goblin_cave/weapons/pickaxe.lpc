#include <std.h>

#include <caves.h>

inherit WEAPON;

void create() {
::create();
    set_name("pickaxe");
    set_short("%^BOLD%^%^BLACK%^Pickaxe%^RESET%^");
    set_long("A standard looking pickaxe.");
    set_id(({"pickaxe", "axe", "pick"}));
    set_mass(50);
    set_value(50);
    set_type("axe");
    set_hands(2);
    set_wc(5);
    set_ac(1);
}

int query_auto_load() { 
    if (this_player() ->query_level() > 14) return 1;

}
