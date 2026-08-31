#include <std.h>
inherit ARMOUR;

void create() {
    :: create();
    set_name("bracelet");
    set_short("%^BLUE%^s%^BOLD%^a%^CYAN%^p%^WHITE%^p%^YELLOW%^h%^WHITE%^i%^CYAN%^r%^BLUE%^e%^RESET%^%^BLUE%^ b%^BOLD%^r%^CYAN%^a%^WHITE%^c%^YELLOW%^e%^WHITE%^l%^CYAN%^e%^BLUE%^t%^RESET%^");
    set_long("%^CYAN%^This is a very pristine sapphire bracelet. It is meant for the Ethereal exclusively.%^RESET%^");
    set_id(({"bracelet"}));
    set_ac(3);
    set_mass(1);
    set_curr_value("gold",60+random(40));
    set_type("bracelet");
    set_limbs(({"right hand", "left hand"}));
}

int query_auto_load() {
    if(this_player()->query_guild() == "ethereal") {
	return 1;
    }
}






