#include <std.h>
int query_auto_load() {
    if (this_player()->query_level() >= 50)
	return 1;
}
#include <amun.h>
inherit ARMOUR;                                                                    						void create() {
    ::create();                                                                        				set_name("Fire Boots");
    set("id", ({ "boots" }) );
    set("short", "%^RESET%^%^ORANGE%^F%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^r%^RED%^e %^ORANGE%^B%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^o%^RED%^t%^ORANGE%^s%^RESET%^");
    set("long", "%^RESET%^%^RED%^Unnaturally light for thick steal, these boots have a dark red color to them with a black demon on the tops of them. These boots were forged in the deep fires of hell.%^RESET%^" );
    set_type("boots");
    set_ac(7);
    set_limbs( ({ "right foot", "left foot" }) );
    set_weight(35);
    set_curr_value("gold", 250);
    set_element("fire", 10);
    set_element("ice", -10);
    set_wear("%^BOLD%^%^RED%^Your feet engulf into flames as you wear your boots.\n");
    set_remove("%^BOLD%^%^RED%^Your feet feel cooler as your remove your boots.");
}
