#include <std.h>

#include <caves.h>

inherit ARMOUR;

void create() {
::create();
    set_name("old tatterd loincloth");
    set_short("%^ORANGE%^Old tatterd loincloth%^RESET%^");
    set_long("Old tatterd cloth which should probably just be thrown out.");
    set_id(({"cloth", "loincloth"}));
    set_ac(1);
    set_mass(5);
    set_value(0);
    set_type("belt");
    set_limbs(({"torso", "left leg", "right leg"}));
}

int query_auto_load() { 
    if (this_player() ->query_level() > 49) return 1;

}
