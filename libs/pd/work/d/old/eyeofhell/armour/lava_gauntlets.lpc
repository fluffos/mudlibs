#include <std.h>
int query_auto_load() {
    if (this_player()->query_level() >= 50)
	return 1;
}
#include <amun.h>
inherit ARMOUR;                                                                    						void create() {
    ::create();                                                                        				set_name("Lava Gauntlets");
    set("id", ({ "gloves", "gauntlets" }) );
    set("short", "%^RESET%^%^RED%^L%^ORANGE%^a%^RED%^v%^ORANGE%^a %^RED%^G%^ORANGE%^a%^RED%^untl%^ORANGE%^e%^RED%^ts%^RESET%^");
    set("long", "%^RESET%^%^ORANGE%^Made by the Lava found in Hell, these gauntlets protect the hands on the one who wears them.%^RESET%^" );
    set_type("gloves");
    set_ac(5);
    set_limbs( ({ "right hand", "left hand" }) );
    set_weight(25);
    set_curr_value("gold", 150);
    set_element("fire", 10);
    set_element("ice", -10);
    set_wear("%^BOLD%^%^RED%^The lava oozes over your hands offering them protection.\n");
    set_remove("%^BOLD%^%^RED%^Your hands return to normal.");
}
