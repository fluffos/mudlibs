#include <std.h>
inherit ARMOUR;

void create() {
    :: create();
    set_name("leggings");
    set_short("%^BLACK%^%^BOLD%^sp%^RESET%^i%^BOLD%^d%^BLACK%^e%^RESET%^r s%^BOLD%^i%^BLACK%^lk l%^RESET%^eg%^BOLD%^g%^RESET%^i%^BOLD%^%^BLACK%^n%^RESET%^g%^BOLD%^s%^RESET%^");
    set_long("These leggings are made with the silk taken from the bodies of female raknids, after the males eat them.  It is very strong, and will protect well.");
    set_id(({"leggings", "spidersilk leggings"}));
    set_ac(4);
    set_mass(8);
    set_curr_value("gold",800+random(40));
    set_type("leggings");
    set_limbs(({"left rear leg", "right rear leg", "left foreleg", "right foreleg"}));
}

int query_auto_load() {
    if (this_player()->query_guild() == "vorticon" && this_player()->query_level() > 35)
	return 1;
}
