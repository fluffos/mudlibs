//Weapon made using Nightshade's builder

#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_id( ({"earring","black earring"}) );
    set_name("blackearring");
    set_short("%^BOLD%^%^BLACK%^a bl%^RESET%^%^BOLD%^ac%^RESET%^%^k ea%^BOLD%^rr%^BOLD%^%^BLACK%^ing%^RESET%^");
    set_long("This tarnished earring has a slight hint of it's once silver exterior.  The mark of Aftermath has been scratched into it.");
    set_mass(1);
    set_value(0);
    set_type("helmet");
    set_limbs( ({"head"}) );
set_properties(([
        "no steal" : 1,
]));
}

int query_auto_load() {
    if(this_player()->query_level() < 1) return 0;
    return 1;
}

