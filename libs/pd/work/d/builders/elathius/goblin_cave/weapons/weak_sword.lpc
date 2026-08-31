#include <std.h>

#include <caves.h>

inherit WEAPON;

void create() {
::create();
    set_name("weak sword");
    set_short("Weak sword");
    set_long("Just a weak looking sword, nothing special.");
    set_id(({"sword"}));
    set_mass(50);
    set_value(125);
    set_type("blade");
    set_hands(1);
    set_wc(15);
    set_ac(1);
}

int query_auto_load() { 
    if (this_player() ->query_level() > 34) return 1;

}
