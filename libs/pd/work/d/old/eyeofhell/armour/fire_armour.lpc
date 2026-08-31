#include <std.h>
int query_auto_load() {
    if (this_player()->query_level() >= 50)
	return 1;
}
#include <amun.h>
inherit ARMOUR;                                                                    						void create() {
    ::create();                                                                        				set_name("Fire Armour");
    set("id", ({ "armour" }) );
    set("short", "%^RESET%^%^ORANGE%^F%^BOLD%^%^BLACK%^i%^RESET%^%^RED%^r%^ORANGE%^e %^RED%^A%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^m%^RED%^o%^ORANGE%^u%^RED%^r%^RESET%^");
    set("long", "%^BOLD%^%^RED%^This armour was made in the Oculus Inferi as a gift to Lucifer." );
    set_type("armour");
    set_ac(11);
    set_limbs( ({ "torso", "right arm", "left arm" }) );
    set_weight(80);
    set_curr_value("gold", 300);
    set_element("fire", 10);
    set_element("ice", -10);
    set_wear("%^BOLD%^%^RED%^Your torso lights on fire as you wear your armour.\n");
    set_remove("%^BOLD%^%^RED%^Your torso is extinguished.");
}
