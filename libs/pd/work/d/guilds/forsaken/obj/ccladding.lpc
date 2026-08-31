#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("centaur cladding");
    set_short("%^RESET%^%^ORANGE%^Centaur %^BOLD%^%^WHITE%^C%^RESET%^%^WHITE%^l%^BOLD%^add%^RESET%^%^WHITE%^i%^BOLD%^ng%^RESET%^");
    set_long("Handed down to the Forsaken guild by the Centaur tribe this set of armour gives great protection.");
    set_id(({"cladding", "centaur cladding"}));
    set_ac(1);            
    set_mass(60);
    set_curr_value("gold", 500);
    set_type("leggings");
    set_limbs(({"horse torso", "right rear leg", "right foreleg", "left rear leg", "left foreleg"}));
}

int query_auto_load() { 
    if(this_player()->query_guild() == "forsaken") return 1;

}
