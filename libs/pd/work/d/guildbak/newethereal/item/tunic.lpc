#include <std.h>
inherit ARMOUR;

void create() {
    :: create();
    set_name("tunic");
    set_short("%^BLACK%^%^BOLD%^d%^RESET%^%^BLUE%^e%^BOLD%^l%^BLACK%^p%^RESET%^%^BLUE%^h%^BOLD%^i%^BLACK%^a%^RESET%^%^BLUE%^n%^BOLD%^ t%^BLACK%^u%^RESET%^%^BLUE%^n%^BOLD%^i%^BLACK%^c%^RESET%^");
    set_long("This tunic is from the lost town of Delphi. Though the town is no longer there, the methods of making it, has not been lost.");
    set_id(({"tunic", "delphian tunic"}));
    set_ac(3);
    set_mass(20);
    set_curr_value("gold",60+random(40));
    set_type("tunic");
    set_limbs(({"left leg", "right leg"}));
}

int query_auto_load() {
    if(this_player()->query_guild() == "ethereal") {
	return 1;
    }
}


