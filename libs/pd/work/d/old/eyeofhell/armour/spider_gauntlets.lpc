#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    						void create() {
    ::create();                                                                        				set_name("Spider Gauntlets");
    set("id", ({ "gloves", "gauntlets" }) );
    set("short", "%^RESET%^%^ORANGE%^Spider Gauntlets%^RESET%^");
    set("long", "%^RESET%^%^ORANGE%^These gauntlets were made for raknids to help them hold thier weapons.%^RESET%^" );
    set_type("gloves");
    set_ac(5);
    set_limbs( ({ "first hand", "second hand", "third hand", "fourth hand", "first arm", "second arm", "third arm", "fourth arm" }) );
    set_weight(15);
    set_curr_value("gold", 150);
}
int query_auto_load() {
    if (this_player()->query_level() >= 36)
	return 1;
}
