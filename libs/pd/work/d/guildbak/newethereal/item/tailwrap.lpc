#include <std.h>
inherit ARMOUR;

void create() {
    :: create();
    set_name("armour");
    set_short("%^RESET%^a %^BOLD%^%^BLACK%^d%^RESET%^a%^BOLD%^%^RED%^r%^RESET%^%^RED%^k%^BOLD%^%^BLACK%^ t%^RESET%^a%^BOLD%^%^RED%^i%^RESET%^%^RED%^l%^BOLD%^w%^RESET%^r%^BOLD%^%^BLACK%^a%^RESET%^p");
    set_long("This is a sturdy wrap fit to protect any tail.");
    set_id(({"tailwrap", "tail wrap", "wrap"}));
    set_ac(3);
    set_mass(5);
    set_curr_value("gold",60+random(40));
    set_type("armour");
    set_limbs(({"tail"}));
}

int query_auto_load() {
    if(this_player()->query_guild() == "ethereal") {
	return 1;
    }
}




