#include <std.h>

#include <caves.h>

inherit ARMOUR;

void create() {
::create();
    set_name("spiked helmet");
    set_short("%^BOLD%^%^BLACK%^S%^RESET%^p%^BOLD%^%^BLACK%^ike%^RESET%^d %^BOLD%^%^BLACK%^Helmet%^RESET%^");
    set_long("A rusted old helmet with spikes running down the middle.");
    set_id(({"helm", "helmet"}));
    set_ac(5);
    set_mass(20);
    set_value(150);
    set_type("helmet");
    set_limbs(({"head"}));
}

int query_auto_load() { 
    if (this_player() ->query_level() > 49) return 1;

}
